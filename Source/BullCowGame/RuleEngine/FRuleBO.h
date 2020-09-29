#pragma once
#include "CoreMinimal.h"
#include "RuleEngine/FWordGameModeRules.h"
#include "FRuleBO.generated.h"


USTRUCT(BlueprintType)
struct BULLCOWGAME_API FRuleBO 
{
    GENERATED_BODY()
    
    public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "BullCowGame")
	FWordGameModeRules WGMRules;

    FRuleBO(){};
    FRuleBO(FWordGameModeRules InWGMRules){ WGMRules = InWGMRules; };

    void SetWordGameModeRules( 
        const int32 InputCommonWordOffset, 
        const int32 InputCommonWordsThreshold,
        const int32 InputUncommonWordOffset,
        const int32 InputUncommonWordsThreshold,
        const int32 InputRareWordsThreshold
    );

    void SetWordGameModeRules(const FWordGameModeRules InWGMRules);

    const FWordGameModeRules GetFWordGameModeRules();

};

/* 
HealthRules
---------------

    float MinHealth
    float MaxHealth
    Buff buff
    Debuff debuff


*/