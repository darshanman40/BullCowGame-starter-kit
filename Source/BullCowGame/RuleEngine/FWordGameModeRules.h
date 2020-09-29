#pragma once
#include "CoreMinimal.h"
#include "FWordGameModeRules.generated.h"

USTRUCT(BlueprintType)
struct BULLCOWGAME_API FWordGameModeRules
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "BullCowGame")
    int32 CommonWordOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "BullCowGame")
    int32 CommonWordsThreshold;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "BullCowGame")
    int32 UncommonWordOffset;    

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "BullCowGame")
    int32 UncommonWordsThreshold;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "BullCowGame")
    int32 RareWordsThreshold;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "BullCowGame")
    bool IsSet;

    FWordGameModeRules():
        CommonWordOffset(0), 
        CommonWordsThreshold(0),
        UncommonWordOffset(0),
        UncommonWordsThreshold(0),
        RareWordsThreshold(0),
        IsSet(false) 
    { };

    FWordGameModeRules(const int32 InCommonWordOffset, const int32 InCommonWordsThreshold, const int32 InUncommonWordOffset, const int32 InUncommonWordsThreshold, const int32 InRareWordsThreshold, const bool InIsSet )
    :   CommonWordOffset(InCommonWordOffset), CommonWordsThreshold(InCommonWordsThreshold),
        UncommonWordOffset(InUncommonWordOffset),UncommonWordsThreshold(InUncommonWordsThreshold),
        RareWordsThreshold(InRareWordsThreshold), IsSet(InIsSet)
    {  };

};

