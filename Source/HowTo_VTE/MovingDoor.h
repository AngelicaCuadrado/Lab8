// MovingDoor.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingDoor.generated.h"

UCLASS()
class HOWTO_VTE_API AMovingDoor : public AActor
{
	GENERATED_BODY()

public:
	AMovingDoor();

protected:
	virtual void BeginPlay() override;

	// The mesh to move (you’ll assign in Blueprint)
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* DoorMesh;

	// Where to move TO (world-space)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	FTransform TargetTransform;

	// How long the move takes
	UPROPERTY(EditAnywhere, Category = "Movement", meta = (ClampMin = "0.1"))
	float MoveDuration = 1.0f;

private:
	// Handle for scheduling the return
	FTimerHandle ReturnTimerHandle;

	// Save the original transform
	FTransform InitialTransform;

public:
	// Kicks off the move to TargetTransform
	UFUNCTION(BlueprintCallable, Category = "Movement")
	void ActivateDoor();

	// Moves back to InitialTransform
	UFUNCTION(BlueprintCallable, Category = "Movement")
	void ResetDoor();

	// Implement the actual motion in Blueprints (Timelines, lerps, etc.)
	UFUNCTION(BlueprintImplementableEvent, Category = "Movement")
	void OnActivateDoor();

	UFUNCTION(BlueprintImplementableEvent, Category = "Movement")
	void OnResetDoor();
};