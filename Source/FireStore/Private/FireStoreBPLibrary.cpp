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
//	MainFunctions::GetDocument("ya29.a0AfH6SMBHgBdwUIz0q-DeAGVziwXl43eDaPzrkqdhAMg5sgFs0Vu1MQOBHhdwjqVM0saS9LAOF1gwMA9F_yiuO3OcUkEO5SQwBi0K9G1qBuvPDrINRo11j9wSB_7vStcY_pPh8UDyfQ71eglvVDV-7LZ40zE-9ITP-ujN5JankDyng-ydga207dc0ouEtnKD9AqFCPtfeBKFK30BXtd9aENUB_yQxl6px0QGF4m-H9XgbgKlaci3XdnuG578x-kOQmypeXmZljTp9SA", "temp", "temp");
	return true;
}

