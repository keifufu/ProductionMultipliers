#pragma once

#include "ProductionMultipliersGameInstanceModule.h"

#include <Subsystem/SubsystemActorManager.h>

#include "ProductionMultipliersClientSubsystem.h"

#include "SatisfactoryModLoader.h"
#include "Patching/NativeHookManager.h"
#include "Buildables/FGBuildableFactory.h"

DEFINE_LOG_CATEGORY(LogProductionMultipliers);

void UProductionMultipliersGameInstanceModule::DispatchLifecycleEvent(ELifecyclePhase Phase)
{
	Super::DispatchLifecycleEvent(Phase);

	if (Phase == ELifecyclePhase::POST_INITIALIZATION) {
		UE_LOG(LogProductionMultipliers, Display, TEXT("[DEBUG] Post Initialization: Registering Hooks"));
		AFGBuildableFactory* bfCDO = GetMutableDefault<AFGBuildableFactory>();
		SUBSCRIBE_METHOD_VIRTUAL_AFTER(AFGBuildableFactory::OnRep_ReplicationDetailActor, bfCDO, ([this](AFGBuildableFactory* self) {
			UWorld* CurrentWorld = GetWorld();
			if (CurrentWorld) {
				UE_LOG(LogProductionMultipliers, Display, TEXT("[DEBUG] Replicated Detail Actor for: %s"), *self->GetName());
				AProductionMultipliersClientSubsystem* ProductionMultipliersClientSubsystem = CurrentWorld->GetSubsystem<USubsystemActorManager>()->GetSubsystemActor<AProductionMultipliersClientSubsystem>();

				if (ProductionMultipliersClientSubsystem) {
					ProductionMultipliersClientSubsystem->PM_OnReplicated.Broadcast(self);
				} else {
					UE_LOG(LogProductionMultipliers, Error, TEXT("[DEBUG] Failed to find AProductionMultipliersClientSubsystem"));
				}
			}
		}));
	}
}