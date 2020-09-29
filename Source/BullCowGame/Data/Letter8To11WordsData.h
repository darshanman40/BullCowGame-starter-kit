#pragma once
#include "CoreMinimal.h"

const TArray<FString> LETTER_8_TO_11_WORDS =
{
    TEXT("abolishment"), // 0
    TEXT("aftershock"), // 1
    TEXT("artichokes"), // 2
    TEXT("atmospheric"), // 3
    TEXT("authorizes"), // 4
    TEXT("background"), // 5
    TEXT("backgrounds"), // 6
    TEXT("bankruptcy"), // 7
    TEXT("behavior"), // 8
    TEXT("binoculars"), // 9
    TEXT("birthplaces"), // 10
    TEXT("blackhorse"), // 11
    TEXT("blacksmith"), // 12
    TEXT("boyfriends"), // 13
    TEXT("campground"), // 14
    TEXT("campgrounds"), // 15
    TEXT("certainly"), // 16
    TEXT("clothespin"), // 17
    TEXT("complainers"), // 18
    TEXT("complaints"), // 19
    TEXT("computer"), // 20
    TEXT("conjugated"), // 21
    TEXT("consider"), // 22
    TEXT("construe"), // 23
    TEXT("consumer"), // 24
    TEXT("copyrighted"), // 25
    TEXT("copyrights"), // 26
    TEXT("cornflakes"), // 27
    TEXT("countryside"), // 28
    TEXT("customer"), // 29
    TEXT("dangerously"), // 30
    TEXT("daughter"), // 31
    TEXT("democrat"), // 32
    TEXT("designatory"), // 33
    TEXT("despicably"), // 34
    TEXT("destroying"), // 35
    TEXT("discover"), // 36
    TEXT("disgraceful"), // 37
    TEXT("disturbance"), // 38
    TEXT("documentary"), // 39
    TEXT("dogmatic"), // 40
    TEXT("downstream"), // 41
    TEXT("duplicates"), // 42
    TEXT("earthmoving"), // 43
    TEXT("education"), // 44
    TEXT("embracingly"), // 45
    TEXT("epistolary"), // 46
    TEXT("equivocal"), // 47
    TEXT("facetiously"), // 48
    TEXT("farsighted"), // 49
    TEXT("filmography"), // 50
    TEXT("flashpoint"), // 51
    TEXT("fluoridates"), // 52
    TEXT("foremanship"), // 53
    TEXT("formidable"), // 54
    TEXT("fractious"), // 55
    TEXT("geophysical"), // 56
    TEXT("godparents"), // 57
    TEXT("gourmand"), // 58
    TEXT("graciously"), // 59
    TEXT("greyhounds"), // 60
    TEXT("hospitable"), // 61
    TEXT("hospitably"), // 62
    TEXT("hospital"), // 63
    TEXT("importance"), // 64
    TEXT("importances"), // 65
    TEXT("imprudently"), // 66
    TEXT("inchoate"), // 67
    TEXT("industry"), // 68
    TEXT("infamously"), // 69
    TEXT("inoculate"), // 70
    TEXT("introduces"), // 71
    TEXT("journalized"), // 72
    TEXT("judgmental"), // 73
    TEXT("juxtaposed"), // 74
    TEXT("juxtaposing"), // 75
    TEXT("keyboarding"), // 76
    TEXT("lawrencium"), // 77
    TEXT("lumberjack"), // 78
    TEXT("lumberjacks"), // 79
    TEXT("majority"), // 80
    TEXT("malnourish"), // 81
    TEXT("maverick"), // 82
    TEXT("mendacious"), // 83
    TEXT("misanthrope"), // 84
    TEXT("misanthropy"), // 85
    TEXT("mistakenly"), // 86
    TEXT("monarchist"), // 87
    TEXT("nightmares"), // 88
    TEXT("noticeably"), // 89
    TEXT("obdurate"), // 90
    TEXT("obfuscate"), // 91
    TEXT("overstaying"), // 92
    TEXT("palindromes"), // 93
    TEXT("pathfinder"), // 94
    TEXT("percolating"), // 95
    TEXT("personal"), // 96
    TEXT("personality"), // 97
    TEXT("physical"), // 98
    TEXT("playgrounds"), // 99
    TEXT("playwrights"), // 100
    TEXT("plethora"), // 101
    TEXT("precautions"), // 102
    TEXT("predictably"), // 103
    TEXT("problematic"), // 104
    TEXT("profligate"), // 105
    TEXT("promulgate"), // 106
    TEXT("quadriceps"), // 107
    TEXT("question"), // 108
    TEXT("regulations"), // 109
    TEXT("republican"), // 110
    TEXT("republicans"), // 111
    TEXT("scubadiver"), // 112
    TEXT("secondarily"), // 113
    TEXT("security"), // 114
    TEXT("shockingly"), // 115
    TEXT("shoulder"), // 116
    TEXT("slumbering"), // 117
    TEXT("sobriety"), // 118
    TEXT("something"), // 119
    TEXT("southern"), // 120
    TEXT("spaceflight"), // 121
    TEXT("speculation"), // 122
    TEXT("stenography"), // 123
    TEXT("subcategory"), // 124
    TEXT("switzerland"), // 125
    TEXT("thousand"), // 126
    TEXT("thunderclap"), // 127
    TEXT("trampoline"), // 128
    TEXT("trampolines"), // 129
    TEXT("trapezoids"), // 130
    TEXT("ultrasonic"), // 131
    TEXT("undesirably"), // 132
    TEXT("unpolarized"), // 133
    TEXT("vibraphones"), // 134
    TEXT("warehousing"), // 135
    TEXT("waveringly"), // 136
    TEXT("workmanship"), // 137
    TEXT("xylographic"), // 138
    TEXT("yourself") // 139
};
const int32 LETTER_8_TO_11_WORDS_SIZE = LETTER_8_TO_11_WORDS.Num();
const TArray<int32> LETTER_8_TO_11_UNCOMMON_WORDS_INDICES =
{
    6,15,19,21,23,          25,33,34,40,43,
    46,48,52,55,58,         59,62,65,66,67, // mid point at 69
    75,82,85,91,95,         97,100,101,105,106,
    107,111,113,118,123,    129,130,134,136,138
};
const int32 LETTER_8_TO_11_UNCOMMON_WORDS_INDICES_SIZE = LETTER_8_TO_11_UNCOMMON_WORDS_INDICES.Num();

const TArray<FString> LETTER_8_TO_11_RARE_WORDS =
{
    TEXT("clamor"),     // 0
    TEXT("debauch"),    // 1
    TEXT("mawkish"),    // 2
    TEXT("maudlin"),    // 3
    TEXT("paucity"),    // 4
    TEXT("plaudit"),    // 5
    TEXT("probity"),    // 6
    TEXT("rescind"),    // 7 
    TEXT("swarthy"),    // 8
    TEXT("upbraid")     // 9
};
const int32 LETTER_8_TO_11_RARE_WORDS_SIZE = LETTER_8_TO_11_RARE_WORDS.Num();