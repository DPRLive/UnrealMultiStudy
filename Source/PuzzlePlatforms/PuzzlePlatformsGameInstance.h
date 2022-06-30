// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Widget/MenuInterface.h"
#include "Widget/MainMenu.h"
#include "Widget/MenuWidget.h"

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Blueprint/UserWidget.h"
#include "PuzzlePlatformsGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API UPuzzlePlatformsGameInstance : public UGameInstance, public IMenuInterface
{
	GENERATED_BODY()
	
public:
	UPuzzlePlatformsGameInstance(const FObjectInitializer& ObjectInitializer);
	virtual void Init();

	UFUNCTION(Exec)
		virtual void Join(const FString& Address) override;

	UFUNCTION(BlueprintCallable)
		void LoadMenu();

	UFUNCTION(BlueprintCallable)
		void LoadInGameMenu();

	UFUNCTION(Exec)
		virtual void Host() override;

	virtual void LoadMainMenu() override;
	virtual void QuitAGame() override;
private:
	TSubclassOf<UUserWidget> MainMenu;
	TSubclassOf<UUserWidget> InGameMenu;
};
