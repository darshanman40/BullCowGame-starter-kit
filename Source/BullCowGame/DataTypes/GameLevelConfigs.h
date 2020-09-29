#pragma once

#include "CoreMinimal.h"

#include "GameLevelConfigs.generated.h"

UENUM(BlueprintType)
enum class EGameMode : uint8
{
    Training UMETA(DisplayName = "Training"),
    Challenging UMETA(DisplayName = "Challenging"),
    Endless UMETA(DisplayName = "Endless")
};

UENUM(BlueprintType)
enum class EGameType : uint8
{
    WordGame UMETA(DisplayName = "Word Game"),
    NumberGame UMETA(DisplayName = "Number Game")
};

UENUM(BlueprintType)
enum class EDifficulty : uint8
{
    Test UMETA(DisplayName = "Test"),
    Easy UMETA(DisplayName = "Easy"),
    Medium UMETA(DisplayName = "Medium"),
    Hard UMETA(DisplayName = "Hard")
};

USTRUCT(BlueprintType)
struct BULLCOWGAME_API FGameLevelConfigs
{
    GENERATED_BODY()
    
    public:

    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category=Enum)
    EGameMode GameMode; // Training, Challenging, Endless 

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category=Enum)
    EGameType GameType; // WordGame, NumberGame

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category=Enum)
    EDifficulty Difficulty; // Test, Easy, Medium, Hard

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category=Enum)
    bool IsSet;

    FGameLevelConfigs() :
        GameMode(EGameMode()), GameType(EGameType()), Difficulty(EDifficulty()), IsSet(false)
        {};
    FGameLevelConfigs(const EGameMode InGameMode, const EGameType InGameType, 
        const EDifficulty InDifficulty, const bool InIsSet)
        : GameMode(InGameMode), GameType(InGameType), 
          Difficulty(InDifficulty), IsSet(InIsSet)
    {
        IsSet = true;
    };

};



