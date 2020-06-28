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
//DECLARE_DYNAMIC_DELEGATE_OneParam(FRresponseDelegate, FString, FString);
DECLARE_DYNAMIC_DELEGATE_OneParam(FStringDelegate, FString, str);
USTRUCT()
struct FJSString
{
	GENERATED_USTRUCT_BODY()
		UPROPERTY()
		FString stringValue;
};
USTRUCT()
struct FJsContainer
{
	GENERATED_USTRUCT_BODY()
		UPROPERTY()
		FJSString json;
};
UCLASS()
class FIRESTORE_API UFStoreFunctions : public UObject
{
	GENERATED_BODY()
public:
		FStringDelegate ResponseDelegate;
		void RequestJsonDocument(FString OAuthToken, FString ProjectID, FString DocumentPath);
		void RecieveJsonDocument(TSharedPtr<FJsonObject> PTR, FString AsStr);
		UFUNCTION()
		void WriteJsonDocument(FString OAuthToken, FString ProjectID, FString DocumentPath, FString JString, const FStringDelegate& Del);
		void WriteResponse(TSharedPtr<FJsonObject> PTR, FString AsStr);
		static FString preparePathString(FString ProjectID, FString DocumentPath);
};

