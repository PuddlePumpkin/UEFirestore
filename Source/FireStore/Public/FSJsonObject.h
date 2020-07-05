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
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Set Float Field", Tooltip = "Sets a float field.", Keywords = "FireStore database datastore json"), Category = "Firestore Json")
		void SetFloatField(FString fieldName, float number);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Set Boolean Field", Tooltip = "Sets a boolean field.", Keywords = "FireStore database datastore json"), Category = "Firestore Json")
		void SetBoolField(FString fieldName, bool boolean);
	//gets
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get String Field", Tooltip = "Gets a string field.", Keywords = "FireStore database datastore json"), Category = "Firestore Json")
		FString GetStringField(FString fieldName);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get String Array Field", Tooltip = "Gets a string array field.", Keywords = "FireStore database datastore json"), Category = "Firestore Json")
		TArray<FString> GetStringArrayField(FString fieldName);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get Float Field", Tooltip = "Gets a float field.", Keywords = "FireStore database datastore json"), Category = "Firestore Json")
		float GetFloatField(FString fieldName);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get Integer Field", Tooltip = "Gets a float field and converts it to an int.", Keywords = "FireStore database datastore json"), Category = "Firestore Json")
		int32 GetIntegerField(FString fieldName);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get Boolean Field", Tooltip = "Gets a boolean field.", Keywords = "FireStore database datastore json"), Category = "Firestore Json")
		bool GetBoolField(FString fieldName);
	//util
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Has Field", Tooltip = "Returns true if a field exists.", Keywords = "FireStore database datastore json"), Category = "Firestore Json")
		bool HasField(FString fieldName);
	UFUNCTION(BlueprintPure , meta = (DisplayName = "Get Json String", Tooltip = "Gets a string from json object.", Keywords = "FireStore database datastore json"), Category = "Firestore Json")
		FString GetJsonString();
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Clear Json", Tooltip = "Resets a json object to default", Keywords = "FireStore database datastore json"), Category = "Firestore Json")
		void ClearJson();
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Set Json String", Tooltip = "Tries to set a json object to given json string", Keywords = "FireStore database datastore json"), Category = "Firestore Json")
		bool SetJsonString(FString JString);
};
