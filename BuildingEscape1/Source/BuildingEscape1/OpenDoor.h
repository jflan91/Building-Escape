#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDoorEvent);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE1_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	UOpenDoor();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintAssignable)
	FDoorEvent OnOpen;

	UPROPERTY(BlueprintAssignable)
	FDoorEvent OnClose;

protected:

	virtual void BeginPlay() override;
	 
	

private:
	UPROPERTY(EditAnywhere)
	float TriggerMass = 50.f;
	
	float GetTotalMassOfActorsOnPlate();
	AActor* Owner = nullptr;

	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate = nullptr;


		
	
};
