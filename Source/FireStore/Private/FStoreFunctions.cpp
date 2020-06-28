// Fill out your copyright notice in the Description page of Project Settings.


#include "FStoreFunctions.h"


void UFStoreFunctions::RequestJsonDocument(FString OAuthToken, FString ProjectID, FString DocumentPath)
{
	URestHandler* RH;
	RH = NewObject<URestHandler>();
	TMap<FString, FString> HeaderMap;
	HeaderMap.Add("Authorization", "Bearer " + OAuthToken);
	RH->MyHttpCall("GET", "https://firestore.googleapis.com/v1/projects/***REMOVED***/databases/(default)/documents/DediServerUserData/ExampleUser", HeaderMap,this,&UFStoreFunctions::RecieveJsonDocument,true);
	RH->ConditionalBeginDestroy();
}
void UFStoreFunctions::RecieveJsonDocument(TSharedPtr<FJsonObject> PTR, FString AsStr)
{
	//Firestore uses nested arrays for map fields
	//to access sub arrays declare a ustruct matching the format of your document field see https://stackoverflow.com/questions/30342465/c-nested-json-in-unreal-engine-4
	//make player data struct
	FJsContainer js;
	//remove json container
	FString clippedStr;
	TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&clippedStr);
	FJsonSerializer::Serialize(PTR->GetObjectField("fields").ToSharedRef(), Writer);

	//write to player data
	FJsonObjectConverter::JsonObjectStringToUStruct<FJsContainer>(clippedStr,&js,0, 0);

	//Print result
	UE_LOG(LogTemp, Display, TEXT("%s"),*clippedStr);
	UE_LOG(LogTemp, Display, TEXT("SubJson: %s"),*js.json.stringValue)
	UE_LOG(LogHttp, Display, TEXT("End Response"));
}
void UFStoreFunctions::WriteJsonDocument(FString OAuthToken, FString ProjectID, FString DocumentPath, FString JString, const FStringDelegate& Del)
{
	ResponseDelegate = Del;
	URestHandler* RH;
	RH = NewObject<URestHandler>();
	TMap<FString, FString> HeaderMap;
	HeaderMap.Add("Authorization", "Bearer " + OAuthToken);
	FString PayloadString = "{\"fields\": {\"json\": {\"stringValue\": \""+JString+"\"}}}";
	FString urlStr = preparePathString(ProjectID, DocumentPath);
	RH->MyHttpCall("PATCH", urlStr, HeaderMap, this, &UFStoreFunctions::WriteResponse, false,PayloadString);
	RH->ConditionalBeginDestroy();
}

void UFStoreFunctions::WriteResponse(TSharedPtr<FJsonObject> PTR, FString AsStr)
{
	ResponseDelegate.ExecuteIfBound(AsStr);
	UE_LOG(LogHttp, Display, TEXT("%s"), *AsStr);
	UE_LOG(LogHttp, Display, TEXT("End Response"));
}

FString UFStoreFunctions::preparePathString(FString ProjectID, FString DocumentPath)
{
	return ("https://firestore.googleapis.com/v1/projects/" + ProjectID + "/databases/(default)/documents/" + DocumentPath);
}