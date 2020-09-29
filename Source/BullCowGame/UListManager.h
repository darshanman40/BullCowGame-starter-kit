#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "DataTypes/GameLevelConfigs.h"
#include "RuleEngine/FRuleBO.h"
#include "UListManager.generated.h"


UINTERFACE(BlueprintType)
class BULLCOWGAME_API UListManagerInterface : public UInterface
{
    GENERATED_BODY()
};

class BULLCOWGAME_API IListManagerInterface
{

    GENERATED_BODY()

    protected:
    

    public:

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "BullCowGame")
    void Init(const FRuleBO& Rules, const FGameLevelConfigs& GameLevelConfigs);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "BullCowGame")
    void ResetList();

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "BullCowGame")
    void AddItem(const int32 item);

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "BullCowGame")
    void ShuffleArray(const int32 seed);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "BullCowGame")
    int32 GetArraySize();

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "BullCowGame")
    FString GetNextItem();

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "BullCowGame")
    FString GetCurrentItem();

};