
#include "UNumberListManager.h"
#include "DataTypes/GameLevelConfigs.h"
#include "UListManager.h"
#include "RuleEngine/FRuleBO.h"
#include "GameLibrary/Headers/UArrayHelper.h"
#include "BullCowGame.h"

#include "UObject/Object.h"

#include <bitset>
#include <cstdlib>
#include <time.h>


//  0123
//  1456
//  0123

/* --------------
TODO: Need to figure out logic to recommend easy and known numbers 
for easy difficulty mode 
----------------*/

UNumberListManager::UNumberListManager(const FObjectInitializer& ObjectInitializer)
  : Super(ObjectInitializer)
{
    ArraySize = 0;
    CurrentIndex = 0;
    srand(time(NULL));
}

// retireve from number array holding starting index for ArrayIndex
int32 UNumberListManager::GetCurrentIndex()
{
    if (CurrentIndex < ArraySize) return IndexArray[CurrentIndex];
    return -1;
}

int32 UNumberListManager::GetNextIndex() 
{
    ++CurrentIndex;
    return GetCurrentIndex();
}

//------------------
//  Implementation of UListManager Interface
//------------------

void UNumberListManager::Init_Implementation(const FRuleBO& Rules, const FGameLevelConfigs& GameLevelConfigs)
{
    // TODO: Write function
}

void UNumberListManager::ResetList_Implementation()
{
    IndexArray.Reset(ArraySize);
    NumberArray.Reset(ArraySize);
}

int32 UNumberListManager::GenerateNumber(int32 *index, int32 seed, int32 Length, int32 recurrentNumber)
{  
    FString NumberString;
    //
    // Write logic to generate number string
    //
    srand(seed);
    std::bitset<10> isDigitUsed;
    int32 recurrentNumberPosition = rand() % Length;
    int32 newRecurrentNumberPosition = rand() % Length;
    int32 newRecurrentNumber = -1;
    if (recurrentNumber > -1) isDigitUsed[recurrentNumber] = true;
    for (int32 i=0; i < Length; i++)
    {

        if (recurrentNumberPosition == i && NumberList.IsValidIndex(recurrentNumber))
        {
            NumberString.AppendChar(NumberList[recurrentNumber]);
            if (i==newRecurrentNumberPosition) newRecurrentNumber = recurrentNumber;
            continue;
        }

        int32 number = rand() % 10;
        if (isDigitUsed[number])
        {
            --i;
            continue;
        } 
        if (i==newRecurrentNumberPosition) newRecurrentNumber = number;
        
        NumberString.AppendChar(NumberList[number]);
        isDigitUsed[number] = true;
    }
    // Add new number to NumberArray
    // if new number exist already in NumberArray. AddUnique() will return old index instead new index
    int32 newIndex = NumberArray.AddUnique(NumberString);
    if (newIndex != *index)         
    {                               
        UE_LOG(GameLog,Display,
        TEXT("Failed to add new number, NewIndex: %i, currentIndex: %i"),
        newIndex,*index);           // if no new number string added 
        --(*index);                 // decrement index to noify failed to add new number
        return recurrentNumber;     // reuse recurrent number for next iteration
    }
    
    AddItem(newIndex);
    
    // TCHAR tempRecurrentChar = numberChars[newRecurrentNumberPosition];
    // return NumberList.Find(numberChars[newRecurrentNumberPosition]);
    return newRecurrentNumber;
}   


void UNumberListManager::AddItem(const int32 item)
{
    IndexArray.AddUnique(item);
    ArraySize = IndexArray.Num();
}

void UNumberListManager::ShuffleArray_Implementation(const int32 seed) 
{
    CurrentIndex = 0;
    if (seed == -1) return;
    UArrayHelper::ShuffleList<int32>(IndexArray, ArraySize, seed);
}

int32 UNumberListManager::GetArraySize_Implementation() // TODO: maybe DELETE
{
    return ArraySize;
}

FString UNumberListManager::GetCurrentItem_Implementation()
{
    if (NumberArray.IsValidIndex(GetCurrentIndex())) return NumberArray[GetCurrentIndex()];
    return TEXT("");
}

FString UNumberListManager::GetNextItem_Implementation()
{
    if(GetNextIndex() > -1) return GetCurrentItem();
    return TEXT("");
}