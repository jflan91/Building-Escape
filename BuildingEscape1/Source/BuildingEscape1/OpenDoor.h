#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE1_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	UOpenDoor();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	

protected:
	void OpenDoor();
	void CloseDoor();
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere)
	float OpenAngle = 90.0f;
	
	UPROPERTY(EditAnywhere)
	float DoorCloseDelay = 1.f;

	float LastDoorOpenTime;
	float GetTotalMassOfActorsOnPlate();
	AActor* Owner = nullptr;

	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate = nullptr;


		
	
};
