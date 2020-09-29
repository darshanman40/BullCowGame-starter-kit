#include "HiddenCodesDAO.h"
#include "DataTypes/GameLevelConfigs.h"

#include "Data/Letter6To7WordsData.h"
#include "Data/Letter8To11WordsData.h"
#include "Data/Letter12To17WordsData.h"


void FHiddenCodesDAO::SetupDataForWordGame()
{
    switch (GameLevelConfigs.Difficulty)
    {
    
        case EDifficulty::Easy:
            CurrentData = FHiddenCodesDO(LETTER_6_TO_7_WORDS, LETTER_6_TO_7_WORDS_SIZE, 
                LETTER_6_TO_7_UNCOMMON_WORDS_INDICES, LETTER_6_TO_7_UNCOMMON_WORDS_INDICES_SIZE,
                LETTER_6_TO_7_RARE_WORDS,LETTER_6_TO_7_RARE_WORDS_SIZE);
            break;
        case EDifficulty::Medium:
            CurrentData = FHiddenCodesDO(LETTER_8_TO_11_WORDS,LETTER_8_TO_11_WORDS_SIZE, 
                LETTER_8_TO_11_UNCOMMON_WORDS_INDICES, LETTER_8_TO_11_UNCOMMON_WORDS_INDICES_SIZE,
                LETTER_8_TO_11_RARE_WORDS,LETTER_8_TO_11_RARE_WORDS_SIZE);
            break;
        case EDifficulty::Hard:
            CurrentData = FHiddenCodesDO(LETTER_12_TO_17_WORDS,LETTER_12_TO_17_WORDS_SIZE, 
                LETTER_12_TO_17_UNCOMMON_WORDS_INDICES, LETTER_12_TO_17_UNCOMMON_WORDS_INDICES_SIZE,
                LETTER_12_TO_17_RARE_WORDS,LETTER_12_TO_17_RARE_WORDS_SIZE);
            break;
        default:
            CurrentData = FHiddenCodesDO(TEST_LETTER_6_TO_7_WORDS, TEST_LETTER_6_TO_7_WORDS_SIZE, 
                TEST_LETTER_6_TO_7_UNCOMMON_WORDS_INDICES, TEST_LETTER_6_TO_7_UNCOMMON_WORDS_INDICES_SIZE,
                TEST_LETTER_6_TO_7_RARE_WORDS, TEST_LETTER_6_TO_7_RARE_WORDS_SIZE);
            break;
    }
}

// TODO: implement Number game logic
void FHiddenCodesDAO::SetupDataForNumberGame()
{

}

//
//  Getters
//
TArray<FString> FHiddenCodesDAO::GetCodesList()
{
    return CurrentData.GetCodesList();
}

int32 FHiddenCodesDAO::GetCodesListSize()
{
    return CurrentData.GetCodesListSize();
}

TArray<int32> FHiddenCodesDAO::GetUncommonWordIndices()
{
    return CurrentData.GetUncommonWordIndices();
}

int32 FHiddenCodesDAO::GetUncommonCodesListSize()
{
    return CurrentData.GetUncommonCodesListSize();
}
    
TArray<FString> FHiddenCodesDAO::GetRareCodesList()
{
    return CurrentData.GetRareCodesList();
}
    
int32 FHiddenCodesDAO::GetRareCodesListSize()
{
    return CurrentData.GetRareCodesListSize();
}
