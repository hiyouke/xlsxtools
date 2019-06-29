package com.xlsxtools;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

public class ItemItemConfigTable
{
	public class ItemItemConfig
	{
		public	int		id;	//id
		public	String		name;	//名称
		public	String		desc;	//描述
		public	String		gain;	//获取途径
		public	int		type;	//类型
		public	int		overlap;	//叠加上限
		public	int		usetype;	//使用效果类型
		public	int[]		usevalue;	//使用效果值2
		public	int		use_times;	//使用次数限制
		public	int		cansell;	//是否可出售
		public	ItemItemSellConfig[]	sell;
		public	String		head;	//小图标
		public	String		model;	//模型
		public	int		star;	//星级
		public	int		linkid;	//关联id
	}

	public class ItemItemSellConfig
	{
		public int	id;	//出售获得物品1
		public int	num;	//出售获得物品数量1
	}
	
	private Map<Integer, ItemItemConfig> m_configs = new HashMap<Integer,ItemItemConfig>();
	public Map<Integer, ItemItemConfig> getConfigs()
	{
		return m_configs;
	}

	public void load() throws IOException
	{
		String path = this.getClass().getClassLoader().getResource("Config/Item_Item.txt").getPath();
		CSVReader reader = new CSVReader(path, 3, "#");
		while (reader.next()) {
			int index = 0;
			ItemItemConfig rec = new ItemItemConfig();

			rec.id = reader.getInt(index++);	//id
			rec.name = reader.getString(index++);	//名称
			rec.desc = reader.getString(index++);	//描述
			rec.gain = reader.getString(index++);	//获取途径
			rec.type = reader.getInt(index++);	//类型
			rec.overlap = reader.getInt(index++);	//叠加上限
			rec.usetype = reader.getInt(index++);	//使用效果类型
			rec.usevalue = new int[2];
			rec.usevalue[0] = reader.getInt(index++);	//使用效果值1
			rec.usevalue[1] = reader.getInt(index++);	//使用效果值2
			rec.use_times = reader.getInt(index++);	//使用次数限制
			rec.cansell = reader.getInt(index++);	//是否可出售
			rec.sell = new ItemItemSellConfig[2];
			for (int i = 0;i < 2;i ++) {
				rec.sell[i] = new ItemItemSellConfig();
			}
			rec.sell[0].id = reader.getInt(index++);	//出售获得物品1
			rec.sell[0].num = reader.getInt(index++);	//出售获得物品数量1
			rec.sell[1].id = reader.getInt(index++);	//出售获得物品2
			rec.sell[1].num = reader.getInt(index++);	//出售获得物品数量2
			rec.head = reader.getString(index++);	//小图标
			rec.model = reader.getString(index++);	//模型
			rec.star = reader.getInt(index++);	//星级
			rec.linkid = reader.getInt(index++);	//关联id
			m_configs.put(rec.id, rec);
		}
	}
}
