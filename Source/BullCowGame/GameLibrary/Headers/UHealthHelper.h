#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UHealthHelper.generated.h"


// https://www.geeksforgeeks.org/passing-by-pointer-vs-passing-by-reference-in-c/

UCLASS()
class UHealthHelper : public UObject
{

    GENERATED_UCLASS_BODY()
    
    public:
    static void IncrementHealthByOne(int32& Health, int32& MaxHealth)
    {
        if (Health < MaxHealth )
        {
            Health++ ;
        }
    };

    static bool DecrementHealthByOne(int32& Health)
    {
        if (Health <= 1)
        {
            Health = 0;
            return true;
        }

        Health-- ;
        return false;
    };

    static bool IncrementHealth(int32& Health, int32 MaxHealth, int32 Heal)
    {
        bool IsOverHealth = false;
        int32 NewHealth = Health + Heal;
        if (NewHealth > MaxHealth)
        {
            IsOverHealth = true;
            Health = MaxHealth;
        }
        else
        {
            Health = NewHealth;
            IsOverHealth = false;
        }

        return IsOverHealth;
    };

    static bool DecrementHealth(int32& Health, int32 damage)
    {
        bool IsDead = false;
        if (Health <= damage)
        {
            Health = 0;
            IsDead = true;
        }
        else 
        {
            Health -= damage;
            IsDead = false;
        }

        return IsDead;    
    };

};