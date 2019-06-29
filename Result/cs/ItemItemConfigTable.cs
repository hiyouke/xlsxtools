using System.Collections;
using System.Collections.Generic;
public class ItemItemConfig
{
	public	int	id;	//id
	public	string	name;	//名称
	public	string	desc;	//描述
	public	string	gain;	//获取途径
	public	int	type;	//类型
	public	int	overlap;	//叠加上限
	public	int	usetype;	//使用效果类型
	public	int[]	usevalue;	//使用效果值2
	public	int	use_times;	//使用次数限制
	public	int	cansell;	//是否可出售
	public	ItemItemSellConfig[]	sell;
	public	string	head;	//小图标
	public	string	model;	//模型
	public	int	star;	//星级
	public	int	linkid;	//关联id
}

public class ItemItemSellConfig
{
	public int	id;	//出售获得物品1
	public int	num;	//出售获得物品数量1
}

public class ItemItemConfigTable
{
	Dictionary<int, ItemItemConfig> m_configs = new Dictionary<int,ItemItemConfig>();
	public Dictionary<int, ItemItemConfig> configs
	{
		get {
			return m_configs;
		}
	}

	public ItemItemConfig GetConfigById(int cid)
	{
		if(m_configs.ContainsKey(cid)){
			return m_configs[cid];
		}
		return null;
	}

	public object ConfigProcess(string[] row)
	{
		if (row.Length < 19)
		{
			return null;
		}

		RowHelper rh = new RowHelper(row);
		ItemItemConfig rec = new ItemItemConfig();

		rec.id = CSVUtility.ToInt(rh.Read());	//id
		rec.name = rh.Read();	//名称
		rec.desc = rh.Read();	//描述
		rec.gain = rh.Read();	//获取途径
		rec.type = CSVUtility.ToInt(rh.Read());	//类型
		rec.overlap = CSVUtility.ToInt(rh.Read());	//叠加上限
		rec.usetype = CSVUtility.ToInt(rh.Read());	//使用效果类型
		rec.usevalue = new int[2];
		rec.usevalue[0] = CSVUtility.ToInt(rh.Read());	//使用效果值1
		rec.usevalue[1] = CSVUtility.ToInt(rh.Read());	//使用效果值2
		rec.use_times = CSVUtility.ToInt(rh.Read());	//使用次数限制
		rec.cansell = CSVUtility.ToInt(rh.Read());	//是否可出售
		rec.sell = new ItemItemSellConfig[2];
		for (int i = 0;i < 2;i ++) {
			rec.sell[i] = new ItemItemSellConfig();
		}
		rec.sell[0].id = CSVUtility.ToInt(rh.Read());	//出售获得物品1
		rec.sell[0].num = CSVUtility.ToInt(rh.Read());	//出售获得物品数量1
		rec.sell[1].id = CSVUtility.ToInt(rh.Read());	//出售获得物品2
		rec.sell[1].num = CSVUtility.ToInt(rh.Read());	//出售获得物品数量2
		rec.head = rh.Read();	//小图标
		rec.model = rh.Read();	//模型
		rec.star = CSVUtility.ToInt(rh.Read());	//星级
		rec.linkid = CSVUtility.ToInt(rh.Read());	//关联id
		return rec;
	}

	public void Load()
	{
		CSVReader reader = new CSVReader();
		reader.LoadText("Config/Item_Item.txt", 3);
		int rows = reader.GetRowCount();
		for (int r = 0; r < rows; ++r)
		{
			string[] row = reader.GetRow(r);
			ItemItemConfig ac = ConfigProcess(row) as ItemItemConfig;
			configs.Add(ac.id, ac);
		}
	}
}
