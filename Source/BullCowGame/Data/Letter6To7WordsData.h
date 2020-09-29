#pragma once
#include "CoreMinimal.h"

const TArray<FString> LETTER_6_TO_7_WORDS =
{
    TEXT("abject"), // 0
    TEXT("abscond"), // 1
    TEXT("action"), // 2
    TEXT("acumen"), // 3
    TEXT("agency"), // 4
    TEXT("almost"), // 5
    TEXT("amount"), // 6
    TEXT("another"), // 7
    TEXT("answer"), // 8
    TEXT("around"), // 9
    TEXT("article"), // 10
    TEXT("atrophy"), // 11
    TEXT("author"), // 12
    TEXT("bashful"), // 13
    TEXT("behind"), // 14
    TEXT("beyond"), // 15
    TEXT("budget"), // 16
    TEXT("cajole"), // 17
    TEXT("calumny"), // 18
    TEXT("candor"), // 19
    TEXT("carouse"), // 20
    TEXT("cavort"), // 21
    TEXT("central"), // 22
    TEXT("century"), // 23
    TEXT("certain"), // 24
    TEXT("change"), // 25
    TEXT("charge"), // 26
    TEXT("cogent"), // 27
    TEXT("company"), // 28
    TEXT("compare"), // 29
    TEXT("conduit"), // 30
    TEXT("country"), // 31
    TEXT("couple"), // 32
    TEXT("course"), // 33
    TEXT("dearth"), // 34
    TEXT("debunk"), // 35
    TEXT("defunct"), // 36
    TEXT("design"), // 37
    TEXT("despot"), // 38
    TEXT("detail"), // 39
    TEXT("dispel"), // 40
    TEXT("during"), // 41
    TEXT("enough"), // 42
    TEXT("exactly"), // 43
    TEXT("exhort"), // 44
    TEXT("explain"), // 45
    TEXT("factor"), // 46
    TEXT("family"), // 47
    TEXT("father"), // 48
    TEXT("figure"), // 49
    TEXT("finger"), // 50
    TEXT("foreign"), // 51
    TEXT("forget"), // 52
    TEXT("friend"), // 53
    TEXT("garden"), // 54
    TEXT("isogram"), // 55
    TEXT("ground"), // 56
    TEXT("growth"), // 57
    TEXT("himself"), // 58
    TEXT("history"), // 59
    TEXT("husband"), // 60
    TEXT("impact"), // 61
    TEXT("improve"), // 62
    TEXT("impute"), // 63
    TEXT("include"), // 64
    TEXT("instead"), // 65
    TEXT("itself"), // 66
    TEXT("kitchen"), // 67
    TEXT("lawyer"), // 68
    TEXT("listen"), // 69
    TEXT("machine"), // 70
    TEXT("market"), // 71
    TEXT("medical"), // 72
    TEXT("method"), // 73
    TEXT("minute"), // 74
    TEXT("modern"), // 75
    TEXT("mother"), // 76
    TEXT("myself"), // 77
    TEXT("nature"), // 78
    TEXT("nearly"), // 79
    TEXT("network"), // 80
    TEXT("notice"), // 81
    TEXT("number"), // 82
    TEXT("others"), // 83
    TEXT("outside"), // 84
    TEXT("parent"), // 85
    TEXT("period"), // 86
    TEXT("person"), // 87
    TEXT("picture"), // 88
    TEXT("player"), // 89
    TEXT("police"), // 90
    TEXT("policy"), // 91
    TEXT("private"), // 92
    TEXT("problem"), // 93
    TEXT("produce"), // 94
    TEXT("product"), // 95
    TEXT("project"), // 96
    TEXT("protean"), // 97
    TEXT("provide"), // 98
    TEXT("public"), // 99
    TEXT("quaint"), // 100
    TEXT("quality"), // 101
    TEXT("quickly"), // 102
    TEXT("reality"), // 103
    TEXT("reason"), // 104
    TEXT("region"), // 105
    TEXT("remain"), // 106
    TEXT("respond"), // 107
    TEXT("result"), // 108
    TEXT("second"), // 109
    TEXT("section"), // 110
    TEXT("senior"), // 111
    TEXT("should"), // 112
    TEXT("simple"), // 113
    TEXT("simply"), // 114
    TEXT("single"), // 115
    TEXT("social"), // 116
    TEXT("society"), // 117
    TEXT("soldier"), // 118
    TEXT("source"), // 119
    TEXT("special"), // 120
    TEXT("spring"), // 121
    TEXT("stolid"), // 122
    TEXT("strong"), // 123
    TEXT("subject"), // 124
    TEXT("surface"), // 125
    TEXT("surfeit"), // 126
    TEXT("theory"), // 127
    TEXT("tirade"), // 128
    TEXT("torpid"), // 129
    TEXT("toward"), // 130
    TEXT("travel"), // 131
    TEXT("trouble"), // 132
    TEXT("umbrage"), // 133
    TEXT("various"), // 134
    TEXT("weapon"), // 135
    TEXT("weight"), // 136
    TEXT("winsome"), // 137
    TEXT("wonder"), // 138
    TEXT("zephyr") // 139
};
const int32 LETTER_6_TO_7_WORDS_SIZE = LETTER_6_TO_7_WORDS.Num();
const TArray<int32> LETTER_6_TO_7_UNCOMMON_WORDS_INDICES =
{
    0,1,3,11,13,            17,18,19,20,21,
    27,30,34,35,36,         38,44,46,63,64,  // b4 70
    72,79,83,91,97,         100,103,107,111,119,
    120,122,124,126,128,    129,133,134,137,139
};
const int32 LETTER_6_TO_7_UNCOMMON_WORDS_INDICES_SIZE = LETTER_6_TO_7_UNCOMMON_WORDS_INDICES.Num();

const TArray<FString> LETTER_6_TO_7_RARE_WORDS =
{
    TEXT("clamor"),         // 0
    TEXT("debauch"),        // 1
    TEXT("mawkish"),        // 2
    TEXT("maudlin"),        // 3
    TEXT("paucity"),        // 4
    TEXT("plaudit"),        // 5
    TEXT("probity"),        // 6
    TEXT("rescind"),        // 7
    TEXT("swarthy"),        // 8
    TEXT("upbraid")         // 9
};
const int32 LETTER_6_TO_7_RARE_WORDS_SIZE = LETTER_6_TO_7_RARE_WORDS.Num();

//--------------------
// TEST DATA
//--------------------

const TArray<FString> TEST_LETTER_6_TO_7_WORDS =
{
    TEXT("abject"), // 0
    TEXT("abscond"), // 1
    TEXT("action"), // 2
    TEXT("acumen"), // 3
    TEXT("agency"), // 4
    TEXT("almost"), // 5
    TEXT("weight"), // 6
    TEXT("winsome"), // 7
    TEXT("wonder"), // 8
    TEXT("zephyr") // 9
};
const int32 TEST_LETTER_6_TO_7_WORDS_SIZE = TEST_LETTER_6_TO_7_WORDS.Num();
const TArray<int32> TEST_LETTER_6_TO_7_UNCOMMON_WORDS_INDICES = 
{
    0,3,    7,9
};
const int32 TEST_LETTER_6_TO_7_UNCOMMON_WORDS_INDICES_SIZE = TEST_LETTER_6_TO_7_UNCOMMON_WORDS_INDICES.Num();
const TArray<FString> TEST_LETTER_6_TO_7_RARE_WORDS = LETTER_6_TO_7_RARE_WORDS;
const int32 TEST_LETTER_6_TO_7_RARE_WORDS_SIZE = TEST_LETTER_6_TO_7_RARE_WORDS.Num();

