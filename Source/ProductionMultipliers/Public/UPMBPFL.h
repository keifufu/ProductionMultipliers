#pragma once

#include "CoreMinimal.h"
#include "Buildables/FGBuildableFactory.h"

#include "UPMBPFL.generated.h"

UCLASS()
class PRODUCTIONMULTIPLIERS_API UPMBPFL : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	public:

	UFUNCTION(BlueprintCallable)
	static void PM_ForceUpdateFactory(AFGBuildableFactory* target);
};