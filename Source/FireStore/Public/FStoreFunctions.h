// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FireStore.h"
#include "RestHandler.h"
#include "Runtime/JsonUtilities/Public/JsonObjectConverter.h"
#include "FStoreFunctions.generated.h"

/**
 * 
 */
struct FStringValue
{
	GENERATED_USTRUCT_BODY()
		UPROPERTY()
		FString stringValue;
};

UCLASS()
class FIRESTORE_API UFStoreFunctions : public UObject
{
	GENERATED_BODY()
public:
		void RequestDocument(FString OAuthToken, FString ProjectID, FString DocumentPath);
		void RecieveDocument(TSharedPtr<FJsonObject> PTR, FString AsStr);
};

