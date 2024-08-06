// Copyright Romera

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "CustomHUD.generated.h"

class UCustomUserWidget;
/**
 * 
 */
UCLASS()
class AURA_API ACustomHUD : public AHUD
{
	GENERATED_BODY()
public:

	UPROPERTY()
	TObjectPtr<UCustomUserWidget> OverlayWidget;
protected:
	virtual void BeginPlay() override;
private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UCustomUserWidget> OverlayWidgetClass;
};
