#include "stdafx.h"
#include "ItemItemConfigTable.h"
#include "CSVReader.h"


ItemItemConfigTable::ItemItemConfigTable()
{
}


ItemItemConfigTable::~ItemItemConfigTable()
{
}


map<int, ItemItemConfig> & ItemItemConfigTable::GetConfigs()
{
	return m_configs;
}

ItemItemConfig * ItemItemConfigTable::GetConfigById(int cid)
{
	if (m_configs.find(cid) != m_configs.end())
	{
		return &m_configs[cid];
	}
	return NULL;
}


bool ItemItemConfigTable::ConfigProcess(vector<string> fields, ItemItemConfig & rec)
{
	if (fields.size() < 19)

	{

		return false;

	}


	int idx = 0;


	rec.id = stoi(fields[idx++]);	//id

	rec.name = fields[idx++];	//名称

	rec.desc = fields[idx++];	//描述

	rec.gain = fields[idx++];	//获取途径

	rec.type = stoi(fields[idx++]);;	//类型

	rec.overlap = stoi(fields[idx++]);	//叠加上限

	rec.usetype = stoi(fields[idx++]);;	//使用效果类型

	rec.usevalue.push_back(stoi(fields[idx++]));	//使用效果值1

	rec.usevalue.push_back(stoi(fields[idx++]));	//使用效果值2

	rec.use_times = stoi(fields[idx++]);	//使用次数限制

	rec.cansell = stoi(fields[idx++]);	//是否可出售


	for (int i = 0; i < 2; i++) {

		rec.sell.push_back(ItemItemSellConfig());

	}

	rec.sell[0].id = stoi(fields[idx++]);	//出售获得物品1

	rec.sell[0].num = stoi(fields[idx++]);	//出售获得物品数量1

	rec.sell[1].id = stoi(fields[idx++]);	//出售获得物品2

	rec.sell[1].num = stoi(fields[idx++]);	//出售获得物品数量2

	rec.head = fields[idx++];	//小图标

	rec.model = fields[idx++];	//模型

	rec.star = stoi(fields[idx++]);	//星级

	rec.linkid = stoi(fields[idx++]);	//关联id

	return true;
}

void ItemItemConfigTable::Load()
{
	CSVReader reader;
	reader.LoadText("Config/Item_Item.txt", 3);
	int rows = reader.GetRowCount();
	for (int r = 0; r < rows; ++r)
	{
		vector<string> row = reader.GetRow(r);
		ItemItemConfig ac;
		ConfigProcess(row, ac);
		m_configs.insert(std::make_pair(ac.id, ac));
	}
}