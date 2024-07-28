// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MenuSystem/MenuInterface.h"
#include "PuzzlePlatformGameInstance.generated.h"

/**
 * 
 */

//FclassFinder :FClassFinder는 컴파일 타임에 에셋을 찾고 로드할 때 사용하는 템플릿 클래스 

UCLASS()
class PUZZLEPLATFORMS_API UPuzzlePlatformGameInstance : public UGameInstance, public IMenuInterface 
{
	GENERATED_BODY()


public:		UPuzzlePlatformGameInstance
	  (
		  const FObjectInitializer& ObjectInitializer
	  );
	virtual void Init();


	UFUNCTION(BlueprintCallable)
		void LoadMenu();



		
	UFUNCTION(Exec) //Exec : 게임 내 콘솔이나 개발자 명령을 통해 직접 호출할 수 있는 함수를 정의 , GameInstance에서 호출 가능 
		void Host();

	UFUNCTION(Exec)
		void Join(const FString& Address);

private:
	TSubclassOf<class UUserWidget> MenuClass;
	class UMainMenu* Menu;
};
