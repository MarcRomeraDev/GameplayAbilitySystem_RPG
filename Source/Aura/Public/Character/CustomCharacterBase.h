// Copyright Romera

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CustomCharacterBase.generated.h"

UCLASS(Abstract)
class AURA_API ACustomCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	ACustomCharacterBase();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category="Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;;

public:
	

};
