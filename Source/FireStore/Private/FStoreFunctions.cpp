// Fill out your copyright notice in the Description page of Project Settings.


#include "FStoreFunctions.h"


void UFStoreFunctions::RequestDocument(FString OAuthToken, FString ProjectID, FString DocumentPath)
{
	URestHandler* RH;
	RH = NewObject<URestHandler>();
	TMap<FString, FString> HeaderMap;
	HeaderMap.Add("Authorization", "Bearer " + OAuthToken);
	RH->MyHttpCall("GET", "https://firestore.googleapis.com/v1/projects/***REMOVED***/databases/(default)/documents/DediServerUserData/ExampleUser", HeaderMap,this,&UFStoreFunctions::RecieveDocument,false);
}
void UFStoreFunctions::RecieveDocument(TSharedPtr<FJsonObject> PTR, FString AsStr)
{
	//Firestore uses nested arrays for map fields
	//to access sub arrays declare a ustruct matching the format of your document field see https://stackoverflow.com/questions/30342465/c-nested-json-in-unreal-engine-4
	//make player data struct
	FPlayerData pdat;

	//remove json container
	FString clippedStr;
	TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&clippedStr);
	FJsonSerializer::Serialize(PTR->GetObjectField("fields").ToSharedRef(), Writer);

	//write to player data
	FJsonObjectConverter::JsonObjectStringToUStruct<FPlayerData>(clippedStr,&pdat,0, 0);

	//Print result
	UE_LOG(LogTemp, Display, TEXT("%s"),*clippedStr);
	//UE_LOG(LogTemp, Display, TEXT("Retrieved value: %s"), *pdat.Name.stringValue);
	//UE_LOG(LogTemp, Display, TEXT("Retrieved Count: %s"), (pdat.Skills.arrayValue.values.)));
	FString prsts;
	if (FJsonObjectConverter::UStructToJsonObjectString<FPlayerData>(pdat, prsts)) {
		UE_LOG(LogTemp, Display, TEXT("UStruct: %s"), *prsts);
	}
	
	UE_LOG(LogHttp, Display, TEXT("End Response"));
}