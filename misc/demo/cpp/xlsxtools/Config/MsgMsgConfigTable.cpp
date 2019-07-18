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

	//������
	rec.id = stoi(fields[idx++]);

	//����
	rec.title = fields[idx++];	

	rec.content = fields[idx++];	//����

	for (int i = 0; i < 3; i++) {

		rec.sell.push_back(MsgMsgSellConfig());
	}

	
	rec.sell[0].id = stoi(fields[idx++]);	//���ۻ����Ʒ1

	rec.sell[0].num = stoi(fields[idx++]);	//���ۻ����Ʒ����1

	rec.sell[1].id = stoi(fields[idx++]);	//���ۻ����Ʒ2

	rec.sell[1].num = stoi(fields[idx++]);	//���ۻ����Ʒ����2

	rec.sell[2].id = stoi(fields[idx++]);	//���ۻ����Ʒ3

	rec.sell[2].num = stoi(fields[idx++]);	//���ۻ����Ʒ����3

	rec.instance.push_back(stoi(fields[idx++]));	//����1

	rec.instance.push_back(stoi(fields[idx++]));	//����1

	rec.instance.push_back(stoi(fields[idx++]));	//����1

	rec.instance.push_back(stoi(fields[idx++]));	//����1

	rec.remark = fields[idx++];	//��ע

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