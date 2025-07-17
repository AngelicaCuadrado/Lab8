// MovingDoor.cpp

#include "MovingDoor.h"
#include "Components/StaticMeshComponent.h"
#include "TimerManager.h"

AMovingDoor::AMovingDoor()
{
    PrimaryActorTick.bCanEverTick = false;

    DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorMesh"));
    RootComponent = DoorMesh;
}

void AMovingDoor::BeginPlay()
{
    Super::BeginPlay();
    InitialTransform = GetActorTransform();
}

void AMovingDoor::ActivateDoor()
{
    // Trigger Blueprint timeline to animate door open
    OnActivateDoor();

    // After MoveDuration, schedule ResetDoor
    GetWorld()->GetTimerManager().SetTimer(
        ReturnTimerHandle,
        this,
        &AMovingDoor::ResetDoor,
        MoveDuration,
        false
    );
}

void AMovingDoor::ResetDoor()
{
    OnResetDoor();
}