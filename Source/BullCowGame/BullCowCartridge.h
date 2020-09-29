// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Console/Cartridge.h"
#include "BullCowGame.h"
#include "UListManager.h"
#include "BullCowCartridge.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BULLCOWGAME_API UBullCowCartridge : public UCartridge
{
	GENERATED_BODY()

	public:

	virtual void BeginPlay() override;
	virtual void OnInput(const FString& Input) override;

	void SetupGame(const FGameLevelConfigs& GameLevelConfigs);
	void SetGameMode(const FGameLevelConfigs& GameLevelConfigs);
	void LoadWords(const EGameType& eGameType);
	void ShuffleArray(bool isSkipShuffle);
	void ProcessGuess(const FString& Guess);
	void GenerateHint(const FString& Answer, const FString& Guess);
	void EndGame();


	private:
	FString HiddenWord;
	int32 Lives, CurrentLives;
	bool bGameOver;

	FWordGameModeRules WGMRules;
	FGameLevelConfigs GLConfigs;
	FRuleBO RuleBO;
	
	

	// TEST Constants ----------
	const FWordGameModeRules TEST_WGMR_1 = FWordGameModeRules(0,3,0,2,0,true);
	const FWordGameModeRules TEST_WGMR_2 = FWordGameModeRules(5,3,2,2,0,true);
	const FWordGameModeRules TEST_WGMR_FULL = FWordGameModeRules(0,10,0,4,10,true);
	const FGameLevelConfigs TEST_GL_CONFIG_1 = FGameLevelConfigs(EGameMode::Training,EGameType::WordGame,EDifficulty::Test,true);
	const FRuleBO TEST_RULE_BO_1 = FRuleBO(TEST_WGMR_1);

	// const FWordGameModeRules LETTER_6_TO_7_WGMR_1 = FWordGameModeRules(0,50,0,20,0,true);
	// const FWordGameModeRules LETTER_6_TO_7_WGMR_2 = FWordGameModeRules(70,50,20,20,0,true);
	// const FWordGameModeRules LETTER_6_TO_7_WGMR_FULL = FWordGameModeRules(0,100,0,40,10,true);

	// const FWordGameModeRules LETTER_8_TO_11_WGMR_1 = FWordGameModeRules(0,50,0,20,0,true);
	// const FWordGameModeRules LETTER_8_TO_11_WGMR_2 = FWordGameModeRules(70,50,20,20,0,true);
	// const FWordGameModeRules LETTER_8_TO_11_WGMR_FULL = FWordGameModeRules(0,100,0,40,10,true);

	// const FWordGameModeRules LETTER_12_TO_17_WGMR_1 = FWordGameModeRules(0,0,50,0,0,true);
	// const FWordGameModeRules LETTER_12_TO_17_WGMR_2 = FWordGameModeRules(5,3,2,2,0,true);
	// const FWordGameModeRules LETTER_12_TO_17_WGMR_FULL = FWordGameModeRules(0,10,0,4,10,true);
	//-------------
	
	UPROPERTY(Category=Default, EditInstanceOnly)
	UObject* ListManagerObject;
	
	int32 TEST_hiddenWordCount;

};

/*

Psudo Code

- start game with welcome screen
- count length of word and save it as Lives and CurrentLives

// Check the guess (no life deduction)
- Check if guess is isogram
- if no, prompt to guess again
- Check the right number of characters
- if no, prompt to guess again

// Removing life

Check if current lives > 0
- If yes, guess again
- Show CurrentLives left
- Check of guess is correct
- if no, deduct 1 life from CurrentLives


*/
