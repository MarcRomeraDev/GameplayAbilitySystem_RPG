// Copyright Romera


#include "CustomCharacterBase.h"

// Sets default values
ACustomCharacterBase::ACustomCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACustomCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACustomCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACustomCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

