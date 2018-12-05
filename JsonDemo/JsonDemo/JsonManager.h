#pragma once
#include "include/rapidjson/document.h"
using namespace rapidjson;
class JsonManager
{
public:	
	static JsonManager*	GetInstance();
	void SaveToJson1(const char* szJsonPath);
	void SaveToJson2(const char* szJsonPath);

	void LoadJson1(const char* szJsonPath);
	~JsonManager();
private:
	JsonManager();
	void SaveToFile(const char* szPath,Document& pDoc);

private:

};
