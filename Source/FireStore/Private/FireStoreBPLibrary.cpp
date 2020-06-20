// Copyright Epic Games, Inc. All Rights Reserved.

#include "FireStoreBPLibrary.h"
#include "FireStore.h"
#include "RestHandler.h"

UFireStoreBPLibrary::UFireStoreBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

float UFireStoreBPLibrary::FireStoreSampleFunction(float Param)
{
	return -1;
}

bool UFireStoreBPLibrary::FireStoreRequestTest()
{
	//RestHandler RH;
	//RH.MyHttpCall("GET", "https://httpbin.org/get", true);
	UFStoreFunctions* SF;
	SF = NewObject<UFStoreFunctions>();
	SF->RequestDocument("ya29.a0AfH6SMCiinpRRemRcMGMRMI-8690nXszOuhuPw22xepKcgdZTD1tms80DgGTudcP8EIVnc38hRo7LLhQ9KLpBLSDGHGMFO6tv80tF2NT-fc842OfP2aX_JVkksPQVI6WgAEs72IWMaCcgfnTaA9etA-THV1XWwkz9SDn4aNbc3kxsT0sFWX9ZNDRe86RBN8u_rKtDNW1nPBq5Ur4wnq5DDA6JKUeem0tm67QJA_a5oirCFnoqZB9F_5CR6UOjUsXS4PIz47WcSxrsw", "temp", "temp");
	SF->ConditionalBeginDestroy();
	return true;
}

