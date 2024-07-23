// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CombatComponent.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class VINDOLANDAFORT_API UCombatComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    // Sets default values for this component's properties
    UCombatComponent();

    /** Attack Input Action */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
    bool bIsAttacking;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
    int AttackCount;

    /** Defend Input Action */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
    bool bIsDefending;

protected:
    // Called when the game starts
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


};
