#pragma once
#include<string>
#include<vector>
#include<map>

using namespace std;


struct MsgErrcodeConfig
{
	int id;//错误码
	string en;//英文名称
	string ch;//中文说明
};

class MsgErrcodeConfigTable
{
private:
	map<int, MsgErrcodeConfig> m_configs;
public:
	map<int, MsgErrcodeConfig> & GetConfigs();
	MsgErrcodeConfig GetConfigById(int cid);
	void Load();

	bool ConfigProcess(vector<string> fields, MsgErrcodeConfig & rec);
};