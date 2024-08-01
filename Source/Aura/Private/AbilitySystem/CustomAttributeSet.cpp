// Copyright Romera


#include "AbilitySystem/CustomAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "Net/UnrealNetwork.h"

#define DECLARE_NOTIFY_GAMEPLAY_ATTRIBUTE(Attribute)\
void UCustomAttributeSet::OnRep_##Attribute(const FGameplayAttributeData& Old##Attribute) const \
{ GAMEPLAYATTRIBUTE_REPNOTIFY(UCustomAttributeSet, ##Attribute, Old##Attribute);}

UCustomAttributeSet::UCustomAttributeSet()
{
}

void UCustomAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	// Its registering health to be replicated, without any conditions and if the value is set in the server, even if is the same value, it will be updated on the clients
	DOREPLIFETIME_CONDITION_NOTIFY(UCustomAttributeSet, Health, COND_None,REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCustomAttributeSet, MaxHealth, COND_None,REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCustomAttributeSet, Mana, COND_None,REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UCustomAttributeSet, MaxMana, COND_None,REPNOTIFY_Always);
}
DECLARE_NOTIFY_GAMEPLAY_ATTRIBUTE(Health)
DECLARE_NOTIFY_GAMEPLAY_ATTRIBUTE(MaxHealth)
DECLARE_NOTIFY_GAMEPLAY_ATTRIBUTE(Mana)
DECLARE_NOTIFY_GAMEPLAY_ATTRIBUTE(MaxMana)

