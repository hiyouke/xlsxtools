#include "stdafx.h"
#include "MsgErrcodeConfigTable.h"
#include "CSVReader.h"

map<int, MsgErrcodeConfig> & MsgErrcodeConfigTable::GetConfigs()
{
    return m_configs;
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
        m_configs.insert(std::make_pair(ac.id, ac));
    }
}

bool MsgErrcodeConfigTable::ConfigProcess(vector<string> fields, MsgErrcodeConfig & rec)
{
    if (fields.size() < 3)
    {
        return false;
    }
    int idx = 0;

	rec.id = stoi(fields[idx++]);//错误码
	rec.en = fields[idx++];//英文名称
	rec.ch = fields[idx++];//中文说明
    
    return true;
}
    