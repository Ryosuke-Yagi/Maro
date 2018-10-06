// Fill out your copyright notice in the Description page of Project Settings.

#include "UnitActor.h"


//-----------------------------------------
// Constract
//-----------------------------------------
AUnitActor::AUnitActor()
{
	PrimaryActorTick.bCanEverTick = true;
}

//-----------------------------------------
// BeginPlay 
//-----------------------------------------
void AUnitActor::BeginPlay()
{
	Super::BeginPlay();
}

//-----------------------------------------
// Tick
//-----------------------------------------
void AUnitActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	mInvincibleSeconds = FMath::Max(mInvincibleSeconds - DeltaTime, 0.0f);
	bool aIsRegeneratable = !AUnitActor::IsDie();
	mRegenerateSeconds += DeltaTime;
	if (mRegenerateSeconds >= 1.0f)
	{
		mRegenerateSeconds -= 1.0f;
	}
}

//------------------------------------------------------
// Receive damage
//------------------------------------------------------
float AUnitActor::ReceiveDamage(bool* piIsCritical, AUnitActor iUnit, float iAttack)
{
	piIsCritical = false;

	if (IsInvincible()) { return 0.0f; }
	if (IsDie()) { return 0.0f; }


	float aDamage = iAttack;
	/*
	if (iUnit != null)
	{
	Unit  aAttacker = iUnit.GetUnit();
	float aAttackMin = iAttack * aAttacker.GetStability();
	aDamage = FMath::RandRange(aAttackMin, iAttack);
	aDamage = FMath::Clamp(FMath::RoundToFloat(aDamage), 1.0f, iAttack);
	if (Random.Range(0, 100) < (int)(aAttacker.GetCritical() * 100.0f))
	{
	aDamage *= 2.0f;
	piIsCritical = true;
	}
	}

	aReceiver.AddHP(-aDamage);
	*/
	mIsChangedHP = true;
	/*
	if (aReceiver.GetHP() <= 0.0f)
	{
	SetAnimatorBool(AnimatorParameters.IS_DIE, true);
	}
	*/
	mInvincibleSeconds = 4.0f / 60.0f;
	return aDamage;
}