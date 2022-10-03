#pragma once

#include "UPMBPFL.h"

void UPMBPFL::PM_ForceUpdateFactory(AFGBuildableFactory* target)
{
	target->SetCurrentPotential(target->GetCurrentPotential());
}

UFGRecipe* UPMBPFL::PM_GetRecipeCDO(TSubclassOf<UFGRecipe> target)
{
	UFGRecipe* cdo = target.GetDefaultObject();
	cdo->AddToRoot();
	return cdo;
}