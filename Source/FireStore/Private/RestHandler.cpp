// Copyright (c) 2020 Keira Karanik


#include "RestHandler.h"
/*URestHandler::URestHandler(const FObjectInitializer& ObjectInitializer)
{
	//called when constructed
	
}*/
bool outsideBool = false;
UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Events")
FResponseDelegate RDelegate;
void URestHandler::MyHttpCall(FString Verb, FString Address, TMap<FString, FString> Headers,UFStoreFunctions* obj, void (UFStoreFunctions::*inFunc)(TSharedPtr<FJsonObject>,FString), bool PrintDebug, FString body)
{
	RDelegate.BindUObject(obj, inFunc);
	Http = &FHttpModule::Get();
	TSharedRef<IHttpRequest> Request = Http->CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &URestHandler::OnResponseReceived);
	//Iterate headers
	for (auto& Elem : Headers)
	{
		Request->SetHeader(Elem.Key, Elem.Value);
	}
	Request->SetURL(Address);
	Request->SetVerb(Verb);
	if (Verb != "POST") {
	Request->SetHeader("Content-Type", "application/json");
	}
	else {
	Request->SetHeader("Content-Type", "application/x-www-form-urlencoded");
	}
	if (Verb == "PATCH" || Verb == "POST") {
		UE_LOG(LogHttp, Display, TEXT("requested"));
		Request->SetContentAsString(body);
	}
	outsideBool = PrintDebug;
	Request->ProcessRequest();
}
void URestHandler::OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	TSharedPtr<FJsonObject> JsonObject;
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Response->GetContentAsString());

	//Deserialize
	if (FJsonSerializer::Deserialize(Reader, JsonObject))
	{
		FString OutputString;
		TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&OutputString);
		FJsonSerializer::Serialize(JsonObject.ToSharedRef(), Writer);
		if (outsideBool) {

			GEngine->AddOnScreenDebugMessage(2, 10.0f, FColor::Green, OutputString);
		}
		RDelegate.ExecuteIfBound(JsonObject, OutputString);
	}
}

