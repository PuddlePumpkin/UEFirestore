// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "RestHandler.h"
#include "FStoreFunctions.h"
#include "FireStoreBPLibrary.generated.h"

UCLASS()
class UFireStoreBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
		//These are the main functions callable in the plugin
		//rewriting the functions they use to be static and blueprintable would require major rewrites of each

};
