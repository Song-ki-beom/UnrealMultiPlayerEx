// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu.h"
#include "Components/Button.h"


void UMainMenu::SetMenuInterface(IMenuInterface* MenuInterfaces)
{
	this->MenuInterface = MenuInterfaces;


}
void UMainMenu::SetUp()
{
	this->AddToViewport();

	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	APlayerController* PlayerController = World->GetFirstPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	FInputModeUIOnly InputModeData;
	InputModeData.SetWidgetToFocus(this->TakeWidget());
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

	PlayerController->SetInputMode(InputModeData);
	PlayerController->bShowMouseCursor = true;
	

}
void UMainMenu::TearDown()
{
	this->RemoveFromViewport();

	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	APlayerController* PlayerController = World->GetFirstPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	FInputModeGameOnly InputModeData;//Default
	PlayerController->SetInputMode(InputModeData);
	PlayerController->bShowMouseCursor = true;


}
bool UMainMenu::Initialize() {
	bool Success = Super::Initialize();
	if (!Success) return false;

	if (!ensure(Host != nullptr)) return false;
	Host->OnClicked.AddDynamic(this, &UMainMenu::HostServer);
	// Todo : Setup

	return true;
}

void UMainMenu::HostServer()
{
	if (MenuInterface != nullptr)
	{
		MenuInterface->Host();
	}
}
