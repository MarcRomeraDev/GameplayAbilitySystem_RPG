// Copyright Romera

#pragma once

#include "CoreMinimal.h"
#include "Character/CustomCharacterBase.h"
#include "MainCharacter.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AMainCharacter : public ACustomCharacterBase
{
	GENERATED_BODY()
public:
	AMainCharacter();
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;
private:
	void InitAbilityActorInfo();
};
