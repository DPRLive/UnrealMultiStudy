// Fill out your copyright notice in the Description page of Project Settings.

#include "MainMenu.h"

#include "Components/WidgetSwitcher.h"
#include "Components/Button.h"
#include "Components/EditableTextBox.h"

bool UMainMenu::Initialize()
{
	bool Success = Super::Initialize();
	if (!Success) return false;

	if (!ensure(HostButton != nullptr)) return false;
	HostButton->OnClicked.AddDynamic(this, &UMainMenu::HostServer);

	if (!ensure(JoinButton != nullptr)) return false;
	JoinButton->OnClicked.AddDynamic(this, &UMainMenu::GoJoinMenu);

	if (!ensure(CancelJoinMenuButton != nullptr)) return false;
	CancelJoinMenuButton->OnClicked.AddDynamic(this, &UMainMenu::BackMainMenu);

	if (!ensure(JoinButton2 != nullptr)) return false;
	JoinButton2->OnClicked.AddDynamic(this, &UMainMenu::JoinClient);

	if (!ensure(QuitGame != nullptr)) return false;
	QuitGame->OnClicked.AddDynamic(this, &UMainMenu::QuitClicked);

	return true;
}

void UMainMenu::HostServer() {
	UE_LOG(LogTemp, Warning, TEXT("HOST! HOST! HOST!"));

	if (MenuInterface == nullptr) return;
	MenuInterface->Host();
}

void UMainMenu::GoJoinMenu() {
	UE_LOG(LogTemp, Warning, TEXT("JOIN! JOIN! JOIN!"));

	if (!ensure(MenuSwitcher != nullptr)) return;
	if (!ensure(JoinMenuWidget != nullptr)) return;
	MenuSwitcher->SetActiveWidget(JoinMenuWidget);
}

void UMainMenu::BackMainMenu()
{
	if (!ensure(MenuSwitcher != nullptr)) return;
	if (!ensure(MainMenuWidget != nullptr)) return;
	MenuSwitcher->SetActiveWidget(MainMenuWidget);
}

void UMainMenu::JoinClient()
{
	if (!ensure(IPAddressField != nullptr)) return;
	if (MenuInterface == nullptr) return;
	MenuInterface->Join(IPAddressField->GetText().ToString());
}

void UMainMenu::QuitClicked()
{
	if (MenuInterface == nullptr) return;
	MenuInterface->QuitAGame();
}

void UMainMenu::OnLevelRemovedFromWorld(ULevel* InLevel, UWorld* InWorld)
{
	Teardown();
}
