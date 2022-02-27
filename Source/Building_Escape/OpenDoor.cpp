// Copyright Pragun Mangla 2022


#include "OpenDoor.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	
	// FRotator CurrentRotation = GetOwner()->GetActorRotation();
	// CurrentRotation.Yaw += 90;
	// GetOwner()->SetActorRotation(CurrentRotation);

	
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	UE_LOG(LogTemp, Warning, TEXT("%s"), *GetOwner()->GetActorRotation().ToString());
	UE_LOG(LogTemp, Warning, TEXT("Yaw is : %f"), GetOwner()->GetActorRotation().Yaw);

	float CurrentYaw = GetOwner()->GetActorRotation().Yaw;
	FRotator OpenDoor(0.f,CurrentYaw,0.f);
	// CurrentYaw yaw, target yaw, 0-1 (for % increase open);
	OpenDoor.Yaw = FMath:: FInterpTo(CurrentYaw, TargetYaw, DeltaTime, 2);
	GetOwner()->SetActorRotation(OpenDoor);
	// ...
}

