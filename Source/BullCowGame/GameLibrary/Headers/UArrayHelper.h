#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UArrayHelper.generated.h"

UCLASS()
class UArrayHelper : public UObject
{
    GENERATED_UCLASS_BODY()
	

    public:
	

	// Designed to shuffle entire array
	template<class T>
	static FORCEINLINE void ShuffleList(TArray<T>& datalist, int32 size, int32 seed)
	{
		srand(seed);
		for (int32 i = 0; i < size; i++)
		{
			int32 index = rand() % size;
			auto temp = datalist[i];
			datalist[i] = datalist[index];
			datalist[index] = temp;
		}
	}
	
	// Designed to shuffle array from specific range
	template<class T>
	static FORCEINLINE void ShuffleList(TArray<T>& datalist, int32 startOffset, int32 loopCount, int32 seed)
	{
		srand(seed);
		for (int32 i=0; i < loopCount; i++)
		{
			int32 index = (rand() % loopCount) + startOffset;
			auto temp = datalist[i+startOffset];
			datalist[i+startOffset] = datalist[index];
			datalist[index] = temp;
		}
	}

};