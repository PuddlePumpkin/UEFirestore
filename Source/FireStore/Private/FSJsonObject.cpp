// Copyright (c) 2020 Keira Karanik


#include "FSJsonObject.h"
//sets
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
}
void UFSJsonObject::SetFloatField(FString fieldName, float number)
{
	jobj->SetNumberField(fieldName, number);
}
void UFSJsonObject::SetBoolField(FString fieldName, bool boolean)
{
	jobj->SetBoolField(fieldName, boolean);
}
//gets
FString UFSJsonObject::GetStringField(FString fieldName)
{
	return jobj->GetStringField(fieldName);
}
TArray<FString> UFSJsonObject::GetStringArrayField(FString fieldName)
{
	TArray<TSharedPtr<FJsonValue>> jsonStrArray;
	jsonStrArray = jobj->GetArrayField(fieldName);
	TArray<FString> StrArray;
	for (TSharedPtr<FJsonValue> val : jsonStrArray)
	{
		StrArray.Add(val->AsString());
	}
	return StrArray;
}
float UFSJsonObject::GetFloatField(FString fieldName)
{
	return jobj->GetNumberField(fieldName);
}
int32 UFSJsonObject::GetIntegerField(FString fieldName)
{
	return jobj->GetIntegerField(fieldName);
}
bool UFSJsonObject::GetBoolField(FString fieldName)
{
	return jobj->GetBoolField(fieldName);
}
//util
bool UFSJsonObject::HasField(FString fieldName)
{
	return jobj->HasField(fieldName);
}
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
bool UFSJsonObject::SetJsonString(FString JString)
{
	TSharedRef<TJsonReader<>> reader = TJsonReaderFactory<>::Create(JString);
	if (FJsonSerializer::Deserialize(reader, jobj))
	{
		return true;
	}
	else
	{
		return false;
	}
}