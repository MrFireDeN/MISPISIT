﻿// CPP_Interactable.h

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CPP_Interactable.generated.h"

UINTERFACE(Blueprintable)
class UCPP_Interactable : public UInterface
{
	GENERATED_BODY()
};
class MISPISIT_API ICPP_Interactable
{
	GENERATED_BODY()

public:
	virtual bool OnAttach() { return true; }
	virtual bool OnDetach() { return true; }
	virtual bool OnTouch() { return true; }
};