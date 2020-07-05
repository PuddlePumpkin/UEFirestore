// Copyright (c) 2020 Keira Karanik

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
	FHttpModule* Http;

	//HTTP Call
	void MyHttpCall(FString Verb, FString Address, TMap<FString, FString> Headers,UFStoreFunctions* obj, void (UFStoreFunctions::* inFunc)(TSharedPtr<FJsonObject>,FString), bool PrintDebug = false, FString body = "");

	//HTTP Callback
	void OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
};
