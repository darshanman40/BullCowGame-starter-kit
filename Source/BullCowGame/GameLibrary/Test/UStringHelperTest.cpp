#include "CoreTypes.h"
#include "Containers/UnrealString.h"
#include "GameLibrary/Headers/UStringHelper.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(UStringHelperTest, "GameLibrary.UStringHelper", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::SmokeFilter)


bool UStringHelperTest::RunTest(const FString& Parameters)
{

    const FString BOBO ="bobo";
    const FString STUDENT ="student";

	// check if string is isogram
	{
        
        TestFalse(TEXT("IsIsogram(bobo) should be false "), UStringHelper::IsIsogram("bobo"));
		TestEqual(TEXT("IsIsogram(student) should be false)"), UStringHelper::IsIsogram("student"), false);
        TestEqual(TEXT("IsIsogram(hospital) should be true"), UStringHelper::IsIsogram("hospital"), true);
        TestEqual(TEXT("IsIsogram(halo) should be true"), UStringHelper::IsIsogram("halo"), true);
	}

    // check if string is plaindrome
    {
        TestEqual(TEXT("IsPalindrome(bobo) should be false"), UStringHelper::IsPalindrome("bobo"), false);
        TestEqual(TEXT("IsPalindrome(help) should be false"), UStringHelper::IsPalindrome("help"), false);
        TestEqual(TEXT("IsPalindrome(train) should be false"), UStringHelper::IsPalindrome("train"), false);
        TestEqual(TEXT("IsPalindrome(aaabbbcccbbbaaa) should be true"), UStringHelper::IsPalindrome("aaabbbcccbbbaaa"), true);
    }
    
    return true;
}
#endif //WITH_DEV_AUTOMATION_TESTS