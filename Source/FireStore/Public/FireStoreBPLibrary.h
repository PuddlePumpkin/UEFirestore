// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "RestHandler.h"
#include "FStoreFunctions.h"
#include "FireStoreBPLibrary.generated.h"
//DECLARE_DYNAMIC_MULTICAST_DELEGATE(FResponseDelegate);
/* 
*	Function library class.
*	Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.
*
*	When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.
*	BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.
*	BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.
*	DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.
*				Its lets you name the node using characters not allowed in Ca++ function names.
*	CompactNodeTitle - the word(s) that appear on the node.
*	Keywords -	the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu. 
*				Good example is "Print String" node which you can find also by using keyword "log".
*	Category -	the category your node will be under in the Blueprint drop-down menu.
*
*	For more info on custom blueprint nodes visit documentation:
*	https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation
*/

UCLASS()
class UFireStoreBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Execute Sample function", Keywords = "uwu FireStore sample test testing"), Category = "FireStoreTesting")
		static float FireStoreSampleFunction(float Param);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Request Firestore Document", Keywords = "FireStore database datastore"), Category = "Firestore Functions")
		static bool FireStoreRequest(FString OAUTHToken, FString ProjectID, FString documentPath, const FStringDelegate& Del);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Update Firestore Document", Keywords = "FireStore database datastore"), Category = "Firestore Functions")
		static bool FireStorePatch(FString OAUTHToken,FString ProjectID,FString documentPath, FString content, const FStringDelegate& Del);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get GCloud Access Token", Keywords = "FireStore database datastore"), Category = "Firestore Functions")
		static void getAccessTok(FString filename);
};
