#include "RuleEngine/FRuleBO.h"
#include "RuleEngine/FWordGameModeRules.h"


void FRuleBO::SetWordGameModeRules(
    const int32 InputCommonWordOffset, 
    const int32 InputCommonWordsThreshold,
    const int32 InputUncommonWordOffset,
    const int32 InputUncommonWordsThreshold,
    const int32 InputRareWordsThreshold)
{
    WGMRules = FWordGameModeRules(InputCommonWordOffset,InputCommonWordsThreshold,InputUncommonWordOffset,InputUncommonWordsThreshold,InputRareWordsThreshold,true);
}

void FRuleBO::SetWordGameModeRules(const FWordGameModeRules InWGMRules)
{
    WGMRules = InWGMRules;
}

const FWordGameModeRules FRuleBO::GetFWordGameModeRules()
{
    return WGMRules;
}
