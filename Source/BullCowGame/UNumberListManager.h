#pragma once

#include "CoreMinimal.h"
#include "UListManager.h"
#include "RuleEngine/FRuleBO.h"

#include "UObject/Object.h"
#include "UNumberListManager.generated.h"

UCLASS(BlueprintType)
class BULLCOWGAME_API UNumberListManager : public UObject, public IListManagerInterface
{
    GENERATED_BODY()

    private:
    TArray<int32> IndexArray;
    TArray<FString> NumberArray;
    int32 ArraySize, TotalNumbers;
    int32 CurrentIndex, NumberLength;
    const TArray<TCHAR> NumberList = 
    {
        '0','1','2','3','4','5','6','7','8','9'
    };

    const int32 IOFFSET_FOUR = 4;
    const int32 IOFFSET_SIX = 6;


    int32 GenerateNumber(int32 *index, int32 seed, int32 Length, int32 recurrentNumber = -1);
    void AddItem(const int32 item); 
    int32 GetCurrentIndex();
    int32 GetNextIndex(); 

    public:
    
    UNumberListManager(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "BullCowGame")
    void Init(const FRuleBO& Rules,const FGameLevelConfigs& GameLevelConfigs);
    virtual void Init_Implementation(const FRuleBO& Rules, const FGameLevelConfigs& GameLevelConfigs) override; 

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "BullCowGame")
    void ResetList();
    virtual void ResetList_Implementation() override;

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "BullCowGame")
    void ShuffleArray(const int32 seed);
    virtual void ShuffleArray_Implementation(const int32 seed) override;

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "BullCowGame")
    int32 GetArraySize();
    virtual int32 GetArraySize_Implementation() override;
    

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "BullCowGame")
    FString GetNextItem();
    virtual FString GetNextItem_Implementation() override;


    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "BullCowGame")
    FString GetCurrentItem();
    virtual FString GetCurrentItem_Implementation() override;    
    
};