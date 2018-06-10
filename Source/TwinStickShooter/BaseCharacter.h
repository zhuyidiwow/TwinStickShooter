// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

UCLASS(Blueprintable)
class TWINSTICKSHOOTER_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	//Step 2: Expose a float property
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "BaseCharacter")
		float Health = 100.0f;

	//Step 3: Expose a boolean property
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "BaseCharacter")
		bool isDead = false;


	//Step 4: Make a helper function, just because we are lazy
	virtual void CalculateDead();

	//Step 5: Expose a method
	UFUNCTION(BlueprintCallable, Category = "BaseCharacter")
		virtual void CalculateHealth(float delta);


	//Step 6: Editor code to make updating values in the editor cleaner
#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

	ABaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	
};
