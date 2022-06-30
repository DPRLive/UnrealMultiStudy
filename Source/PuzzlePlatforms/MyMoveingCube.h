// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MyMoveingCube.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API AMyMoveingCube : public AStaticMeshActor
{
	GENERATED_BODY()
	
public:
	AMyMoveingCube();

	void AddActivePlatforms();
	void RemoveActivePlatforms();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere)
		float Speed;

	UPROPERTY(EditAnywhere, Meta = (MakeEditWidget = true))
		FVector TargetLocation;

	FVector GlobalStartLocation;
	FVector GlobalTargetLocation;

	UPROPERTY(EditAnywhere)
		int ActiveTriggers = 1; // ���� active�ϰ� �ִ� �÷����� ��, �⺻ 1�� �����Ͽ� �÷����� ��� ���Ҷ��� �����ϼ� �ֵ�����.
};
