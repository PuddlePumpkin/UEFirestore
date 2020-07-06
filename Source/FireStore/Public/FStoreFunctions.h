// Copyright (c) 2020 Keira Karanik

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
DECLARE_DYNAMIC_DELEGATE_TwoParams(FStringDelegate, FString, str, bool, Success);
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
private:
		//Callback Function for "getToken()"
		void RecieveAccessToken(TSharedPtr<FJsonObject> PTR, FString AsStr);
		//helper function prepares a file path string from a project id and document path.
		static FString preparePathString(FString ProjectID, FString DocumentPath);
		FStringDelegate ResponseDelegate;
		//Reads a document from given path
		void RequestJsonDocument(FString OAuthToken, FString ProjectID, FString DocumentPath, const FStringDelegate& Del);
		//Callback Function for "RequestJsonDocument()"
		void RecieveJsonDocument(TSharedPtr<FJsonObject> PTR, FString AsStr);
		UFUNCTION()
		//Writes a document with given Json String
		void WriteJsonDocument(FString OAuthToken, FString ProjectID, FString DocumentPath, FString JString, const FStringDelegate& Del);
		//Callback Function for "WriteJsonDocument()"
		void RecieveWriteResponse(TSharedPtr<FJsonObject> PTR, FString AsStr);
		UFUNCTION()
		//Gets a access token from the Service account json file specified.
		bool getToken(FString filename, const FStringDelegate& Del);
public:
		//main functions
		UFUNCTION(BlueprintCallable, meta = (Tooltip = "Request a firestore document to read", DisplayName = "Request Firestore Document", Keywords = "FireStore database datastore"), Category = "Firestore Functions")
		static void FireStoreRequest(FString OAUTHToken, FString ProjectID, FString documentPath, const FStringDelegate& Del);
		UFUNCTION(BlueprintCallable, meta = (Tooltip = "Updates a firestore document with given string", DisplayName = "Update Firestore Document", Keywords = "FireStore database datastore"), Category = "Firestore Functions")
		static void FireStorePatch(FString OAUTHToken, FString ProjectID, FString documentPath, FString content, const FStringDelegate& Del);
		UFUNCTION(BlueprintCallable, meta = (Tooltip = "Requests a new access token for google cloud", DisplayName = "Get GCloud Access Token", Keywords = "FireStore database datastore"), Category = "Firestore Functions")
		static bool getAccessToken(FString filename, const FStringDelegate& Del);
		//end main functions
};

