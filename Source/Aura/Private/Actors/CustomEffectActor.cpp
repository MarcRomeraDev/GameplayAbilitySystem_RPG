// Copyright Romera


#include "Actors/CustomEffectActor.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystem/CustomAttributeSet.h"
#include "Components/SphereComponent.h"
ACustomEffectActor::ACustomEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);
	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	Sphere->SetupAttachment(GetRootComponent());
}

void ACustomEffectActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& HitResult)
{
	// TODO: Change this to apply a Gameplay Effect, For now, using const_cast as a hack!
	if(IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(OtherActor))
	{
		const UCustomAttributeSet* AttributeSet= Cast<UCustomAttributeSet>(ASCInterface->GetAbilitySystemComponent()->GetAttributeSet(UCustomAttributeSet::StaticClass()));
		UCustomAttributeSet* MutableAttributeSet= const_cast<UCustomAttributeSet*>(AttributeSet);
		MutableAttributeSet->SetHealth(AttributeSet->GetHealth() + 25.f);
		Destroy();
	}
}

void ACustomEffectActor::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	
}


void ACustomEffectActor::BeginPlay()
{
	Super::BeginPlay();
	Sphere->OnComponentBeginOverlap.AddDynamic(this,&ACustomEffectActor::OnOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this,&ACustomEffectActor::EndOverlap);
}

