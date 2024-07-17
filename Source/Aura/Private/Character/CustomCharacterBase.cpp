// Copyright Romera


#include "Character/CustomCharacterBase.h"


ACustomCharacterBase::ACustomCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(),FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void ACustomCharacterBase::BeginPlay()
{
	Super::BeginPlay();
}
