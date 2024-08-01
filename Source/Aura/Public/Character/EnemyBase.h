// Copyright Romera

#pragma once

#include "CoreMinimal.h"
#include "Character/CustomCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "EnemyBase.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AEnemyBase : public ACustomCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()
public:
	AEnemyBase();

#pragma region Enemy Interface
	
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	
#pragma endregion

protected:
	virtual void BeginPlay() override;
};
