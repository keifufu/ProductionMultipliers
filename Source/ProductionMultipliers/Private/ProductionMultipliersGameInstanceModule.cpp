#pragma once

#include "ProductionMultipliersGameInstanceModule.h"

#include <Subsystem/SubsystemActorManager.h>

#include "ProductionMultipliersClientSubsystem.h"

#include "SatisfactoryModLoader.h"
#include "Patching/NativeHookManager.h"
#include "Buildables/FGBuildableFactory.h"
#include "Buildables/FGBuildableFrackingActivator.h"
#include "FGRecipe.h"

DEFINE_LOG_CATEGORY(LogProductionMultipliers);

void UProductionMultipliersGameInstanceModule::DispatchLifecycleEvent(ELifecyclePhase Phase)
{
	Super::DispatchLifecycleEvent(Phase);

	if (Phase == ELifecyclePhase::POST_INITIALIZATION) {
		UE_LOG(LogProductionMultipliers, Display, TEXT("[DEBUG] Post Initialization: Registering Hooks"));

		AFGBuildableFactory* bfCDO = GetMutableDefault<AFGBuildableFactory>();
		bfCDO->AddToRoot();
		/*
		 * We used to hook `OnRep_ReplicationDetailActor` here, which seems to have been called every time a client
		 * interacted with a machine which has not been replicated yet.
		 * 
		 * This seems to have changed somewhere around U7? It doesn't fire anymore.
		 * Luckily `OnRep_CurrentPotential` also fires every time we replicate the machine,
		 * although I guess it could also fire unnecessarily sometimes. I don't think that matters much.
		 */
		SUBSCRIBE_METHOD_VIRTUAL_AFTER(AFGBuildableFactory::OnRep_CurrentPotential, bfCDO, ([this](AFGBuildableFactory* self) {
			UWorld* CurrentWorld = GetWorld();
			if (CurrentWorld) {
				//UE_LOG(LogProductionMultipliers, Display, TEXT("[DEBUG] Replicated Detail Actor for: %s"), *self->GetName());
				UE_LOG(LogProductionMultipliers, Display, TEXT("[DEBUG] Replicated Actor: %s"), *self->GetName());
				AProductionMultipliersClientSubsystem* ProductionMultipliersClientSubsystem = CurrentWorld->GetSubsystem<USubsystemActorManager>()->GetSubsystemActor<AProductionMultipliersClientSubsystem>();

				if (ProductionMultipliersClientSubsystem) {
					ProductionMultipliersClientSubsystem->PM_OnReplicated.Broadcast(self);
				}
				else {
					UE_LOG(LogProductionMultipliers, Error, TEXT("[DEBUG] Failed to find AProductionMultipliersClientSubsystem"));
				}
			}
			else {
				UE_LOG(LogProductionMultipliers, Error, TEXT("[DEBUG] Failed to find CurrentWorld"));
			}
		}));
	}
}