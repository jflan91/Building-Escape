#include "OpenDoor.h"
#include "Gameframework/Actor.h"
#include "Engine/World.h"



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
	ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
}


void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	///poll trigger
	if (PressurePlate->IsOverlappingActor(ActorThatOpens))
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

