// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Firestore.h"

/**
 * 
 */
class FIRESTORE_API MainFunctions
{
public:
	UFUNCTION()
		void GetDocument(FString AccessToken, FString ProjectID, FString DocumentPath);
	//default
	MainFunctions();
	~MainFunctions();


};
