// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuInterface.h"
#include "MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API UMainMenu : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetMenuInterface(IMenuInterface* MenuInterfaces);

	void SetUp();
	void TearDown();


protected:
	virtual bool Initialize();
private:
		UPROPERTY(meta = (BindWidget))
		class UButton* Host;
		UPROPERTY(meta = (BindWidget))
			class UButton* Join;
		UFUNCTION()
			void HostServer();

		IMenuInterface* MenuInterface;
};
