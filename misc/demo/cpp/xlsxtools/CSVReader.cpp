#include "stdafx.h"
#include "CSVReader.h"
#include <fstream>

CSVReader::CSVReader()
{
}


CSVReader::~CSVReader()
{
}


bool CSVReader::LoadText(string textfileName, int skipLine)
{
	FILE *fp = NULL;
	fopen_s(&fp, textfileName.c_str(), "r");

	if (fp == NULL) {
		printf("can not load file!");
		return false;
	}
	int lineCount = 1;
	while (!feof(fp))
	{
		char lineContent[1024] = { 0 };
		fgets(lineContent, 1024, fp);
		if (lineCount > skipLine)
		{
			ParseLine(lineContent);
		}
		//printf("%d %s", lineCount, lineContent);
		lineCount++;
	}
	fclose(fp);

	Log();

	return true;
}

void CSVReader::ParseLine(string lineText)
{
	vector<string> vals;
	Split(lineText, "#", vals);
	items.push_back(FieldData(vals));
}

void CSVReader::Split(const string& str, const string& delim, vector<string> & ret) {
	std::string::size_type pos1, pos2;
	size_t len = str.length();
	pos2 = str.find(delim);
	pos1 = 0;
	while (std::string::npos != pos2)
	{
		ret.emplace_back(str.substr(pos1, pos2 - pos1));

		pos1 = pos2 + delim.size();
		pos2 = str.find(delim, pos1);
	}
	if (pos1 != len)
		ret.emplace_back(str.substr(pos1));
}

void CSVReader::Log() 
{
	for (size_t i = 0; i < items.size(); i++)
	{
		items[i].Log();
	}
}