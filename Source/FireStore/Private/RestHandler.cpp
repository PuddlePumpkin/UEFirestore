// Fill out your copyright notice in the Description page of Project Settings.


#include "RestHandler.h"
/*URestHandler::URestHandler(const FObjectInitializer& ObjectInitializer)
{
	//called when constructed
	
}*/
bool outsideBool = false;
UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Events")
FResponseDelegate RDelegate;
void URestHandler::MyHttpCall(FString Verb, FString Address, TMap<FString, FString> Headers, UFStoreFunctions* obj, void (UFStoreFunctions::*inFunc)(TSharedPtr<FJsonObject>,FString), bool PrintDebug)
{
	//RDelegate.BindRaw();
	//RDelegate.BindUObject(this, inFunc);
	RDelegate.BindUObject(obj, inFunc);
	Http = &FHttpModule::Get();
	TSharedRef<IHttpRequest> Request = Http->CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &URestHandler::OnResponseReceived);
	//Iterate headers
	for (auto& Elem : Headers)
	{
		Request->SetHeader(Elem.Key, Elem.Value);
	}
	//This is the url on which to process the request
	Request->SetURL(Address);
	Request->SetVerb(Verb);
	outsideBool = PrintDebug;
	Request->ProcessRequest();
}


/*Assigned function on successfull http call*/
void URestHandler::OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	//Create a pointer to hold the json serialized data
	TSharedPtr<FJsonObject> JsonObject;

	//Create a reader pointer to read the json data
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Response->GetContentAsString());

	//Deserialize the json data given Reader and the actual object to deserialize
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

void URestHandler::FuckedTest(FString test)
{
	GEngine->AddOnScreenDebugMessage(1, 10.0f, FColor::Red, "LITTERALLY KILL ME");
}

