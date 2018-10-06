// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UnitActor.generated.h"

UCLASS()
class UNREALPROJECT_API AUnitActor : public AActor
{
	GENERATED_BODY()
		//------------------------------------------------------
		// Accessors
		//------------------------------------------------------
public: void SetInvincibleSeconds(float iSeconds) { mInvincibleSeconds = iSeconds; }
public: bool IsInvincible() { return (mInvincibleSeconds > 0.0f); }
public: bool IsDie() { return false; }

		//------------------------------------------------------
		// Method
		//------------------------------------------------------
public:	                 AUnitActor();
public:    virtual float ReceiveDamage(bool* ipIsCritical, AUnitActor iUnit, float iAttack);
//public:    virtual void  Terminate();
public:	   virtual void  Tick(float DeltaTime) override;
protected: virtual void  BeginPlay()                override;
protected: virtual void  OnHitUnit(AUnitActor iUnit) {}

		   //------------------------------------------------------
		   // Variables
		   //------------------------------------------------------
protected:  float mInvincibleSeconds;
protected:  float mRegenerateSeconds;
protected:  bool  mIsChangedHP;
};
