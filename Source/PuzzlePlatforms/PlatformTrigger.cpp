// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformTrigger.h"
#include "Components/BoxComponent.h"
#include "MovingPlatform.h"
// Sets default values
APlatformTrigger::APlatformTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TriggerVolume =CreateDefaultSubobject<UBoxComponent>(FName("TriggerVolume"));
	if (!ensure(TriggerVolume != nullptr)) return;
	RootComponent = TriggerVolume;
	// 델리게이트 바인딩 (보통 Begin Play에서 함)
	TriggerVolume->OnComponentBeginOverlap.AddDynamic(this, &APlatformTrigger::OnMyComponentBeginOverlap);
	TriggerVolume->OnComponentEndOverlap.AddDynamic(this, &APlatformTrigger::OnMyComponentEndOverlap);

}

// Called when the game starts or when spawned
void APlatformTrigger::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlatformTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlatformTrigger::OnMyComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Activated"));
	for (AMovingPlatform* MovingPlatform : PlatformsToTrigger)
	{
		MovingPlatform->AddActiveTrigger();
	}

}

void APlatformTrigger::OnMyComponentEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp, Warning, TEXT("DeActivated"));
	for (AMovingPlatform* MovingPlatform : PlatformsToTrigger)
	{
		MovingPlatform->RemoveActiveTrigger();
	}

}

