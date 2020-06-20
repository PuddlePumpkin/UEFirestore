// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/Online/HTTP/Public/Http.h"
#include "UObject/NoExportTypes.h"
#include "FStoreFunctions.h"
#include "RestHandler.generated.h"

DECLARE_DELEGATE_OneParam(FResponseDelegate, FString);
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
	void MyHttpCall(FString Verb, FString Address, TMap<FString, FString> Headers, UFStoreFunctions* obj, void (UFStoreFunctions::* inFunc)(FString), bool PrintDebug = false);

	/*Assign this function to call when the GET request processes sucessfully*/
	void OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
	void FuckedTest(FString test);
};
