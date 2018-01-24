#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE1_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	UGrabber();

protected:
	virtual void BeginPlay() override;
	void FindInputComponent();
	void FindPhysicsComponent();

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	float Reach = 100.f;
	UPhysicsHandleComponent* PhysicsHandle = nullptr;
	UInputComponent* InputComponent = nullptr;
	void Grab();
	void Release();
	const FHitResult GetFirstPhysicsBodyInReach();
	FVector GetReachLineEnd();
	FVector GetReachLineStart();
};
