// Copyright Romera


#include "UI/Widget/CustomUserWidget.h"

void UCustomUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}
