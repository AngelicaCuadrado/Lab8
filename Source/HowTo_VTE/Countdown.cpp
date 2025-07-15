// Fill out your copyright notice in the Description page of Project Settings.

#include "Countdown.h"
#include "HowTo_VTE.h"
#include "Components/TextRenderComponent.h"

ACountdown::ACountdown()
{
    PrimaryActorTick.bCanEverTick = false;

    // Create the text component and make it the root
    CountdownText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("CountdownNumber"));
    RootComponent = CountdownText;

    CountdownText->SetHorizontalAlignment(EHTA_Center);
    CountdownText->SetWorldSize(150.0f);

    CountdownTime = 3;
}

void ACountdown::BeginPlay()
{
    Super::BeginPlay();
    UpdateTimerDisplay();
    GetWorldTimerManager().SetTimer(
        CountdownTimerHandle,
        this,
        &ACountdown::AdvanceTimer,
        1.0f,
        true
    );
}

void ACountdown::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void ACountdown::UpdateTimerDisplay()
{
    CountdownText->SetText(
        FText::AsNumber(FMath::Max(CountdownTime, 0))
    );
}

void ACountdown::AdvanceTimer()
{
    --CountdownTime;
    UpdateTimerDisplay();

    if (CountdownTime < 1)
    {
        GetWorldTimerManager().ClearTimer(CountdownTimerHandle);
        CountdownHasFinished();
    }
}

void ACountdown::CountdownHasFinished_Implementation()
{
    CountdownText->SetText(FText::FromString(TEXT("GO!")));
}
