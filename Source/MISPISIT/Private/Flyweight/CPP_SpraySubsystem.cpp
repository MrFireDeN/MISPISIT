// Fill out your copyright notice in the Description page of Project Settings.


#include "Flyweight/CPP_SpraySubsystem.h"

const FCPP_SprayPattern* UCPP_SpraySubsystem::GetSprayPattern(const ESprayType Type) const
{
	if (Type == ESprayType::MAX)
	{
		return nullptr;
	}

	return SprayPatterns[static_cast<uint32>(Type)].Get();
}

void UCPP_SpraySubsystem::PostInitialize()
{
	Super::PostInitialize();
	
	SprayPatterns.Reserve(Count);

	for (uint8 i = 0; i < Count; ++i)
	{
		ESprayType CurrentType = static_cast<ESprayType>(i);
    
		switch (CurrentType)
		{
		case ESprayType::AssaultRifle:
			SprayPatterns.Add(MakeShared<FCPP_SprayPattern>(1));
			UE_LOG(LogTemp, Log, TEXT("Processing Assault Rifle"));
			break;
		case ESprayType::Pistol:
			SprayPatterns.Add(MakeShared<FCPP_SprayPattern>(2));
			UE_LOG(LogTemp, Log, TEXT("Processing Pistol"));
			break;
		case ESprayType::Shotgun:
			SprayPatterns.Add(MakeShared<FCPP_SprayPattern>(3));
			UE_LOG(LogTemp, Log, TEXT("Processing Shotgun"));
			break;
		}
	}
}
