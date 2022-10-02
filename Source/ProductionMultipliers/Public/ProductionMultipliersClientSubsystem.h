#pragma once

#include "Subsystem/ModSubsystem.h"
#include "Buildables/FGBuildableFactory.h"

#include "ProductionMultipliersClientSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPMOnReplicated, AFGBuildableFactory*, target);

UCLASS()
class PRODUCTIONMULTIPLIERS_API AProductionMultipliersClientSubsystem : public AModSubsystem
{
	GENERATED_BODY()

public:
	AProductionMultipliersClientSubsystem() {
		this->ReplicationPolicy = ESubsystemReplicationPolicy::SpawnOnClient;
	}

	UPROPERTY(BlueprintAssignable)
	FPMOnReplicated PM_OnReplicated;
};