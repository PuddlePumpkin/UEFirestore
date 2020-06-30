// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
//#include "Runtime/JsonUtilities/Public/JsonObjectConverter.h"
#include "UObject/NoExportTypes.h"
#include "FSJsonObject.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class FIRESTORE_API UFSJsonObject : public UObject
{
	GENERATED_BODY()
	UFUNCTION(BlueprintCallable, meta = (Tooltip = "sets a string field", DisplayName = "Set string field", Keywords = "FireStore database datastore json"), Category = "Firestore Functions")
		void SetStringField(FString fieldName, FString string);
	UFUNCTION(BlueprintCallable, meta = (Tooltip = "sets a string array field", DisplayName = "Set string array field", Keywords = "FireStore database datastore json"), Category = "Firestore Functions")
		void SetStringArrayField(FString fieldName, TArray<FString> stringArray);
	TSharedPtr<FJsonObject> jobj = MakeShareable(new FJsonObject);
};
