// Fill out your copyright notice in the Description page of Project Settings.


#include "PuzzlePlatformGameInstance.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"
#include "PlatformTrigger.h"
#include "Engine/Engine.h"
#include "Widgets/SWidget.h"
#include "MenuSystem/MainMenu.h"
#include "GameFramework/PlayerController.h"
#include "OnlineSessionSettings.h"
#include "Interfaces/OnlineSessionInterface.h"

const static FName SESSION_NAME = TEXT("My Session Game");

UPuzzlePlatformGameInstance::UPuzzlePlatformGameInstance(const FObjectInitializer& ObjectInitializer) 
{
	static ConstructorHelpers::FClassFinder<UUserWidget> MenuBPClass(TEXT("/Game/MenuSystem/WBP_MainMenu"));
	if (!ensure(MenuBPClass.Class != nullptr)) return;

	MenuClass = MenuBPClass.Class;

	


}

void UPuzzlePlatformGameInstance::Init()
{
	IOnlineSubsystem* Subsystem = IOnlineSubsystem::Get();
	
	if (Subsystem != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Found Subsystem %s"), *Subsystem->GetSubsystemName().ToString());
		SessionInterface = Subsystem->GetSessionInterface();
		SessionInterface->OnCreateSessionCompleteDelegates.AddUObject(this, &UPuzzlePlatformGameInstance::OnCreateSessionComplete);
		SessionInterface->OnDestroySessionCompleteDelegates.AddUObject(this, &UPuzzlePlatformGameInstance::OnDestroySessionComplete);

		// c++ raw 포인터를 TShared 포인터 (참조 카운트) 형식으로 바꿈 
		SessionSearch = MakeShareable(new FOnlineSessionSearch());
		if (SessionSearch.IsValid())
		{

			//세션 find 시작 
			UE_LOG(LogTemp, Warning, TEXT("Starting Find Session"));
			SessionSearch->bIsLanQuery = true;
			SessionInterface->FindSessions(0, SessionSearch.ToSharedRef());
			SessionInterface->OnFindSessionsCompleteDelegates.AddUObject(this, &UPuzzlePlatformGameInstance::OnFindSessionsComplete);
		}
	}

	else 
	{
		UE_LOG(LogTemp, Warning, TEXT("Found no Subsystem"));

	}


	

}

void UPuzzlePlatformGameInstance::LoadMenu()
{
	if (!ensure(MenuClass != nullptr)) return;

	Menu = CreateWidget<UMainMenu>(this, MenuClass);
	if (!ensure(Menu != nullptr)) return;

	

	Menu->SetUp();
	Menu->SetMenuInterface(this);

}

void UPuzzlePlatformGameInstance::Host()
{
	if (SessionInterface.IsValid()) 
	{
		auto ExistingSession = SessionInterface->GetNamedSession(SESSION_NAME);
		if (ExistingSession != nullptr)
		{
			SessionInterface->DestroySession(SESSION_NAME);
		}
		else
		{
			CreateSession();

		}
		
	}
	
}



void UPuzzlePlatformGameInstance::OnCreateSessionComplete(FName SessionName, bool Success)
{
	if (!Success)
	{
		UE_LOG(LogTemp, Warning, TEXT("Could Not Create Sessionnnnnnnnnnn!"));
		return;
	}

	if (Menu != nullptr)
	{
		Menu->TearDown();
	}

	UEngine* Engine = GetEngine();
	if (!ensure(Engine != nullptr)) return;
	Engine->AddOnScreenDebugMessage(0, 5.f, FColor::Green, TEXT("This is host"));

	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	World->ServerTravel("/Game/ThirdPersonCPP/Maps/ThirdPersonExampleMap?listen"); 


	
	

}

void UPuzzlePlatformGameInstance::OnDestroySessionComplete(FName SessionName, bool Success)
{
	if (Success)
	{
		CreateSession();
	}



}

void UPuzzlePlatformGameInstance::OnFindSessionsComplete(bool Success)
{
		if (Success && SessionSearch.IsValid())
		{
			UE_LOG(LogTemp, Warning, TEXT("Find Session Complete"));
			for  (const FOnlineSessionSearchResult& SearchResult : SessionSearch -> SearchResults)
			{
				UE_LOG(LogTemp, Warning, TEXT("Find Session names: %s"), *SearchResult.GetSessionIdStr());

			}
		}
}

void UPuzzlePlatformGameInstance::CreateSession()
{
	if (SessionInterface.IsValid()) 
	{
		FOnlineSessionSettings SessionSettings;
		SessionSettings.bIsLANMatch = true; // Lan 매칭만 설정
		SessionSettings.NumPublicConnections = 2; //세션 최대 플레이어 
		SessionSettings.bShouldAdvertise = true; // broadcast? 광고 게시 
		SessionInterface->CreateSession(0, SESSION_NAME, SessionSettings);
	}

	
}

void UPuzzlePlatformGameInstance::Join(const FString& Address)
{
	if (Menu != nullptr)
	{
		Menu->TearDown();
	}

	UEngine* Engine = GetEngine();
	if (!ensure(Engine != nullptr)) return;
	Engine->AddOnScreenDebugMessage(0, 5.f, FColor::Green, FString::Printf(TEXT("Joining %s"), *Address));

	APlayerController* PlayerController = GetFirstLocalPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	PlayerController->ClientTravel(Address, TRAVEL_Absolute);


}


