#pragma once

#include "UPMBPFL.h"

void UPMBPFL::PM_ForceUpdateFactory(AFGBuildableFactory* target)
{
	// Note: GetCurrentPotential returns nonsense for Generators,
	// So I'm just reading the variable directly now.
	target->SetCurrentPotential(target->mCurrentPotential);
}

UFGRecipe* UPMBPFL::PM_GetRecipeCDO(TSubclassOf<UFGRecipe> target)
{
	UFGRecipe* cdo = target.GetDefaultObject();
	cdo->AddToRoot();
	return cdo;
}