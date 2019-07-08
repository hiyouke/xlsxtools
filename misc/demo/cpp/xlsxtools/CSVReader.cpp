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
	char lineContent[1024] = { 0 };
	int lineCount = 1;
	while (!feof(fp))
	{
		fgets(lineContent, 1024, fp);
		printf("line :%d %s", lineCount++, lineContent);
	}
	fclose(fp);

	return true;
}
