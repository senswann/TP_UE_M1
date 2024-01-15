// Fill out your copyright notice in the Description page of Project Settings.


#include "TP_Boost.h"

// Sets default values
ATP_Boost::ATP_Boost()
{
	// Create the static mesh component and set it as the root component
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));

	RootComponent = StaticMeshComponent;

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	BoxCollision->InitBoxExtent(FVector(32.f, 32.f, 32.f));
	BoxCollision->AttachToComponent(StaticMeshComponent, FAttachmentTransformRules::KeepRelativeTransform);
	BoxCollision->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &ATP_Boost::OnOverlapBegin);

}

// Called when the game starts or when spawned
void ATP_Boost::BeginPlay()
{
	Super::BeginPlay();
}

void ATP_Boost::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	if (ATP_UECharacter* other = Cast<ATP_UECharacter>(OtherActor)) {
		other->AddLength();
		Destroy();
	}
}