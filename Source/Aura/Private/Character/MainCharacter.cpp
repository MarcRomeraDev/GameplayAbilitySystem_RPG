// Copyright Romera


#include "Character/MainCharacter.h"

#include "AbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/CustomPlayerState.h"

AMainCharacter::AMainCharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f,400.f,0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false; 
}

void AMainCharacter::PossessedBy(AController* NewController) //Server
{
	Super::PossessedBy(NewController);
	// Init ability actor info for the Server here because we need to be sure that we have a valid PC ready
	InitAbilityActorInfo();
}

void AMainCharacter::OnRep_PlayerState() // Client
{
	Super::OnRep_PlayerState();
	// Init ability actor info for the client since the PS only gets changed in map loads
	InitAbilityActorInfo();
}

void AMainCharacter::InitAbilityActorInfo()
{
	ACustomPlayerState* CustomPlayerState = GetPlayerState<ACustomPlayerState>();
	check(CustomPlayerState);
	CustomPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(CustomPlayerState,this);

	AbilitySystemComponent = CustomPlayerState->GetAbilitySystemComponent();
	AttributeSet = CustomPlayerState->GetAttributeSet();
}
