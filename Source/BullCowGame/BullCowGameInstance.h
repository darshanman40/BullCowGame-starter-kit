#pragma once

#include "CoreMinimal.h"
#include "Engine/GameEngine.h"

#include "RuleEngine/FRuleBO.h"
#include "DataTypes/GameLevelConfigs.h"

#include "BullCowGameInstance.generated.h"

UCLASS()
class UBullCowGameInstance : public UGameInstance
{
    GENERATED_BODY()
    
    public:
    UBullCowGameInstance(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(EditAnywhere,BlueprintReadWrite,Category=BullCowGame)
    FRuleBO RuleBo;
    
    UPROPERTY(EditAnywhere,BlueprintReadWrite,Category=BullCowGame)
    FGameLevelConfigs GameLevelConfigs;


};