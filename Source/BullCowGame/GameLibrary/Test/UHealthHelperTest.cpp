#include "CoreTypes.h"
#include "Containers/UnrealString.h"
#include "GameLibrary/Headers/UHealthHelper.h"
#include "Misc/AutomationTest.h"


#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(UHealthHelperTest, "GameLibrary.HealthHelper", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::SmokeFilter)


bool UHealthHelperTest::RunTest(const FString& Parameters)
{
    int32 HEALTH = 50;
    int32 MAX_HEALTH = 100;
    int32 NO_HEALTH = 0;
    int32 HEAL = 10;
    int32 DAMAGE = 20;

    bool isIncrementHealthByOnePass1;
    bool isIncrementHealthByOnePass2;
    bool isDecrementHealthByOnePass1;
    bool isDecrementHealthByOnePass2;
    

	{
        UHealthHelper::IncrementHealthByOne(HEALTH, MAX_HEALTH);
		TestEqual(TEXT("(IncrementHealthByOne) should increment health from 50 to 51 "),HEALTH, 51 );
        UHealthHelper::IncrementHealthByOne(MAX_HEALTH, MAX_HEALTH);
		TestEqual(TEXT("(IncrementHealthByOne) should increment health from 100 to 100 "),MAX_HEALTH, 100 );

        UHealthHelper::DecrementHealthByOne(HEALTH);
        TestEqual(TEXT("(DecrementHealthByOne) should decrement health 51 to 50"),HEALTH, 50 );
        UHealthHelper::DecrementHealthByOne(NO_HEALTH);
        TestEqual(TEXT("(DecrementHealthByOne) should decrement health from 0 to 0"),NO_HEALTH, 0 );

        UHealthHelper::IncrementHealth(HEALTH, MAX_HEALTH, HEAL);
        TestEqual(TEXT("(IncrementHealth) should increment health from 50 to 60"),HEALTH, 60 );
        UHealthHelper::IncrementHealth(MAX_HEALTH, MAX_HEALTH, HEAL);
        TestEqual(TEXT("(IncrementHealth) should increment health from 100 to 100"),MAX_HEALTH, 100 );

        UHealthHelper::DecrementHealth(HEALTH, DAMAGE);
        TestEqual(TEXT("(DecrementHealth) should decrement health from 60 to 40"),HEALTH, 40 );
        UHealthHelper::DecrementHealth(NO_HEALTH, DAMAGE);
        TestEqual(TEXT("(DecrementHealth) should decrement health from 0 to 0"),NO_HEALTH, 0 );

	}


     return true;
}
#endif //WITH_DEV_AUTOMATION_TESTS