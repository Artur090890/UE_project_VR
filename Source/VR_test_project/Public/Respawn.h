
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Respawn.generated.h"

UCLASS()
class VR_TEST_PROJECT_API ARespawn : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARespawn();
	UFUNCTION(BlueprintCallable)
		void  OpenLevels(FName data);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


};
