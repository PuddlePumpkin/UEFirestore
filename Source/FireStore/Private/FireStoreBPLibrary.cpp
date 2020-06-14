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
	RestHandler RH;
	RH.MyHttpCall("GET", "https://httpbin.org/get", true);
	return true;
}

