// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "SpatialFunctionalTest.h"
#include "SpyValueGASTestActor.h"
#include "CrossServerAbilityActivationTest.generated.h"

/**
 * Tests that a gameplay ability can be activated on an actor across a server boundary.
 * Activation by ability spec, class, tag, and gameplay event are tested.
 */
UCLASS()
class SPATIALGDKFUNCTIONALTESTS_API ACrossServerAbilityActivationTest : public ASpatialFunctionalTest
{
	GENERATED_BODY()

	ACrossServerAbilityActivationTest();

	virtual void PrepareTest() override;

	UPROPERTY(EditInstanceOnly, Category = "Test Settings")
	float DuplicateActivationCheckWaitTime;

private:
	ASpyValueGASTestActor* TargetActor;
	float StepTimer;

	// Returns whether the caller should finish the step
	bool WaitForActivationConfirmation(float DeltaTime);
};