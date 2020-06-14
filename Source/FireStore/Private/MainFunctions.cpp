// Fill out your copyright notice in the Description page of Project Settings.


#include "MainFunctions.h"

MainFunctions::MainFunctions()
{
}
void MainFunctions::GetDocument(FString AccessToken, FString ProjectID, FString DocumentPath) {
	RestHandler RH;
	RH.MyHttpCall("GET", "https://firestore.googleapis.com/v1/projects/", true);
}
MainFunctions::~MainFunctions()
{
}
