// Copyright Epic Games, Inc. All Rights Reserved.

#include "PVZ_USFX_LAB01GameMode.h"
#include "PVZ_USFX_LAB01Pawn.h"
#include "Zombie.h"
#include "Plant.h"
#include "Math/UnrealMathUtility.h" // Necesario para FMath


APVZ_USFX_LAB01GameMode::APVZ_USFX_LAB01GameMode()
{
	PrimaryActorTick.bCanEverTick = true;
	// set default pawn class to our character class
	DefaultPawnClass = APVZ_USFX_LAB01Pawn::StaticClass();

	TiempoTranscurrido = 0.0f;
}

void APVZ_USFX_LAB01GameMode::BeginPlay()
{
	Super::BeginPlay();

	// Lugar donde quieras crear la instancia del objeto de planta
	//FVector SpawnLocation1 = FVector(-850.0f, 400.0f, 160.0f); // Cambia las coordenadas según tus necesidades

	//AZombie* NewZombieActor1 = GetWorld()->SpawnActor<AZombie>(AZombie::StaticClass(), SpawnLocation1, FRotator::ZeroRotator);

	//FVector SpawnLocation2 = FVector(-500.0f, 200.0f, 160.0f); // Cambia las coordenadas según tus necesidades

	//AZombie* NewZombieActor2 = GetWorld()->SpawnActor<AZombie>(AZombie::StaticClass(), SpawnLocation2, FRotator::ZeroRotator);
	//

	//// Lugar donde quieras crear la instancia del objeto
	//FVector MinSpawnLocation = FVector(-1000.0f, -1000.0f, 0.0f);
	//FVector MaxSpawnLocation = FVector(1000.0f, 1000.0f, 0.0f);

	//float RandomX = FMath::RandRange(MinSpawnLocation.X, MaxSpawnLocation.X);
	//float RandomY = FMath::RandRange(MinSpawnLocation.Y, MaxSpawnLocation.Y);
	//float Z = 180.0f; // Altura en Z

	//FVector SpawnLocation = FVector(RandomX, RandomY, Z);

	//AZombie* NewZombieActor3 = GetWorld()->SpawnActor<AZombie>(AZombie::StaticClass(), SpawnLocation, FRotator::ZeroRotator);



	FVector SpawnLocationZombie = FVector(-800.0f, 400.0f, 160.0f); 
	
	// Crear objetos y agregarlos al vector
	// Se crean los Zombies dinamicamente
	for (int i = 0; i < 5; i++) {
		SpawnLocationZombie.X += 100;
		AZombie* NuevoZombie = GetWorld()->SpawnActor<AZombie>(AZombie::StaticClass(), SpawnLocationZombie, FRotator::ZeroRotator);
		NuevoZombie->MovementSpeed = 0.02f;
		vectorZombies.Add(NuevoZombie);
	}

	//Se crean las plantas dinamicamente
	FVector SpawnLocationPlant = FVector(-800.0f, -600.0f, 160.0f);
	FVector SpawnLocationPlantTemp = SpawnLocationPlant;
	FString PlantName;

		
	for (int i = 0; i < 5; i++) {
		SpawnLocationPlantTemp.X += 100;
		for (int j = 0; j < 2; j++) {
			SpawnLocationPlantTemp.Y += 80;
			APlant* NuevoPlant = GetWorld()->SpawnActor<APlant>(APlant::StaticClass(), SpawnLocationPlantTemp, FRotator::ZeroRotator);
			PlantName = FString::Printf(TEXT("Plant%d_%d"), i, j); // Crear una clave única para cada planta
			vectorPlants.Add(PlantName , NuevoPlant);
		//	SpawnLocationPlant = SpawnLocationPlantTemp;
		}
		SpawnLocationPlantTemp.Y = SpawnLocationPlant.Y;
	}




}


void APVZ_USFX_LAB01GameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TiempoTranscurrido += DeltaTime;

	if (TiempoTranscurrido > 2.0f) {
		// Iterar sobre el vector de objetos
		for (int i = 0; i < vectorZombies.Num(); i++) {
			vectorZombies[i]->MovementSpeed = FMath::FRand() * 0.1f;
			//vectorZombies[i]->MovementSpeed += i * 1.0f;
		}
		TiempoTranscurrido = 0.0f;
	}

}

void APVZ_USFX_LAB01GameMode::ChangeEnergyRandomly()
{
	// Define el rango de energía aleatoria (ajusta estos valores según tus necesidades)
	float MinEnergy = 0.0f;
	float MaxEnergy = 100.0f;

	// Genera un valor de energía aleatorio dentro del rango
	float NewEnergy = FMath::FRandRange(MinEnergy, MaxEnergy);

	// Aplica el nuevo valor de energía a la planta
	Energy = NewEnergy;
	
}

//// Called when the game starts or when spawned
//void APVZ_USFX_LAB01GameMode::BeginPlay()
//{
//	Super::BeginPlay();
//
//}

