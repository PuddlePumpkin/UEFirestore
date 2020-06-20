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
USTRUCT()
struct FIntegerValue
{
	GENERATED_USTRUCT_BODY()
		UPROPERTY()
		int32 integerValue;
};
USTRUCT()
struct FStringValue
{
	GENERATED_USTRUCT_BODY()
		UPROPERTY()
		FString stringValue;
};
USTRUCT()
struct FStringArrayValue
{
	GENERATED_USTRUCT_BODY()
		UPROPERTY()
		TArray<FStringValue> values;
};
USTRUCT()
struct FSkills
{
	GENERATED_USTRUCT_BODY()
		UPROPERTY()
		FStringArrayValue arrayValue;
};
USTRUCT()
struct FPlayerData
{
	GENERATED_USTRUCT_BODY()
		UPROPERTY()
		FStringValue Name;
		UPROPERTY()
		FSkills Skills;
};

UCLASS()
class FIRESTORE_API UFStoreFunctions : public UObject
{
	GENERATED_BODY()
public:
		void RequestDocument(FString OAuthToken, FString ProjectID, FString DocumentPath);
		void RecieveDocument(TSharedPtr<FJsonObject> PTR, FString AsStr);
};

