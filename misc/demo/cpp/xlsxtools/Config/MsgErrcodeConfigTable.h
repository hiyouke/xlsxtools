#pragma once
#include<string>
#include<vector>
#include<map>

using namespace std;

struct MsgErrcodeConfig
{
	int errcode;

	string en;

	string ch;
};

class MsgErrcodeConfigTable
{
public:
	MsgErrcodeConfigTable();
	~MsgErrcodeConfigTable();

public:
	map<int, MsgErrcodeConfig> & GetConfigs();
	MsgErrcodeConfig * GetConfigById(int cid);

	bool ConfigProcess(vector<string> fields, MsgErrcodeConfig & rec);

	void Load();

private:
	map<int, MsgErrcodeConfig> m_configs;
};

