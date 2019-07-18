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

	//����
	string	title;

	//����
	string	content;

	vector<MsgMsgSellConfig> sell;

	//����1
	vector<int>	instance;

	//��ע
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

