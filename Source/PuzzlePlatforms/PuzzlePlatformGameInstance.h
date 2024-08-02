// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MenuSystem/MenuInterface.h"
#include "PuzzlePlatformGameInstance.generated.h"

/**
 * 
 */

//FclassFinder :FClassFinder�� ������ Ÿ�ӿ� ������ ã�� �ε��� �� ����ϴ� ���ø� Ŭ���� 

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



		
	UFUNCTION(Exec) 
		void Host();

	UFUNCTION(Exec)
		void Join(const FString& Address);

private:
	TSubclassOf<class UUserWidget> MenuClass;
	class UMainMenu* Menu;
};
