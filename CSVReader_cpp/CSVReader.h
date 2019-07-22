#pragma once
#include<string>
#include<vector>

using namespace std;

struct FieldData
{
	FieldData(vector<string> vals) {
		fields = vals;
	}

	void Log() 
	{
		for (size_t i = 0; i < fields.size(); i++)
		{
			printf("%s ", fields[i].c_str());
		}
		printf("\r");
	}

	vector<string> fields;
};

class CSVReader
{
public:
	CSVReader();
	~CSVReader();

public:
	size_t GetRowCount() { return m_items.size(); }

	vector<string> & GetRow(int idx){ return m_items[idx].fields; }

	bool LoadText(string textfileName, int skipLine);

	void ParseLine(string lineText);

	void Split(const string& str, const string& delim, vector<string> & res);


	void Log();

private:
	vector<FieldData> m_items;
};

