// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/Online/HTTP/Public/Http.h"
#include "Firestore.h"
/**
 * 
 */
class FIRESTORE_API RestHandler
{
public:
	FHttpModule* Http;

	/* The actual HTTP call */
	UFUNCTION()
		void MyHttpCall(FString Verb, FString Address, bool PrintDebug = false);

	/*Assign this function to call when the GET request processes sucessfully*/
	void OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

	//default
	RestHandler();
	~RestHandler();
};
