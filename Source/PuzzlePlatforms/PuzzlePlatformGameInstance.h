// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MenuSystem/MenuInterface.h"
#include "OnlineSubsystem.h"
#include "PuzzlePlatformGameInstance.generated.h"

/**
 * 
 */

//FclassFinder :FClassFinder는 클래스 유형의 자원 탐색(BP Actor, WBP Class) ,  FObjectFinder 는 Material,Texture , Sound, Static Mesh 와 같은 UObject 유형 
UCLASS()
class PUZZLEPLATFORMS_API UPuzzlePlatformGameInstance : public UGameInstance, public IMenuInterface 
{
	GENERATED_BODY()


public:		
	UPuzzlePlatformGameInstance
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

	//참조 카운트로 메모리가 관리되는 공유 포인터 
	//세션 생성 , 세션 찾기, 세션 참가 , 세션 소멸 등 세션의 전반적인 흐름을 관리하는 인터페이스 (SessionInterface)

	IOnlineSessionPtr SessionInterface;
	TSharedPtr<class FOnlineSessionSearch> SessionSearch;

	//콜백 함수는 특정 이벤트가 발생했을 때 자동으로 호출되는 함수, 비동기 작업과 이벤트 기반 프로그래밍에서 자주 사용
	void OnCreateSessionComplete(FName SessionName , bool Success);
	void OnDestroySessionComplete(FName SessionName, bool Success);
	void OnFindSessionsComplete(bool Success);

	void CreateSession();
};
