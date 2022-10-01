#pragma once

#include "ProductionMultipliersSubsystem.h"

#include "Patching/NativeHookManager.h"
#include "Buildables/FGBuildableFactory.h"

DEFINE_LOG_CATEGORY(LogProductionMultipliers);

void AProductionMultipliersSubsystem::PM_RegisterHooks(AProductionMultipliersSubsystem* Subsystem, bool Debug) {
	if (Debug)
		UE_LOG(LogProductionMultipliers, Display, TEXT("Registering Hooks"));
	AFGBuildableFactory* bfCDO = GetMutableDefault<AFGBuildableFactory>();
	SUBSCRIBE_METHOD_VIRTUAL_AFTER(AFGBuildableFactory::OnRep_ReplicationDetailActor, bfCDO, ([Subsystem, Debug](AFGBuildableFactory* self) {
		if (Debug)
			UE_LOG(LogProductionMultipliers, Display, TEXT("Replicated Detail Actor for: %s"), *self->GetName());
		Subsystem->PM_OnReplicated.Broadcast(self);
	}));
}