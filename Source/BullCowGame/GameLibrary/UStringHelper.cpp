#include "Headers/UStringHelper.h"
#include "UObject/Object.h"

#include <bitset>
#include <cctype>


UStringHelper::UStringHelper(const FObjectInitializer& ObjectInitializer)	: 
    Super(ObjectInitializer)
{

}

bool UStringHelper::IsIsogram(const FString& Input)
{

    FString tempInput = *Input.ToLower();
    int32 n = 0;
    for (TCHAR c : tempInput)
    {
        int32 i;
        tempInput.FindChar(c,i);
        if (i!=n) return false;
        n++;
    }

    return true;
}

bool UStringHelper::IsPalindrome(const FString& Input)
{ 
    FString NewString = Input.Reverse();
    return Input.Equals(NewString,ESearchCase::IgnoreCase);
}