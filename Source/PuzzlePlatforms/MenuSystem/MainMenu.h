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
	UMainMenu(const FObjectInitializer& ObjectInitializer);  
	void SetMenuInterface(IMenuInterface* MenuInterfaces);

	void SetUp();
	void TearDown();

protected:
	virtual bool Initialize();

private:
	UFUNCTION()
		void HostServer();
	UFUNCTION()
		void JoinServer();
	UFUNCTION()
		void OpenJoinMenu();
	UFUNCTION()
		void OpenMainMenu();
	UFUNCTION()
		void QuitPressed();

private:
		TSubclassOf<class UUserWidget> ServerRowClass;

		UPROPERTY(meta = (BindWidget))
			class UButton* HostButton;
		UPROPERTY(meta = (BindWidget))
			class UButton* JoinButton;
		UPROPERTY(meta = (BindWidget))
			class UPanelWidget* ServerList;
		UPROPERTY(meta = (BindWidget))
			class UButton* QuitButton;
		UPROPERTY(meta = (BindWidget))
			class UButton* CancelJoinMenuButton;
		UPROPERTY(meta = (BindWidget))
			class UButton* ConfirmJoinMenuButton;
		UPROPERTY(meta = (BindWidget))
			class UWidgetSwitcher* MenuSwitcher;
		UPROPERTY(meta = (BindWidget))
			class UWidget* JoinMenu;
		UPROPERTY(meta = (BindWidget))
			class UWidget* MainMenu;
		IMenuInterface* MenuInterface;

};
