// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/Online/HTTP/Public/Http.h"
#include "UObject/NoExportTypes.h"
#include "RestHandler.generated.h"

class UFStoreFunctions;
DECLARE_DELEGATE_TwoParams(FResponseDelegate, TSharedPtr<FJsonObject>, FString);
/**
 * 
 */
UCLASS()
class FIRESTORE_API URestHandler : public UObject
{
	GENERATED_BODY()
public:
	//UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Events")
	//FResponseDelegate RDelegate;
	FHttpModule* Http;

	/* The actual HTTP call */
	void MyHttpCall(FString Verb, FString Address, TMap<FString, FString> Headers,UFStoreFunctions* obj, void (UFStoreFunctions::* inFunc)(TSharedPtr<FJsonObject>,FString), bool PrintDebug = false, FString body = "");

	/*Assign this function to call when the GET request processes sucessfully*/
	void OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
};
