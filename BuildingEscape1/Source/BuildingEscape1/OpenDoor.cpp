#include "OpenDoor.h"
#include "Gameframework/Actor.h"
#include "Engine/World.h"
#include "Components/PrimitiveComponent.h"
#include "Grabber.h"

#define OUT

UOpenDoor::UOpenDoor()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void UOpenDoor::OpenDoor()
{
	Owner->SetActorRotation(FRotator(0.0f, -90.0f, 0.0f));
}

void UOpenDoor::CloseDoor()
{
	Owner->SetActorRotation(FRotator(0.0f, 0.f, 0.0f));
}


void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	Owner = GetOwner();
	if (!PressurePlate)
	{
		UE_LOG(LogTemp, Error, TEXT("%s is missing a Preesure Plate"), *GetOwner()->GetName())
	}
}


void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	///poll trigger
	if (GetTotalMassOfActorsOnPlate() >= 50.f)
	{
		OpenDoor();
		LastDoorOpenTime = GetWorld()->GetTimeSeconds();
	}
	///Check if it is time to close the door
	if (GetWorld()->GetTimeSeconds() - LastDoorOpenTime >= DoorCloseDelay) 
	{
		CloseDoor();
	}


}

float UOpenDoor::GetTotalMassOfActorsOnPlate() 
{
	float TotalMass = 0.f;
	TArray<AActor*> OverlapingActors; 
	if (!PressurePlate) { return TotalMass; }
	PressurePlate->GetOverlappingActors(OUT OverlapingActors);
	for (const auto* Actor : OverlapingActors)
	{
		TotalMass += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
		UE_LOG(LogTemp, Warning, TEXT("%s on pressure plate"), *Actor->GetName());
	}
	return TotalMass;
}