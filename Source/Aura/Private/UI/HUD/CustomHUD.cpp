// Copyright Romera


#include "UI/HUD/CustomHUD.h"
#include "UI/Widget/CustomUserWidget.h"


void ACustomHUD::BeginPlay()
{
	Super::BeginPlay();
	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	Widget->AddToViewport();
}
