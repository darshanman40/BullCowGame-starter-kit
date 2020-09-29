#pragma once
#include "CoreMinimal.h"
#include "UStringHelper.generated.h"

UCLASS()
class UStringHelper : public UObject
{
    GENERATED_UCLASS_BODY()

    public:
    static bool IsIsogram(const FString& Input);
    static bool IsPalindrome(const FString& Input);
};