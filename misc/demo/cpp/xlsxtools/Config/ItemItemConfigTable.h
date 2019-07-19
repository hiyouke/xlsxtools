#pragma once
#include<string>
#include<vector>
#include<map>

using namespace std;


struct ItemItemSellConfig
{
	 int	id;	//���ۻ����Ʒ1
	 int	num;	//���ۻ����Ʒ����1
};

struct ItemItemConfig
{
		int	id;	//id
		string	name;	//����
		string	desc;	//����
		string	gain;	//��ȡ;��
		int	type;	//����
		int	overlap;	//��������
		int	usetype;	//ʹ��Ч������
		vector<int>	usevalue;	//ʹ��Ч��ֵ2
		int	use_times;	//ʹ�ô�������
		int	cansell;	//�Ƿ�ɳ���
		vector<ItemItemSellConfig>	sell;
		string	head;	//Сͼ��
		string	model;	//ģ��
		int	star;	//�Ǽ�
		int	linkid;	//����id
};


class ItemItemConfigTable
{
public:
	ItemItemConfigTable();
	~ItemItemConfigTable();

public:
	map<int, ItemItemConfig> & GetConfigs();
	ItemItemConfig * GetConfigById(int cid);

	bool ConfigProcess(vector<string> fields, ItemItemConfig & rec);

	void Load();

private:
	map<int, ItemItemConfig> m_configs;
};

