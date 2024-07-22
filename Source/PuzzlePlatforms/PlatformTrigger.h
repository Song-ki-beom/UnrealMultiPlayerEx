// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlatformTrigger.generated.h"

UCLASS()
class PUZZLEPLATFORMS_API APlatformTrigger : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlatformTrigger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// 바인딩(Binding)할 함수. 이름 바꿔도 됨
	UFUNCTION()	// 델리게이트 함수는 지정자 필수
		void OnMyComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()	// 델리게이트 함수는 지정자 필수
		void OnMyComponentEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

private:
	UPROPERTY(VisibleAnywhere)
		class UBoxComponent* TriggerVolume;

	UPROPERTY(EditAnywhere)
		TArray<class AMovingPlatform*> PlatformsToTrigger;




};
