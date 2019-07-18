#include "stdafx.h"
#include "MsgErrcodeConfigTable.h"
#include "CSVReader.h"

MsgErrcodeConfigTable::MsgErrcodeConfigTable()
{
}


MsgErrcodeConfigTable::~MsgErrcodeConfigTable()
{
}

map<int, MsgErrcodeConfig> & MsgErrcodeConfigTable::GetConfigs()
{
	return m_configs;
}

MsgErrcodeConfig * MsgErrcodeConfigTable::GetConfigById(int cid)
{
	if (m_configs.find(cid) != m_configs.end())
	{
		return &m_configs[cid];
	}
	return NULL;
}


bool MsgErrcodeConfigTable::ConfigProcess(vector<string> fields, MsgErrcodeConfig & rec)
{
	if (fields.size() < 3)
	{
		return false;
	}

	int idx = 0;
	rec.errcode = stoi(fields[idx]);//错误码
	idx++;
	rec.en = fields[idx];	//英文名称
	idx++;
	rec.ch = fields[idx++];	//中文说明

	return true;
}

void MsgErrcodeConfigTable::Load()
{
	CSVReader reader;
	reader.LoadText("Config/Msg_Errcode.txt", 3);
	int rows = reader.GetRowCount();
	for (int r = 0; r < rows; ++r)
	{
		vector<string> row = reader.GetRow(r);
		MsgErrcodeConfig ac;
		ConfigProcess(row, ac);
		m_configs.insert(std::make_pair(ac.errcode, ac));
	}
}