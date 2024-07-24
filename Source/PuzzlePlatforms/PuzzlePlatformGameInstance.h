// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PuzzlePlatformGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API UPuzzlePlatformGameInstance : public UGameInstance
{
	GENERATED_BODY()


public:		UPuzzlePlatformGameInstance
	  (
		  const FObjectInitializer& ObjectInitializer
	  );
	virtual void Init();
		
	UFUNCTION(Exec) //Exec : 게임 내 콘솔이나 개발자 명령을 통해 직접 호출할 수 있는 함수를 정의 , GameInstance에서 호출 가능 
		void Host();

	UFUNCTION(Exec)
		void Join(const FString& Address);

};
