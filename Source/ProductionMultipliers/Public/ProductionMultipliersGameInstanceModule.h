#pragma once

#include "Module/GameInstanceModule.h"

#include "ProductionMultipliersGameInstanceModule.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogProductionMultipliers, Log, All);

UCLASS(BlueprintType)
class UProductionMultipliersGameInstanceModule : public UGameInstanceModule
{
	GENERATED_BODY()

public:
	virtual void DispatchLifecycleEvent(ELifecyclePhase Phase) override;
};