#pragma once

#include "CoreMinimal.h"
#include "Subsystem/ModSubsystem.h"
#include "Buildables/FGBuildableFactory.h"

#include "ProductionMultipliersSubsystem.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogProductionMultipliers, Log, All);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPMOnReplicated, AFGBuildableFactory*, target);

UCLASS()
class PRODUCTIONMULTIPLIERS_API AProductionMultipliersSubsystem : public AModSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void PM_RegisterHooks(AProductionMultipliersSubsystem* Subsystem, bool Debug);

	UPROPERTY(BlueprintAssignable)
	FPMOnReplicated PM_OnReplicated;
};