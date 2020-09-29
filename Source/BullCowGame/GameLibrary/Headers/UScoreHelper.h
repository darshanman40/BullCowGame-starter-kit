#pragma once
#include "CoreMinimal.h"
#include "UScoreHelper.generated.h"


USTRUCT()
struct FPlayerScore
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY()
    int32 TempTotalScore;

    UPROPERTY()
    int32 DisplayScore;

    FPlayerScore(const int32 score)
    {
        TempTotalScore = score;
        DisplayScore = score;
    }

    FPlayerScore()
    {
        TempTotalScore = 0;
        DisplayScore = 0;
    }

};

UCLASS()
class UScoreHelper : public UObject
{


/*

Maintain player score
- increment temp score by 1
- increment temp score by N
- Assign Max temp score and display score for a level
- decrement temp score by 1
- decrement temp score by N
- update display score from temp
- get display score

*/
    
    GENERATED_UCLASS_BODY()

    private:
    static FPlayerScore PlayerScore;

    public:
    static FORCEINLINE int32 GetPlayerScore()
    {
        return PlayerScore.DisplayScore;
    };
    
    static void IncrementScoreByOne()
    {
        PlayerScore.TempTotalScore++ ;   
    };
    static void DecrementScoreByOne()
    {
        if (PlayerScore.TempTotalScore > 0) PlayerScore.TempTotalScore-- ; 
    };

    static void IncrementScore(int32 score)
    {
        PlayerScore.TempTotalScore += score;
    };

    static void DecrementScore(int32 score)
    {
        PlayerScore.TempTotalScore -= score;
        if (PlayerScore.TempTotalScore > 0) UScoreHelper::PlayerScore.TempTotalScore = 0;
    };

    static void UpdateScore()
    {
        PlayerScore.DisplayScore = UScoreHelper::PlayerScore.TempTotalScore;
    };
    
    static void ApplyBonusMultiplier(int32 score)
    {
        PlayerScore.TempTotalScore *= score;
    };

};