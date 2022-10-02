#pragma once

#include "UPMBPFL.h"

#include "Buildables/FGBuildableFactory.h"

void UPMBPFL::PM_ForceUpdateFactory(AFGBuildableFactory* target)
{
	target->SetCurrentPotential(target->GetCurrentPotential());
}