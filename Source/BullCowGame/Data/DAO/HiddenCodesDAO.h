#pragma once
#include "CoreMinimal.h"

#include "DataTypes/GameLevelConfigs.h"

#include "HiddenCodesDAO.generated.h"




USTRUCT()
struct FHiddenCodesDO
{
    GENERATED_BODY()

    private:

    UPROPERTY()
    TArray<FString> CodesList;

    UPROPERTY()
    int32 CodesListSize;

    UPROPERTY()
    TArray<int32> UncommonWordIndices;

    UPROPERTY()
    int32 UncommonCodesListSize;

    UPROPERTY()
    TArray<FString> RareCodesList;

    UPROPERTY()
    int32 RareCodesListSize;


    public:
    
    //Constructor
    FHiddenCodesDO() :
        CodesList(TArray<FString>()), CodesListSize(0), UncommonWordIndices(TArray<int32>()), UncommonCodesListSize(0),
            RareCodesList(TArray<FString>()), RareCodesListSize(0)
        {};

    FHiddenCodesDO(const TArray<FString> InCodesList, const int32 InCodesListSize, 
        const TArray<int32> InUncommonWordIndices, const int32 InUncommonCodesListSize,
        const TArray<FString> InRareCodesList, const int32 InRareCodesListSize)
        : CodesList(InCodesList), CodesListSize(InCodesListSize), 
          UncommonWordIndices(InUncommonWordIndices), UncommonCodesListSize(InUncommonCodesListSize),
          RareCodesList(InRareCodesList), RareCodesListSize(InRareCodesListSize)
    {};

    //Getters
    TArray<FString> GetCodesList(){return CodesList;};
    int32 GetCodesListSize(){return CodesListSize;};
    TArray<int32> GetUncommonWordIndices(){return UncommonWordIndices;};
    int32 GetUncommonCodesListSize(){return UncommonCodesListSize;};
    TArray<FString> GetRareCodesList(){return RareCodesList;};
    int32 GetRareCodesListSize(){return RareCodesListSize;};
    

};

USTRUCT(BlueprintType)
struct FHiddenCodesDAO
{
    GENERATED_BODY()

    private:

    UPROPERTY()
    FHiddenCodesDO CurrentData;

    // Variables
    UPROPERTY()
    FGameLevelConfigs GameLevelConfigs;

    void SetupDataForWordGame();
    void SetupDataForNumberGame();

    public:

    FHiddenCodesDAO() :
        GameLevelConfigs(FGameLevelConfigs(EGameMode(),EGameType(),EDifficulty(),bool()))
    {};

    FHiddenCodesDAO(FGameLevelConfigs InFGameLevelConfigs) 
        : GameLevelConfigs(InFGameLevelConfigs)
    {
        if ( InFGameLevelConfigs.GameType == EGameType::WordGame )
            SetupDataForWordGame();
        else if(InFGameLevelConfigs.GameType == EGameType::NumberGame)
            SetupDataForNumberGame();
    };

    TArray<FString> GetCodesList();
    int32 GetCodesListSize(); 
    TArray<int32> GetUncommonWordIndices();
    int32 GetUncommonCodesListSize();
    TArray<FString> GetRareCodesList();
    int32 GetRareCodesListSize();

};