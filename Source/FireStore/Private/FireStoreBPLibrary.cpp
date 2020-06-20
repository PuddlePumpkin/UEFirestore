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
	SF->RequestDocument("ya29.a0AfH6SMDb9qeQB-ht2_FBVVCcLrMmQHwTMlSWzYmhz-OMzWZMu94k1yYFkw63y_tbsymxKSEC5acwZaviv_agOafYYTEI_ioZf4397xznOyhsxw-qfTLWtQFFM1BLeHM4ZS9v_JWzLs92E9WqtiDFHeIXTEAaE7qNMcqLQ6FgogyCwnJmgYpFaZ1qt5TAIavDlyIp5dfJVRHA_vNxKz3Ycu1qHthVR4tr7vlXGP447dbtVDx240n6c7gSJM2BSQ8GnyhNZIQLWfT2ZQ", "temp", "temp");
	SF->ConditionalBeginDestroy();
	return true;
}

