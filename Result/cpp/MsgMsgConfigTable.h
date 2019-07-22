#pragma once
#include<string>
#include<vector>
#include<map>

using namespace std;

struct MsgMsgSellConfig
{
	int	id;	//出售获得物品1
	int	num;	//出售获得物品数量1
};


struct MsgMsgConfig
{
	int id;//id
	string title;//标题
	string content;//内容
	vector<MsgMsgSellConfig> sell;
	vector<int> instance;//副本1
	string remark;//备注
};

class MsgMsgConfigTable
{
private:
	map<int, MsgMsgConfig> m_configs;
public:
	map<int, MsgMsgConfig> & GetConfigs();
	MsgMsgConfig GetConfigById(int cid);
	void Load();

	bool ConfigProcess(vector<string> fields, MsgMsgConfig & rec);
};