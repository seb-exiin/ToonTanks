// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnBase.h"
#include "Components/CapsuleComponent.h"
#include "ToonTanks/Actors/ProjectileBase.h"

// Sets default values
APawnBase::APawnBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	RootComponent = CapsuleComp;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	BaseMesh->SetupAttachment(RootComponent);

	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret Mesh"));
	TurretMesh->SetupAttachment(BaseMesh);

	ProjectiveSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn Point"));
	ProjectiveSpawnPoint->SetupAttachment(TurretMesh);
}

void APawnBase::RotateTurret(FVector LookAtTarget)
{
	FVector LookAtTargetClean = FVector(LookAtTarget.X, LookAtTarget.Y, TurretMesh->GetComponentLocation().Z);
	FVector StartLocation = TurretMesh->GetComponentLocation();

	FRotator TurretRotation = FVector(LookAtTargetClean- StartLocation).Rotation();
	TurretMesh->SetWorldRotation(TurretRotation);

	// Update the turretMesh rotation to face toward the lookAtTarget passed in from the Child Classes
	// TurretMesh->SetWorldRotation()....
}

void APawnBase::Fire()
{
	//Get Projecttile spawnppoint location and rotation => spawn projectile class at location firing towards rotation
	if (ProjectileClass)
	{

		FVector SpawnLocation = ProjectiveSpawnPoint->GetComponentLocation();
		FRotator SpawnRotation = ProjectiveSpawnPoint->GetComponentRotation();

		AProjectileBase* TempProjectile = GetWorld()->SpawnActor<AProjectileBase>(ProjectileClass, SpawnLocation, SpawnRotation);
		TempProjectile->SetOwner(this);
	}
}

void APawnBase::HandleDestruction()
{
	// -- unversal functionality ---
	//Play death effects particles, sound and camera shake


	// ---- then do child overrides ---
	// ---- pawnTurret - Inform GameMode turret died -> then destroy() Self.


	// -- PawnTank -- nform gamemode player died -> then hide() all components and stop movement input.


}



