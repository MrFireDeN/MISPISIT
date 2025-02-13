// CPP_IProduct.h

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CPP_IProduct.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UCPP_IProduct : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class MISPISIT_API ICPP_IProduct
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual float GetPrice() { return 0; }
	virtual FName GetName() { return "Name"; }
	virtual void PlaceInBox(AActor* Box) {}
	virtual void PlaceInWorld() {}
};
