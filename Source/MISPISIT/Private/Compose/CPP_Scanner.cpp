// CPP_Scanner.cpp

#include "Compose/CPP_Scanner.h"

#include "GameFramework/Character.h"
#include "Kismet/KismetSystemLibrary.h"


// Sets default values
ACPP_Scanner::ACPP_Scanner()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	ScannerMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ScannerMesh"));
	RootComponent = ScannerMesh;
	ScannerMesh->SetRelativeScale3D(FVector(0.5));

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	BoxCollision->SetBoxExtent(FVector(50));
	BoxCollision->SetupAttachment(RootComponent);
	
	UAssetLoader::LoadMeshFromAsset(ScannerMesh, "/Game/Project/Models/Compose/SM_Scanner.SM_Scanner");
}

void ACPP_Scanner::BeginPlay()
{
	CameraManager = GetWorld()->GetFirstPlayerController()->PlayerCameraManager;
}

void ACPP_Scanner::ScanProduct(ICPP_IProduct* Product)
{
	if (!Product) return;
	
	FString ProductInformation = "Product Name: " + Product->GetName().ToString() +
		"; Price: " + FString::FromInt(Product->GetPrice());
	UKismetSystemLibrary::PrintString(GetWorld(), ProductInformation);
}

bool ACPP_Scanner::OnPrimaryAction()
{
	
	if (!CameraManager) return false;

	// Начальная точка луча — позиция камеры
	FVector StartLocation = CameraManager->GetCameraLocation();

	// Конечная точка луча — вперед от камеры на определенное расстояние
	FVector ForwardVector = CameraManager->GetActorForwardVector();
	FVector EndLocation = StartLocation + (ForwardVector * 1000.0f); // 1000 — длина луча

	// Параметры трассировки
	FCollisionQueryParams TraceParams(FName(TEXT("LineTrace")), true);
	TraceParams.bTraceComplex = true; // Трассировка по сложной геометрии
	TraceParams.bReturnPhysicalMaterial = true; // Возвращать физический материал

	// Результат трассировки
	FHitResult HitResult;

	// Выполняем трассировку
	bool bHit = GetWorld()->LineTraceSingleByChannel(
		HitResult,
		StartLocation,
		EndLocation,
		ECC_Visibility, // Канал трассировки (видимость)
		TraceParams
	);

	// Обработка результата
	if (bHit)
	{
		// Если луч попал в объект
		AActor* HitActor = HitResult.GetActor();
		if (HitActor)
		{
			ScanProduct(Cast<ICPP_IProduct>(HitActor));
		}

		// Визуализация точки попадания
		DrawDebugSphere(GetWorld(), HitResult.Location, 10.0f, 12, FColor::Green, false, 5.0f);
	}
	
	return true;
}

bool ACPP_Scanner::OnAttach()
{
	ScannerMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	
	return ICPP_Interactable::OnAttach();
}

bool ACPP_Scanner::OnDetach()
{
	ScannerMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	ScannerMesh->SetSimulatePhysics(true);
	
	return ICPP_Interactable::OnDetach();
}

