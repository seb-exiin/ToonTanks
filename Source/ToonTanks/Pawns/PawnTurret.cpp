// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnTurret.h"
#include "PawnTank.h"
#include "Kismet/GameplayStatics.h"

// Called when the game starts or when spawned
void APawnTurret::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &APawnTurret::CheckFireCondition, FireRate, true);

	PlayerPawn = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));
}

// Called every frame
void APawnTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!PlayerPawn || ReturnDistanceToPlayer() > FireRange)
		return;

	RotateTurret(PlayerPawn->GetActorLocation());

}

void APawnTurret::CheckFireCondition()
{
	// If Player == null || is dead then Bail!!

	if (!PlayerPawn) return;


	// If player is in range, then Fire!!
	if (ReturnDistanceToPlayer() <= FireRange) 
	{
		Fire();
	}

}

float APawnTurret::ReturnDistanceToPlayer()
{
	if (!PlayerPawn) 
	{
		return 0.0f;
	}

	return FVector::Dist(PlayerPawn->GetActorLocation(), GetActorLocation());

}

void APawnTurret::HandleDestruction()
{
	//call base pawn class handleDestruction
	Super::HandleDestruction(); 
	Destroy();

}
