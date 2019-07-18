#pragma once
#include<string>
#include<vector>
#include<map>

using namespace std;


struct MsgMsgSellConfig
{
	int	id;

	int	num;
};

struct MsgMsgConfig
{
	int	id;

	//标题
	string	title;

	//内容
	string	content;

	vector<MsgMsgSellConfig> sell;

	//副本1
	vector<int>	instance;

	//备注
	string	remark;
};

class MsgMsgConfigTable
{
public:
	MsgMsgConfigTable();
	~MsgMsgConfigTable();

public:
	map<int, MsgMsgConfig> & GetConfigs();
	MsgMsgConfig * GetConfigById(int cid);

	bool ConfigProcess(vector<string> fields, MsgMsgConfig & rec);

	void Load();

private:
	map<int, MsgMsgConfig> m_configs;
};

