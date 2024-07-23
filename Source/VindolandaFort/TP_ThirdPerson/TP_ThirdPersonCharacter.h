// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CombatComponent.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
#include "TP_ThirdPersonCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

UCLASS(config = Game)
class ATP_ThirdPersonCharacter : public ACharacter
{
    GENERATED_BODY()

    /** Camera boom positioning the camera behind the character */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
    USpringArmComponent* CameraBoom;

    /** Follow camera */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
    UCameraComponent* FollowCamera;

    /** MappingContext */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
    UInputMappingContext* DefaultMappingContext;

    ///** Jump Input Action */
    //UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
    //UInputAction* JumpAction;

    /** Move Input Action */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
    UInputAction* MoveAction;

    /** Look Input Action */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
    UInputAction* LookAction;

    /** Sprint Input Action */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
    UInputAction* SprintAction;

    /** Crouch Input Action */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
    UInputAction* CrouchAction;

    /* Movement arg */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (AllowPrivateAccess = "true"))
    float maxWalkSpeed = 250.f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (AllowPrivateAccess = "true"))
    float maxWalkSpeedCrouched = 175.f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (AllowPrivateAccess = "true"))
    float sprintSpeed = 500.f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (AllowPrivateAccess = "true"))
    float jumpHeight = 700.f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (AllowPrivateAccess = "true"))
    bool bIsCrouching;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (AllowPrivateAccess = "true"))
    bool bIsSprinting;

    /** CombatComponent */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Default, meta = (AllowPrivateAccess = "true"))
    UCombatComponent* CombatComponent;
    /* Combat arg */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
    bool bIsHandWeapon;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
    bool bIsHandShield;

public:
    ATP_ThirdPersonCharacter();

protected:

    /** Called for movement input */
    void Move(const FInputActionValue& Value);

    /** Called for looking input */
    void Look(const FInputActionValue& Value);

    /** Called for Sprint input */
    void Sprint(const FInputActionValue& Value);

    /** Called for Crouch input */
    void ACrouch(const FInputActionValue& Value);

    ///** Called for Attack input */
    //UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Combat")
    //void Attack(const bool Value);
    //virtual void Attack_Implementation(const bool Value);
    //UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Combat")
    //void PrimeAttack(int& Count);
    //virtual void PrimeAttack_Implementation(int& Count);

    /** Called for Defend input */
    //void Defend(const FInputActionValue& Value);

protected:
    // APawn interface
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    // To add mapping context
    virtual void BeginPlay();

    virtual void Tick(float DeltaTime);

public:
    /** Returns CameraBoom subobject **/
    FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
    /** Returns FollowCamera subobject **/
    FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

