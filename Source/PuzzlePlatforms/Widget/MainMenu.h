// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "MenuInterface.h"
#include "MenuWidget.h"

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API UMainMenu : public UMenuWidget
{
	GENERATED_BODY()

protected:
	virtual bool Initialize();

private:
	UPROPERTY(meta = (BindWidget))
		class UWidgetSwitcher* MenuSwitcher;

	UPROPERTY(meta = (BindWidget))
		UWidget* MainMenuWidget;

	UPROPERTY(meta = (BindWidget))
		class UButton* HostButton;

	UPROPERTY(meta = (BindWidget))
		UButton* JoinButton;

	UPROPERTY(meta = (BindWidget))
		UWidget* JoinMenuWidget;

	UPROPERTY(meta = (BindWidget))
		UButton* JoinButton2;

	UPROPERTY(meta = (BindWidget))
		UButton* CancelJoinMenuButton;

	UPROPERTY(meta = (BindWidget))
		class UEditableTextBox* IPAddressField;

	UPROPERTY(meta = (BindWidget))
		UButton* QuitGame;

	UFUNCTION()
		void HostServer();

	UFUNCTION()
		void GoJoinMenu();

	UFUNCTION()
		void BackMainMenu();

	UFUNCTION()
		void JoinClient();

	UFUNCTION()
		void QuitClicked();


public:
	virtual void OnLevelRemovedFromWorld(ULevel* InLevel, UWorld* InWorld) override;
};
