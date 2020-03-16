#include "JsonManager.h"
#include "include/rapidjson/stringbuffer.h"
#include "include/rapidjson/writer.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;


JsonManager::JsonManager()
{

}

JsonManager::~JsonManager()
{

}


JsonManager* JsonManager::GetInstance()
{

	static JsonManager s_JsonManager;
	return &s_JsonManager;
}


void JsonManager::SaveToJson1(const char* szJsonPath)
{
	// {
	// "name":"qfl",
	// "age":20,
	// "letter":["a","b","c"],
	// "location": {"province":"fujian","city":"xiamen","number":16}
	// "book":[{"name":"book1", "isbn":"123"},{"name":"book2","isbn":"456"}],
	// "healthy":true,
	// }

	Document doc;
	rapidjson::Document::AllocatorType& allocator = doc.GetAllocator();
	doc.SetObject();

	rapidjson::Value vName;
	doc.AddMember("name","qf1",allocator);
	doc.AddMember("age",20,allocator);

	Value letter (kArrayType);
	letter.PushBack("a",allocator);
	letter.PushBack("b",allocator);
	letter.PushBack("c",allocator);
	letter.PushBack(2,allocator);
	doc.AddMember("letter",letter,allocator);


	Value vLocation(kObjectType);
	vLocation.AddMember("province","fujian",allocator);
	vLocation.AddMember("city","xiamen",allocator);
	vLocation.AddMember("number",16, allocator);
	doc.AddMember("location",vLocation,allocator);

	Value vBook(kArrayType);

	Value vBookEle(kObjectType);
	vBookEle.AddMember("name","book1",allocator);
	vBookEle.AddMember("isbn","123",allocator);
	vBook.PushBack(vBookEle,allocator);

	Value vBookEle2(kObjectType);
	vBookEle2.AddMember("name","book2",allocator);
	vBookEle2.AddMember("isbn","456",allocator);
	vBook.PushBack(vBookEle2,allocator);

	doc.AddMember("book",vBook,allocator);
	doc.AddMember("health",true,allocator);

	SaveToFile(szJsonPath,doc);

}

void JsonManager::SaveToFile(const char* szPath,Document& pDoc)
{
	if(NULL == szPath)
		return;

	rapidjson::StringBuffer buffer;
	rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
	pDoc.Accept(writer);

	string strJson = buffer.GetString();
	printf("Json string :%s   \n\n",strJson.c_str());

	ofstream of(szPath);
	if(of.is_open())
	{
		of << strJson;
		of.close();
	}

}

void JsonManager::SaveToJson2(const char* szJsonPath)
{
	Document doc;
	Document::AllocatorType& allocator = doc.GetAllocator();
	doc.SetArray();


	Value rootNode(kObjectType);
	rootNode.AddMember("name","face",allocator);
	rootNode.AddMember("value",10.05,allocator);
	
	Value vFace(kArrayType);

	Value vEye(kObjectType);
	vEye.AddMember("eyes",2,allocator);
	vFace.PushBack(vEye,allocator);

	Value vNose(kObjectType);
	vNose.AddMember("nose",1,allocator);
	vFace.PushBack(vNose,allocator);

	Value vMouth(kObjectType);
	vMouth.AddMember("mouth",1,allocator);
	vFace.PushBack(vMouth,allocator);

	rootNode.AddMember("faceOrgan",vFace,allocator);


	doc.PushBack(rootNode,allocator);

	SaveToFile(szJsonPath,doc);
}

void JsonManager::LoadJson1(const char* szJsonPath)
{
	if(NULL == szJsonPath)
		return;

	std::string strText;
	ifstream ifStre(szJsonPath);
	if(!ifStre.is_open())
		return;

	std::string strCurLine;
	while (getline(ifStre,strCurLine))
	{
		strText.append(strCurLine);
	}

	ifStre.close();

	Document doc;

	doc.Parse(strText.c_str());

	if(!doc.IsObject())
		return;

	std::string result = "\n";

	if(doc.HasMember("name") && doc["name"].IsString())
	{
		std::string strName = doc["name"].GetString();
		result = "\nname:" + strName+ ",\n";
	}

	if(doc.HasMember("age") && doc["age"].IsInt())
	{
		int nAge = doc["age"].GetFloat();
		result.append("age:");
		result.append(to_string(nAge));
		result.append(",\n");
	}
	
	if(doc.HasMember("letter") && doc["letter"].IsArray())
	{
		rapidjson::Value vLetter;
		vLetter = doc["letter"];
		result.append("letter:[");
		for (rapidjson::SizeType i = 0 ; i < vLetter.Size();i++)
		{
			if(vLetter[i].IsString())
			{
				result.append(vLetter[i].GetString());				
			}else if(vLetter[i].IsInt())
			{
				result.append(to_string(vLetter[i].GetInt()));
			}
			else if(vLetter[i].IsFloat())
			{
				result.append(to_string(vLetter[i].GetFloat()));
			}
			result.append("  ");
		}

		result.append("],\n");
	}


	if(doc.HasMember("location") && doc["location"].IsObject())
	{
		rapidjson::Value vLocation;
		vLocation= doc["location"];
		result.append("location:{\n");
		if(vLocation.HasMember("province"))
		{
			result.append("  rovince:");
			result.append(vLocation["province"].GetString());
			result.append(",\n");
		}

		if(vLocation.HasMember("city"))
		{
			result.append("  city:");
			result.append(vLocation["city"].GetString());
			result.append(",\n");
		}

		if(vLocation.HasMember("number"))
		{
			result.append("  number:");
			result.append(to_string(vLocation["number"].GetInt()));
			result.append("\n");
		}
		result.append("},\n");
	}

	if(doc.HasMember("book") && doc["book"].IsArray())
	{
		rapidjson::Value aBooks;
		aBooks = doc["book"];
		result.append("\nbook:[\n");

		for (rapidjson::SizeType i = 0; i < aBooks.Size();i++)
		{
			if(aBooks[i].IsObject())
			{
				result.append("  {\n");
				if(aBooks[i].HasMember("name") && aBooks[i]["name"].IsString())
				{
					result.append("    name:");
					result.append( aBooks[i]["name"].GetString());
					result.append(",\n");
				}

				if(aBooks[i].HasMember("isbn") && aBooks[i]["isbn"].IsString())
				{
					result.append("    isbn:");
					result.append( aBooks[i]["isbn"].GetString());
					result.append("\n");
				}
				result.append("  },\n");
			}
		}
		result.append("]\n");
	}
	printf("%s's content is \n %s\n",szJsonPath,result.c_str());
}
