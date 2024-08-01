// Copyright Romera


#include "Player/CustomPlayerState.h"

#include "AbilitySystem/CustomAbilitySystemComponent.h"
#include "AbilitySystem/CustomAttributeSet.h"
#include "Aura/Aura.h"

ACustomPlayerState::ACustomPlayerState()
{
	NetUpdateFrequency = PLAYER_STATE_NET_UPDATE_RATE;	// How often the server will update clients

	AbilitySystemComponent = CreateDefaultSubobject<UCustomAbilitySystemComponent>("Ability System Component");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	

	AttributeSet = CreateDefaultSubobject<UCustomAttributeSet>("Attribute Set");
}

UAbilitySystemComponent* ACustomPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
