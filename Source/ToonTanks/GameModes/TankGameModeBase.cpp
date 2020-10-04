// Fill out your copyright notice in the Description page of Project Settings.


#include "TankGameModeBase.h"
// Sets default values
/*
ATankGameModeBase::ATankGameModeBase()
{

}
*/
void ATankGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	//Get References and game win/Lose conditions

	//Call HandleGameStart() to initalise the start countdown, turret activation, pwan check etc...


}

void ATankGameModeBase::ActorDied(AActor* DeadActor)
{
	//Wheck waht type of actior died and respond accordingly
}

void ATankGameModeBase::HandleGameStart()
{
	//Initalize the start countdown, turret activation, pwan check etc...
	//Call Blueprint version Gamestart();
}

void ATankGameModeBase::HandleGameOver(bool PlayerWon)
{
	//See if the player has destroyed all the turrets, show win results.
	//Else if a turret destroyed the player, show lose result.
	//call brlueprint version Gameover(bool).
}


/*
void ATankGameModeBase::GameStart()
{

}

void ATankGameModeBase::GameOver(bool PlayerWon)
{

}*/