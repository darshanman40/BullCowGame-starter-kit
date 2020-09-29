#pragma once

#include "CoreMinimal.h"
#include "UListManager.h"
#include "UObject/Object.h"
#include "UWordListManager.generated.h"

UCLASS(BlueprintType)
class BULLCOWGAME_API UWordListManager : public UObject, public IListManagerInterface
{
    GENERATED_BODY()


    private:
    TArray<int32> IndexArray;
    int32 ArraySize;
    int32 CurrentIndex;
    FWordGameModeRules Wgmr;

    int32 MinLength, MaxLength;


    // private:

    UPROPERTY()
    TArray<FString> CodesList;

    UPROPERTY()
    int32 CodesListSize;

    UPROPERTY()
    TArray<int32> UncommonWordIndices;

    UPROPERTY()
    int32 UncommonCodesListSize;

    UPROPERTY()
    TArray<FString> RareCodesList;

    UPROPERTY()
    int32 RareCodesListSize;

    // Local helper functions
    void LoadDefaultValues();
    int32 GetCurrentIndex();
    int32 GetNextIndex();

    public:

    UWordListManager(const FObjectInitializer& ObjectInitializer);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "BullCowGame")
    void Init(const FRuleBO& Rules, const FGameLevelConfigs& GameLevelConfigs);
    virtual void Init_Implementation(const FRuleBO& Rules, const FGameLevelConfigs& GameLevelConfigs) override;

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "BullCowGame")
    void ResetList();
    virtual void ResetList_Implementation() override;

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "BullCowGame")
    void ShuffleArray(const int32 seed);
    virtual void ShuffleArray_Implementation(const int32 seed) override;

    // New function for FString
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "BullCowGame")
    FString GetCurrentItem();
    virtual FString GetCurrentItem_Implementation() override;

    // New function for FString
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "BullCowGame")
    FString GetNextItem();
    virtual FString GetNextItem_Implementation() override;

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "BullCowGame")
    int32 GetArraySize();
    virtual int32 GetArraySize_Implementation() override;
        
    
};