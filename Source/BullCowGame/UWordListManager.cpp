
#include "UWordListManager.h"
#include "UListManager.h"
#include "BullCowGame.h"
#include "DataTypes/GameLevelConfigs.h"
#include "RuleEngine/FRuleBO.h"
#include "Data/DAO/HiddenCodesDAO.h"

#include "UObject/Object.h"
#include "GameLibrary/Headers/UArrayHelper.h"
#include "GameLibrary/Headers/UStringHelper.h"


UWordListManager::UWordListManager(const FObjectInitializer& ObjectInitializer)
  : Super(ObjectInitializer)
{
    ArraySize = 0;
    CurrentIndex = 0;
}

void UWordListManager::LoadDefaultValues()
{
    ArraySize = 0;
    if (Wgmr.CommonWordsThreshold > 0) ArraySize += Wgmr.CommonWordsThreshold;
    if (Wgmr.UncommonWordsThreshold > 0) ArraySize += Wgmr.UncommonWordsThreshold;
    if (Wgmr.RareWordsThreshold > 0) ArraySize += Wgmr.RareWordsThreshold;

    IndexArray.Init(-1, ArraySize);
    int32 skippedIndex = 0; // adding 1 everytime uncommon word has found in an index
    int32 wordIndex = 0; // index to traverse through codes list
    int32 *tempUncommonIndexPtr = UncommonWordIndices.GetData() + Wgmr.UncommonWordOffset;
    int32 traverseLimit =  Wgmr.CommonWordsThreshold; // this will increment per index type (common words, uncommon words then rare words limit)

    // ordered Values for common codes
    for (; wordIndex < traverseLimit; wordIndex++)
    {
        int32 tempNewIndexValue = wordIndex + skippedIndex + Wgmr.CommonWordOffset;
        if (tempNewIndexValue == *tempUncommonIndexPtr)
        {  
            *tempUncommonIndexPtr++;
            skippedIndex++;
            --wordIndex;  
            continue;
        }
        IndexArray[wordIndex] = tempNewIndexValue;
    }

    traverseLimit += Wgmr.UncommonWordsThreshold; // apending uncommon words limit
    tempUncommonIndexPtr = UncommonWordIndices.GetData() + Wgmr.UncommonWordOffset; // resetting uncommon index pointer
    for (; wordIndex < traverseLimit; wordIndex++)
    {
        IndexArray[wordIndex] = *tempUncommonIndexPtr;
        *tempUncommonIndexPtr++;
    }

    traverseLimit += Wgmr.RareWordsThreshold; // apendning uncommon words limit
    for (int32 rareWordIndex = 0; wordIndex < traverseLimit; wordIndex++, rareWordIndex++)
    {
        IndexArray[wordIndex] = 
            Wgmr.CommonWordsThreshold +
            Wgmr.UncommonWordsThreshold +    // using wordIndex as offset so function 
            rareWordIndex;                  // can switch array from wordlist to rareWordList
    }

    // Verify the IndexArray is filled with valid indices
    for (int32 i=0; i< ArraySize; i++)
    {
        if (IndexArray[i] == -1 || IndexArray[i] >= ArraySize ) UE_LOG(GameLog,Error,TEXT("Invalid Index found in IndexArray at index: %i, value: %i"),i,IndexArray[i]);
    }
}

int32 UWordListManager::GetCurrentIndex()
{
    if (CurrentIndex < ArraySize) return IndexArray[CurrentIndex];
    return -1;
}

int32 UWordListManager::GetNextIndex() 
{
    ++CurrentIndex;
    return GetCurrentIndex();
}

//--------------------
//  Implementation of UListManager interface
//--------------------

void UWordListManager::Init_Implementation(const FRuleBO& Rules, const FGameLevelConfigs& GameLevelConfigs)
{

    FHiddenCodesDAO HiddenCodesDAO = FHiddenCodesDAO(GameLevelConfigs);
    CodesList =             HiddenCodesDAO.GetCodesList();
    CodesListSize =         HiddenCodesDAO.GetCodesListSize();
    UncommonWordIndices =   HiddenCodesDAO.GetUncommonWordIndices();
    UncommonCodesListSize = HiddenCodesDAO.GetUncommonCodesListSize();
    RareCodesList =         HiddenCodesDAO.GetRareCodesList();
    RareCodesListSize =     HiddenCodesDAO.GetRareCodesListSize();
    Wgmr = Rules.WGMRules;
    
    LoadDefaultValues();
}


void UWordListManager::ResetList_Implementation()
{
    IndexArray.Init(-1, ArraySize);
}


void UWordListManager::ShuffleArray_Implementation(int32 seed)
{
    CurrentIndex = 0;
    if (seed == -1) return; // skipping the shuffle jus in case testing the order of list

    int32 wordIndex = 0; // resetting wordindex to traverse through and shuffle
    UArrayHelper::ShuffleList<int32>(IndexArray, wordIndex, Wgmr.CommonWordsThreshold, seed); // common words
    
    if (Wgmr.UncommonWordsThreshold > 0)
    {
        wordIndex += Wgmr.CommonWordsThreshold;
        UArrayHelper::ShuffleList<int32>(IndexArray, wordIndex, Wgmr.UncommonWordsThreshold, seed); // uncommon words
    }

    if (Wgmr.RareWordsThreshold > 0)
    {
        wordIndex += Wgmr.UncommonWordsThreshold;
        UArrayHelper::ShuffleList<int32>(IndexArray, wordIndex, Wgmr.RareWordsThreshold, seed);
    }
}

int32 UWordListManager::GetArraySize_Implementation()
{
    return ArraySize;
}

FString UWordListManager::GetCurrentItem_Implementation() 
{
    if (CodesList.IsValidIndex(GetCurrentIndex())) return CodesList[GetCurrentIndex()];
    if (RareCodesList.IsValidIndex(GetCurrentIndex()-CodesListSize)) return RareCodesList[GetCurrentIndex()-CodesListSize];
    return TEXT("");
}

FString UWordListManager::GetNextItem_Implementation() 
{
    if(GetNextIndex() > -1) return GetCurrentItem();
    return TEXT("");
}