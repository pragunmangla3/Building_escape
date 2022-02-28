// Copyright Pragun Mangla 2022

#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
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
	if(!PressurePlate){
		UE_LOG(LogTemp, Warning, TEXT("%s has OpenDoor component on it, but no pressurePlate set"), *GetOwner()->GetName())
	}

	InitialYaw = GetOwner()->GetActorRotation().Yaw;
	ActorThatOpen = GetWorld()->GetFirstPlayerController()->GetPawn();
	

}




// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if(PressurePlate && PressurePlate->IsOverlappingActor(ActorThatOpen )){
		OpenDoor(DeltaTime);
	}
	else{
		CloseDoor(DeltaTime);
	}

	


	// ...
}

void UOpenDoor::OpenDoor(float DeltaTime){

	float CurrentYaw = GetOwner()->GetActorRotation().Yaw;
	FRotator DoorRotation(0.f,CurrentYaw,0.f);
	// CurrentYaw yaw, target yaw, 0-1 (for % increase open);
	DoorRotation.Yaw = FMath:: FInterpTo(CurrentYaw, InitialYaw + TargetYaw, DeltaTime, 2);
	GetOwner()->SetActorRotation(DoorRotation);

}

void UOpenDoor::CloseDoor(float DeltaTime){

	float CurrentYaw = GetOwner()->GetActorRotation().Yaw;
	FRotator DoorRotation(0.f,CurrentYaw,0.f);
	// CurrentYaw yaw, target yaw, 0-1 (for % increase open);
	DoorRotation.Yaw = FMath:: FInterpTo(CurrentYaw, InitialYaw, DeltaTime, 4);
	GetOwner()->SetActorRotation(DoorRotation);

}
