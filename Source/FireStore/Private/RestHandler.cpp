// Fill out your copyright notice in the Description page of Project Settings.
#include "RestHandler.h"
#include "Kismet/KismetStringLibrary.h"
RestHandler::RestHandler()
{
	//called when constructed
	Http = &FHttpModule::Get();
}
bool outsideBool = false;
void RestHandler::MyHttpCall(FString Verb, FString Address, bool PrintDebug)
{
	TSharedRef<IHttpRequest> Request = Http->CreateRequest();
	Request->OnProcessRequestComplete().BindRaw(this, &RestHandler::OnResponseReceived);
	//This is the url on which to process the request
	Request->SetURL(Address);
	Request->SetVerb(Verb);
	Request->SetHeader(TEXT("User-Agent"), "X-kfsAgent");
	Request->SetHeader("Content-Type", TEXT("application/json"));
	outsideBool = PrintDebug;
	Request->ProcessRequest();
}


/*Assigned function on successfull http call*/
void RestHandler::OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	//Create a pointer to hold the json serialized data
	TSharedPtr<FJsonObject> JsonObject;

	//Create a reader pointer to read the json data
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Response->GetContentAsString());

	//Deserialize the json data given Reader and the actual object to deserialize
	if (FJsonSerializer::Deserialize(Reader, JsonObject))
	{
		if (outsideBool) {
			FString OutputString;
			TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&OutputString);
			FJsonSerializer::Serialize(JsonObject.ToSharedRef(), Writer);
			GEngine->AddOnScreenDebugMessage(2, 10.0f, FColor::Green, OutputString);
		}
	}
}

RestHandler::~RestHandler()
{
}
