// Fill out your copyright notice in the Description page of Project Settings.

#include "HorrorHouse.h"
#include "FlashLightController.h"
#define OUT

// Sets default values for this component's properties
UFlashLightController::UFlashLightController()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UFlashLightController::BeginPlay()
{
	Super::BeginPlay();

	// Find Spot Light Component
	SpotLight = GetOwner()->FindComponentByClass<ASpotLight>();

	// Get Viewport Rotation
	FVector PlayerViewPortLocation;
	FRotator PlayerViewPortRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPortLocation,
		OUT PlayerViewPortRotation);
	
	// Align Spot Light to Viewport
	SpotLight->SetActorRotation(PlayerViewPortRotation);
	
}


// Called every frame
void UFlashLightController::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

