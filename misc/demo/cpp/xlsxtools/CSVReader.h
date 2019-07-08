#pragma once
#include <string>

using namespace std;

class CSVReader
{
public:
	CSVReader();
	~CSVReader();

public:
	bool LoadText(string textfileName, int skipLine);
};

