// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "RestHandler.h"
#include "FStoreFunctions.h"
#include "FireStoreBPLibrary.generated.h"

UCLASS()
class UFireStoreBPLibrary : public UBlueprintFunctionLibrary
{
	//GENERATED_UCLASS_BODY()
	GENERATED_BODY()
		//These are the main functions callable in the plugin
		//rewriting the functions they use to be static and blueprintable would require major rewrites of each
	UFUNCTION(BlueprintCallable, meta = (Tooltip = "Request a firestore document to read",DisplayName = "Request Firestore Document", Keywords = "FireStore database datastore"), Category = "Firestore Functions")
		static bool FireStoreRequest(FString OAUTHToken, FString ProjectID, FString documentPath, const FStringDelegate& Del);
	UFUNCTION(BlueprintCallable, meta = (Tooltip = "Updates a firestore document with given string",DisplayName = "Update Firestore Document", Keywords = "FireStore database datastore"), Category = "Firestore Functions")
		static bool FireStorePatch(FString OAUTHToken,FString ProjectID,FString documentPath, FString content, const FStringDelegate& Del);
	UFUNCTION(BlueprintCallable, meta = (Tooltip = "Requests a new access token for google cloud",DisplayName = "Get GCloud Access Token", Keywords = "FireStore database datastore"), Category = "Firestore Functions")
		static void getAccessToken(FString filename, const FStringDelegate& Del);
};
