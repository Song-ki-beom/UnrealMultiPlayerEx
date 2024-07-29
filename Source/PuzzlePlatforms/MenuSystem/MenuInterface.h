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
	�������̽��� �Լ��� pure virtual(= 0) �ϰ� ���� �ش� �������̽� Ŭ�������� ������ ���� �ʾƵ� �ǰ� ����, �� �������̽��� implement �ϴ� �Լ������� ����� ������

	�⺻������  C++ �� Implementation �� �������� �ʰ�(Java�� O), ���߻���� �����ϱ� ������  Abstract Class �� ����Ͽ� �������̽� ��ɰ� ����ϰ� ����Ѵ�.

	Abstract Ŭ������ ���� Abstract Class �θ� �����Ǿ� �ִ� Ŭ�����̴� 
	*/


public:
	virtual void  Host()=0; 
	virtual void Join(const FString& Address)=0;
	
};
