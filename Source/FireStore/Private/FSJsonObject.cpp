// Fill out your copyright notice in the Description page of Project Settings.


#include "FSJsonObject.h"

void UFSJsonObject::SetStringField(FString fieldName, FString string)
{
	jobj->SetStringField(fieldName, string);
}
void UFSJsonObject::SetStringArrayField(FString fieldName, TArray<FString> stringArray)
{
	TArray<TSharedPtr<FJsonValue>> jsonStrArray;
	for (FString Str : stringArray)
	{
		jsonStrArray.Add(MakeShareable(new FJsonValueString(Str)));
	}
	jobj->SetArrayField(fieldName, jsonStrArray);
	//FString OutputString;
	//TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&OutputString);
	//FJsonSerializer::Serialize(jobj.ToSharedRef(),Writer);
	//UE_LOG(LogHttp, Display, TEXT("response: %s"), *OutputString);
}
//todo read stuff:
FString UFSJsonObject::GetJsonString() 
{
	FString OutputString;
	TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&OutputString);
	FJsonSerializer::Serialize(jobj.ToSharedRef(), Writer);
	return OutputString;
}
void UFSJsonObject::ClearJson()
{
	jobj = MakeShareable(new FJsonObject);
}