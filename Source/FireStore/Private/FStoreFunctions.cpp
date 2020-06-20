// Fill out your copyright notice in the Description page of Project Settings.


#include "FStoreFunctions.h"


void UFStoreFunctions::RequestDocument(FString OAuthToken, FString ProjectID, FString DocumentPath)
{
	URestHandler* RH;
	RH = NewObject<URestHandler>();
	TMap<FString, FString> HeaderMap;
	HeaderMap.Add("Authorization", "Bearer " + OAuthToken);
	RH->MyHttpCall("GET", "https://firestore.googleapis.com/v1/projects/***REMOVED***/databases/(default)/documents/DediServerUserData/ExampleUser", HeaderMap,this,&UFStoreFunctions::RecieveDocument,true);
}

void UFStoreFunctions::RecieveDocument(FString ResponseStr)
{
	GEngine->AddOnScreenDebugMessage(1, 10.0f, FColor::Red, ResponseStr);
}
