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
	TSharedPtr<FJsonObject> jobj = MakeShareable(new FJsonObject);
	//sets
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Set String Field", Tooltip = "Sets a string field.", Keywords = "FireStore database datastore json"), Category = "Firestore Json")
		void SetStringField(FString fieldName, FString string);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Set String Array Field", Tooltip = "Sets a string array field.", Keywords = "FireStore database datastore json"), Category = "Firestore Json")
		void SetStringArrayField(FString fieldName, TArray<FString> stringArray);
	//util
	UFUNCTION(BlueprintPure , meta = (DisplayName = "Get Json String", Tooltip = "Gets a string from json object.", Keywords = "FireStore database datastore json"), Category = "Firestore Json")
		FString GetJsonString();
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Clear Json", Tooltip = "Resets a json object to default", Keywords = "FireStore database datastore json"), Category = "Firestore Json")
		void ClearJson();
};
