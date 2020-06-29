// Fill out your copyright notice in the Description page of Project Settings.


#include "FStoreFunctions.h"
#include "jwt.h"

void UFStoreFunctions::RequestJsonDocument(FString OAuthToken, FString ProjectID, FString DocumentPath, const FStringDelegate& Del)
{
	ResponseDelegate = Del;
	URestHandler* RH;
	RH = NewObject<URestHandler>();
	TMap<FString, FString> HeaderMap;
	HeaderMap.Add("Authorization", "Bearer " + OAuthToken);
	FString urlStr = preparePathString(ProjectID, DocumentPath);
	RH->MyHttpCall("GET", urlStr, HeaderMap,this,&UFStoreFunctions::RecieveJsonDocument,false);
	RH->ConditionalBeginDestroy();
}
void UFStoreFunctions::RecieveJsonDocument(TSharedPtr<FJsonObject> PTR, FString AsStr)
{
	//Firestore uses nested arrays for map fields
	//to access sub arrays declare a ustruct matching the format of your document field see https://stackoverflow.com/questions/30342465/c-nested-json-in-unreal-engine-4
	//make player data struct
	FJsContainer js;
	//remove json container
	FString clippedStr;
	TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&clippedStr);
	FJsonSerializer::Serialize(PTR->GetObjectField("fields").ToSharedRef(), Writer);

	//write to player data
	FJsonObjectConverter::JsonObjectStringToUStruct<FJsContainer>(clippedStr,&js,0, 0);

	//Print result
	UE_LOG(LogTemp, Display, TEXT("%s"),*clippedStr);
	UE_LOG(LogTemp, Display, TEXT("SubJson: %s"), *js.json.stringValue)
	ResponseDelegate.ExecuteIfBound(*js.json.stringValue);
	UE_LOG(LogHttp, Display, TEXT("End Response"));
}
void UFStoreFunctions::WriteJsonDocument(FString OAuthToken, FString ProjectID, FString DocumentPath, FString JString, const FStringDelegate& Del)
{
	ResponseDelegate = Del;
	URestHandler* RH;
	RH = NewObject<URestHandler>();
	TMap<FString, FString> HeaderMap;
	HeaderMap.Add("Authorization", "Bearer " + OAuthToken);
	//HeaderMap.Add("Authorization", "Key " + OAuthToken);
	FString PayloadString = "{\"fields\": {\"json\": {\"stringValue\": \""+JString+"\"}}}";
	FString urlStr = preparePathString(ProjectID, DocumentPath);
	RH->MyHttpCall("PATCH", urlStr, HeaderMap, this, &UFStoreFunctions::WriteResponse, false,PayloadString);
	RH->ConditionalBeginDestroy();
}

void UFStoreFunctions::WriteResponse(TSharedPtr<FJsonObject> PTR, FString AsStr)
{
	ResponseDelegate.ExecuteIfBound(AsStr);
	UE_LOG(LogHttp, Display, TEXT("response: %s"), *AsStr);
	UE_LOG(LogHttp, Display, TEXT("End Response"));
}

FString UFStoreFunctions::preparePathString(FString ProjectID, FString DocumentPath)
{
	return ("https://firestore.googleapis.com/v1/projects/" + ProjectID + "/databases/(default)/documents/" + DocumentPath);
}

void UFStoreFunctions::getToken()
{
	//UE_LOG(LogHttp, Display, TEXT("fuck monkey:"));
	//FString jsonFile = "***REMOVED***-1e30ffe5c7eb.json";
	FString jsonFile = "C:\\Users\\Kira\\Desktop\\***REMOVED***-1e30ffe5c7eb.json";
	const TCHAR* file = *jsonFile;

	FString result;
	//bool bout = FFileHelper::LoadFileToString(result, *FPaths::ProjectDir() + *file);
	bool bout = FFileHelper::LoadFileToString(result, file);
	UE_LOG(LogHttp, Display, TEXT("Bool: %s"), bout ? TEXT("true") : TEXT("false"));
	UE_LOG(LogHttp, Display, TEXT("Dick her down: %s"), *result);
	//}
	FString pkey = "***REMOVED***";
auto token = jwt::create()
	.set_issuer("***REMOVED***")
	.set_type("JWS")
	.set_subject("***REMOVED***")
	//.set_audience("https://www.googleapis.com/oauth2/v4/token")
	.set_audience("https://oauth2.googleapis.com/token")
	.set_payload_claim("scope", jwt::claim(std::string("https://www.googleapis.com/auth/datastore")))
	.set_issued_at(std::chrono::system_clock::now())
	.set_expires_at(std::chrono::system_clock::now() + std::chrono::seconds{ 3600 })
	.sign(jwt::algorithm::rs256{"secret",std::string(TCHAR_TO_UTF8(*pkey))});
//ResponseDelegate = Del;
URestHandler* RH;
RH = NewObject<URestHandler>();
TMap<FString, FString> HeaderMap;
FString sturng = token.c_str();
//HeaderMap.Add("Authorization", "Bearer " + sturng);
UE_LOG(LogHttp, Display, TEXT("jwt: %s"), *sturng);
FString PayloadString = "grant_type=urn%3Aietf%3Aparams%3Aoauth%3Agrant-type%3Ajwt-bearer&assertion=" + sturng;
RH->MyHttpCall("POST", "https://oauth2.googleapis.com/token", HeaderMap, this, &UFStoreFunctions::WriteResponse, true,PayloadString);
//RH->MyHttpCall("POST", "https://www.googleapis.com/oauth2/v4/token", HeaderMap, this, &UFStoreFunctions::WriteResponse, true);
RH->ConditionalBeginDestroy();
}
