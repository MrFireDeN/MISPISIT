// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/Gameplay/MIShootingRangeSubsystem.h"

void UMIShootingRangeSubsystem::Start()
{
	if (!bIsPlaying)
	{
		bIsPlaying = true;
		Score = 0;
	}
}

void UMIShootingRangeSubsystem::Stop()
{
	if (bIsPlaying)
	{
		bIsPlaying = false;
	}
}

void UMIShootingRangeSubsystem::AddScore()
{
	if (bIsPlaying)
	{
		Score++;
		OnScoreChanged.Broadcast(Score);
	}
}
