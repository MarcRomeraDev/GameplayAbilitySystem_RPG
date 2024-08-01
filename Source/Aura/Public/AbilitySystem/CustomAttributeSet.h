// Copyright Romera

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "CustomAttributeSet.generated.h"


#define DECLARE_NEW_ATTRIBUTE(Name,CategoryName)\
UPROPERTY(BlueprintReadOnly,ReplicatedUsing = OnRep_##Name, Category = CategoryName)\
FGameplayAttributeData Name;\
UFUNCTION()\
void OnRep_##Name(const FGameplayAttributeData& Old##Name) const;

UCLASS()
class AURA_API UCustomAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
public:
	UCustomAttributeSet();
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	DECLARE_NEW_ATTRIBUTE(Health,"Vital Attributes")
	DECLARE_NEW_ATTRIBUTE(MaxHealth,"Vital Attributes")
	DECLARE_NEW_ATTRIBUTE(Mana,"Vital Attributes")
	DECLARE_NEW_ATTRIBUTE(MaxMana,"Vital Attributes")
};
