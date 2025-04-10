// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPP_FSprayPattern.h"
#include "Subsystems/WorldSubsystem.h"
#include "CPP_SpraySubsystem.generated.h"

/**
 * 
 */
UCLASS()
class MISPISIT_API UCPP_SpraySubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	const FCPP_SprayPattern* GetSprayPattern(const ESprayType Type) const;

protected:
	virtual void PostInitialize() override;

private:
	uint8 Count = static_cast<uint8>(ESprayType::MAX);
	
	TArray<TSharedPtr<FCPP_SprayPattern>, TInlineAllocator<3>> SprayPatterns;
};
