#pragma once
#include<string>
#include<vector>
#include<map>

using namespace std;

struct ItemItemSellConfig
{
	int	id;	//出售获得物品1
	int	num;	//出售获得物品数量1
};


struct ItemItemConfig
{
	int id;//id
	string name;//名称
	string desc;//描述
	string gain;//获取途径
	int type;//类型
	int overlap;//叠加上限
	int usetype;//使用效果类型
	vector<int> usevalue;//使用效果值2
	int use_times;//使用次数限制
	int cansell;//是否可出售
	vector<ItemItemSellConfig> sell;
	string head;//小图标
	string model;//模型
	int star;//星级
	int linkid;//关联id
};

class ItemItemConfigTable
{
private:
	map<int, ItemItemConfig> m_configs;
public:
	map<int, ItemItemConfig> & GetConfigs();
	ItemItemConfig GetConfigById(int cid);
	void Load();

	bool ConfigProcess(vector<string> fields, ItemItemConfig & rec);
};