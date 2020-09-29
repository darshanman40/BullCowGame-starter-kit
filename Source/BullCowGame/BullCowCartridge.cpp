// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
#include "Containers/UnrealString.h"
#include "BullCowGame.h"
#include "UWordListManager.h"
#include "UNumberListManager.h"
#include "DataTypes/GameLevelConfigs.h"
#include "BullCowGameInstance.h"

#include "Data/Difficulty.h"

// Static Libraries
#include "GameLibrary/Headers/UStringHelper.h"
#include "GameLibrary/Headers/UHealthHelper.h"
#include "GameLibrary/Headers/UArrayHelper.h"


#include <bitset>
#include <cctype>
#include <string>
#include <cstdlib>
#include <time.h>



void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    srand(time(NULL));
    TEST_hiddenWordCount = 0;

    UBullCowGameInstance* GameInstance = Cast<UBullCowGameInstance>(GetWorld()->GetGameInstance());
    if(GameInstance) // Pass the game level info through menu page
    {
        GLConfigs = GameInstance->GameLevelConfigs;
        RuleBO = GameInstance->RuleBo;
        WGMRules = RuleBO.GetFWordGameModeRules();
    }

    if (!GLConfigs.IsSet) 
    {
        UE_LOG(GameLog,Warning,TEXT("GLConfigs is not set, loading test object "));
        GLConfigs = TEST_GL_CONFIG_1; 
    }

    if (!WGMRules.IsSet)
    {
        UE_LOG(GameLog,Warning,TEXT("WGMRules is not set, loading test object "));
        WGMRules = TEST_WGMR_1;
    }

    UE_LOG(GameLog,Display,TEXT("Instantiating ListManagerObject"));
    SetGameMode(GLConfigs);    
    HiddenWord = IListManagerInterface::Execute_GetCurrentItem(ListManagerObject);
    SetupGame(GLConfigs);
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    if (bGameOver)
    {
        ClearScreen();
        ShuffleArray(false);
        SetupGame(GLConfigs);
    }
    else
    {
        ProcessGuess(Input.ToLower());
    }

}

// Manage the list of words or number depending on game mode (eGameType)
void UBullCowCartridge::SetGameMode(const FGameLevelConfigs& GameLevelConfigs)
{
    TScriptInterface<IListManagerInterface> ListM;
    switch (GameLevelConfigs.GameType)
    {
        // TODO: Implement case for number type game  ( EGameType::NumberGame )

        case EGameType::WordGame:
        {
            UE_LOG(GameLog,Display,TEXT("Running Word Game Mode"));
            UWordListManager* WordListM = NewObject<UWordListManager>(this,TEXT("WordListM"));
            ListM.SetObject(WordListM);
            ListM.SetInterface(Cast<IListManagerInterface>(WordListM));
            ListManagerObject = ListM.GetObject();
            IListManagerInterface::Execute_Init(ListManagerObject, WGMRules,GameLevelConfigs);
            ShuffleArray(false);
            break;
        }
    }
}

void UBullCowCartridge::ShuffleArray(bool isSkipShuffle)
{
    int32 seed = -1;
     if (!isSkipShuffle) seed = rand();  // skip shuffle, only reset index
    IListManagerInterface::Execute_ShuffleArray(ListManagerObject,seed);
    UE_LOG(GameLog,Display,TEXT("Total Words found: %i "), IListManagerInterface::Execute_GetArraySize(ListManagerObject));  
}

void UBullCowCartridge::SetupGame(const FGameLevelConfigs& GameLevelConfigs)
{

    bGameOver = false;
  
    if (HiddenWord == "") // if ran out of words
    {
        ShuffleArray(false); // shuffle array and reset the index
        HiddenWord = IListManagerInterface::Execute_GetCurrentItem(ListManagerObject);
    }

    TEST_hiddenWordCount++;
    UE_LOG(GameLog,Display,TEXT("Level: %i"),TEST_hiddenWordCount);

    // HiddenWord = TEXT("HEAT");           //TODO: Short TEST

    Lives = CurrentLives = HiddenWord.Len();

    PrintLine(TEXT("Welcome to Bull Cow Game"));
    PrintLine(TEXT("Press Enter to continue..."));
    PrintLine(FString::Printf(TEXT("Guess the %i letter word..."), Lives));

    UE_LOG(GameLog,Display,TEXT("The Hidden Word: %s, total lives: %i "), *HiddenWord, CurrentLives);
    
}

void UBullCowCartridge::ProcessGuess(const FString& Guess)
{
    if (Guess == HiddenWord)
    {
        PrintLine(TEXT("You have Won!"));
        EndGame();
        HiddenWord = IListManagerInterface::Execute_GetNextItem(ListManagerObject);
        return;
    }

    //Check the guess without removing lives
    if (Guess.Len() < 1)
    {
        PrintLine(TEXT("Guess is empty, please enter the guess"));
        return;
    }

    if (!UStringHelper::IsIsogram(*Guess))
    {
        PrintLine(TEXT("Your guess is not an isogram, please try again"));
        return;
    }

    if (Guess.Len() != HiddenWord.Len())
    {
        PrintLine(FString::Printf(TEXT("Hidden character is %i long, please try again!"),HiddenWord.Len()));
        return;
    }

    //Remove Lives if guess meet the requirements to loose life
    bool IsDead = UHealthHelper::DecrementHealthByOne(CurrentLives);
    if ( IsDead )
    {
        PrintLine(FString::Printf(TEXT("Game Over!")));
        PrintLine(FString::Printf(TEXT("Hidden Word was %s"),*HiddenWord));
        ShuffleArray(true); // only resetting index
        EndGame();        
    }
    else
    {
        GenerateHint(HiddenWord, Guess);
        PrintLine(FString::Printf(TEXT("Wrong guess, %i lives left"),CurrentLives));
        PrintLine(FString::Printf(TEXT("Please try again!")));
    }

}

// For example, if the secret word is HEAT,
// a guess of COIN would result in "0 Bulls, 0 Cows" (all of the guessed letters are wrong);
// a guess of EATS would result in "0 Bulls, 3 Cows" (since E, A, T are all present, but not in the guessed positions)
// a guess of TEAL would result in "2 Bulls, 1 Cow" (since E and A are in the right positions,
//      while T is in the wrong position).
// The game would continue until someone scores "4 Bulls" for guessing HEAT exactly.

void UBullCowCartridge::GenerateHint(const FString& Answer, const FString& Guess )
{
    int32 Cows, Bulls;
    Cows = Bulls = 0;
    int32 INDEX; // to return back index of found character

    for (int32 i = 0; i < Guess.Len(); i++)
    {
        bool found = Answer.FindChar(Guess[i], INDEX);

        // if character doesnt exist in Answer, neither bull nor cow
        // if character exist in Answer AND at same position then bulls + 1
        // if character exist in Answer but NOT at same position then cows + 1
        if (found)
        {
            if (INDEX == i ) Bulls++;
            else Cows++;
        }
    }

    PrintLine(FString::Printf(TEXT("Bulls: %i , Cows: %i"), Bulls, Cows));
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Press enter to play again."));
}
