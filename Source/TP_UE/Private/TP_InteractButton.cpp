// Fill out your copyright notice in the Description page of Project Settings.


#include "TP_InteractButton.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ATP_InteractButton::ATP_InteractButton()
{
	// Create the static mesh component and set it as the root component
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	
	RootComponent = StaticMeshComponent;

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	BoxCollision->InitBoxExtent(FVector(32.f, 32.f, 32.f));
	BoxCollision->AttachToComponent(StaticMeshComponent, FAttachmentTransformRules::KeepRelativeTransform);
	BoxCollision->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &ATP_InteractButton::OnOverlapBegin);
}

// Called when the game starts or when spawned
void ATP_InteractButton::BeginPlay()
{
	Super::BeginPlay();
}

void ATP_InteractButton::OnHitBegin()
{
	if (ATP_UEGameMode* _GameMode = Cast<ATP_UEGameMode>(UGameplayStatics::GetGameMode(GetWorld()))) {
		_GameMode->HitButton();
		BoxCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		UE_LOG(LogTemp, Warning, TEXT("Hit"));
	}
}

void ATP_InteractButton::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	if (ATP_UECharacter* other = Cast<ATP_UECharacter>(OtherActor)) {
		OnHitBegin();
	}
}