// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MenuInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UMenuInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class PUZZLEPLATFORMS_API IMenuInterface
{
	GENERATED_BODY()

	
	/*
	인터페이스의 함수는 pure virtual(= 0) 하게 만들어서 해당 인터페이스 클래스에서 구현을 하지 않아도 되게 만듦, 이 인터페이스를 implement 하는 함수에서는 사용이 가능함

	기본적으로  C++ 은 Implementation 을 지원하지 않고(Java는 O), 다중상속을 지원하기 때문에  Abstract Class 를 사용하여 인터페이스 기능과 비슷하게 사용한다.

	Abstract 클래스는 오직 Abstract Class 로만 구성되어 있는 클래스이다 
	*/


public:
	virtual void  Host()=0; 
	
	
};
