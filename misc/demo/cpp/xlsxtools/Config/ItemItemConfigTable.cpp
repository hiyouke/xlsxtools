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

	rec.name = fields[idx++];	//����

	rec.desc = fields[idx++];	//����

	rec.gain = fields[idx++];	//��ȡ;��

	rec.type = stoi(fields[idx++]);;	//����

	rec.overlap = stoi(fields[idx++]);	//��������

	rec.usetype = stoi(fields[idx++]);;	//ʹ��Ч������

	rec.usevalue.push_back(stoi(fields[idx++]));	//ʹ��Ч��ֵ1

	rec.usevalue.push_back(stoi(fields[idx++]));	//ʹ��Ч��ֵ2

	rec.use_times = stoi(fields[idx++]);	//ʹ�ô�������

	rec.cansell = stoi(fields[idx++]);	//�Ƿ�ɳ���


	for (int i = 0; i < 2; i++) {

		rec.sell.push_back(ItemItemSellConfig());

	}

	rec.sell[0].id = stoi(fields[idx++]);	//���ۻ����Ʒ1

	rec.sell[0].num = stoi(fields[idx++]);	//���ۻ����Ʒ����1

	rec.sell[1].id = stoi(fields[idx++]);	//���ۻ����Ʒ2

	rec.sell[1].num = stoi(fields[idx++]);	//���ۻ����Ʒ����2

	rec.head = fields[idx++];	//Сͼ��

	rec.model = fields[idx++];	//ģ��

	rec.star = stoi(fields[idx++]);	//�Ǽ�

	rec.linkid = stoi(fields[idx++]);	//����id

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