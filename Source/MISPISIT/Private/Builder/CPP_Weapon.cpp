// CPP_Weapon.cpp

#include "Builder/CPP_Weapon.h"

ACPP_Weapon::ACPP_Weapon()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetActorScale3D(FVector(0.5));
}
