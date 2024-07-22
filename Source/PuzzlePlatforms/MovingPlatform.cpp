// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform() 
{
	PrimaryActorTick.bCanEverTick = true;
	SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	if (HasAuthority())
	{
		SetReplicates(true); //대상 복제
		SetReplicateMovement(true); //대상 움직임 복제 
	};
	GlobalStartLocation = GetActorLocation();
	GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation); //GetTransform().TransformPosition <<- 로컬->글로벌 트랜스폼으로 변경시킴 
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (ActiveTriggers > 0) {
		if (HasAuthority())
		{
			FVector Location = GetActorLocation();
			float JourneyLength = (GlobalTargetLocation - GlobalStartLocation).Size();
			float JourneyTraveled = (Location - GlobalStartLocation).Size();

			if (JourneyTraveled > JourneyLength)
			{
				FVector temp = GlobalTargetLocation;
				GlobalTargetLocation = GlobalStartLocation;
				GlobalStartLocation = temp;
			}
			FVector Direction = (GlobalTargetLocation - GlobalStartLocation).GetSafeNormal();
			Location += Direction * Speed * DeltaTime;
			SetActorLocation(Location);
		}
	}
}

void AMovingPlatform::AddActiveTrigger()
{
		 ActiveTriggers++;

}

void AMovingPlatform::RemoveActiveTrigger()
{
	if(ActiveTriggers>0)
		ActiveTriggers--;
}
