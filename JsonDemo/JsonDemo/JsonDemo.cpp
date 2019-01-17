// JsonDemo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include "include/rapidjson/document.h"
#include "include/rapidjson/rapidjson.h"
#include "include/rapidjson/writer.h"
#include "include/rapidjson/stringbuffer.h"
#include <string>
#include <iostream>
#include <fstream>
#include "JsonManager.h"

using namespace std;
using namespace rapidjson;

int _tmain(int argc, _TCHAR* argv[])
{
	//Demo1 save to JsonDemo01.json
 	std::string strDemo1Path = "./JsonDemo01.json";
// 	JsonManager::GetInstance()->SaveToJson1(strDemo1Path.c_str());


	//Demo1 save to JsonDemo02.json
// 	std::string strDemo2Path = "./JsonDemo02.json";
// 	JsonManager::GetInstance()->SaveToJson2(strDemo2Path.c_str());

	//load  JsonDemo01.json
 	JsonManager::GetInstance()->LoadJson1(strDemo1Path.c_str());
	system("pause");
	return 0;
}

