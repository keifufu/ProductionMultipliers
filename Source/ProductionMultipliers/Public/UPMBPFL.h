#pragma once

#include "Buildables/FGBuildableFactory.h"
#include "FGRecipe.h"

#include "UPMBPFL.generated.h"

UCLASS()
class PRODUCTIONMULTIPLIERS_API UPMBPFL : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	static void PM_ForceUpdateFactory(AFGBuildableFactory* target);

	UFUNCTION(BlueprintCallable)
	static UFGRecipe* PM_GetRecipeCDO(TSubclassOf<UFGRecipe> target);
};