#include "stdafx.h"
#include "MsgMsgConfigTable.h"
#include "CSVReader.h"


MsgMsgConfigTable::MsgMsgConfigTable()
{
}


MsgMsgConfigTable::~MsgMsgConfigTable()
{
}


map<int, MsgMsgConfig> & MsgMsgConfigTable::GetConfigs()
{
	return m_configs;
}

MsgMsgConfig * MsgMsgConfigTable::GetConfigById(int cid)
{
	if (m_configs.find(cid) != m_configs.end())
	{
		return &m_configs[cid];
	}
	return NULL;
}


bool MsgMsgConfigTable::ConfigProcess(vector<string> fields, MsgMsgConfig & rec)
{
	if (fields.size() < 14)
	{
		return false;
	}
	int idx = 0;

	//错误码
	rec.id = stoi(fields[idx++]);

	//标题
	rec.title = fields[idx++];	

	rec.content = fields[idx++];	//内容

	for (int i = 0; i < 3; i++) {

		rec.sell.push_back(MsgMsgSellConfig());
	}

	
	rec.sell[0].id = stoi(fields[idx++]);	//出售获得物品1

	rec.sell[0].num = stoi(fields[idx++]);	//出售获得物品数量1

	rec.sell[1].id = stoi(fields[idx++]);	//出售获得物品2

	rec.sell[1].num = stoi(fields[idx++]);	//出售获得物品数量2

	rec.sell[2].id = stoi(fields[idx++]);	//出售获得物品3

	rec.sell[2].num = stoi(fields[idx++]);	//出售获得物品数量3

	rec.instance.push_back(stoi(fields[idx++]));	//副本1

	rec.instance.push_back(stoi(fields[idx++]));	//副本1

	rec.instance.push_back(stoi(fields[idx++]));	//副本1

	rec.instance.push_back(stoi(fields[idx++]));	//副本1

	rec.remark = fields[idx++];	//备注

	return true;
}

void MsgMsgConfigTable::Load()
{
	CSVReader reader;
	reader.LoadText("Config/Msg_Msg.txt", 3);
	int rows = reader.GetRowCount();
	for (int r = 0; r < rows; ++r)
	{
		vector<string> row = reader.GetRow(r);
		MsgMsgConfig ac;
		ConfigProcess(row, ac);
		m_configs.insert(std::make_pair(ac.id, ac));
	}
}