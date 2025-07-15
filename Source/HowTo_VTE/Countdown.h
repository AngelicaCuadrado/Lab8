// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/TextRenderComponent.h"
#include "Countdown.generated.h"

UCLASS()
class HOWTO_VTE_API ACountdown : public AActor
{
    GENERATED_BODY()

public:
    ACountdown();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    // How long, in seconds, the countdown will run
    UPROPERTY(EditAnywhere)
    int32 CountdownTime;

    // Text component that displays the countdown
    UPROPERTY(EditAnywhere)
    UTextRenderComponent* CountdownText;

    void UpdateTimerDisplay();
    void AdvanceTimer();

    UFUNCTION(BlueprintNativeEvent)
    void CountdownHasFinished();
    virtual void CountdownHasFinished_Implementation();

    FTimerHandle CountdownTimerHandle;
};