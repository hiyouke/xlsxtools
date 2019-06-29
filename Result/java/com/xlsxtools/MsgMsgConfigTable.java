package com.xlsxtools;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

public class MsgMsgConfigTable
{
	public class MsgMsgConfig
	{
		public	int		id;	//id
		public	String		title;	//标题
		public	String		content;	//内容
		public	MsgMsgSellConfig[]	sell;
		public	int[]		instance;	//副本1
		public	String		remark;	//备注
	}

	public class MsgMsgSellConfig
	{
		public int	id;	//出售获得物品1
		public int	num;	//出售获得物品数量1
	}
	
	private Map<Integer, MsgMsgConfig> m_configs = new HashMap<Integer,MsgMsgConfig>();
	public Map<Integer, MsgMsgConfig> getConfigs()
	{
		return m_configs;
	}

	public void load() throws IOException
	{
		String path = this.getClass().getClassLoader().getResource("Config/Msg_Msg.txt").getPath();
		CSVReader reader = new CSVReader(path, 3, "#");
		while (reader.next()) {
			int index = 0;
			MsgMsgConfig rec = new MsgMsgConfig();

			rec.id = reader.getInt(index++);	//id
			rec.title = reader.getString(index++);	//标题
			rec.content = reader.getString(index++);	//内容
			rec.sell = new MsgMsgSellConfig[3];
			for (int i = 0;i < 3;i ++) {
				rec.sell[i] = new MsgMsgSellConfig();
			}
			rec.sell[0].id = reader.getInt(index++);	//出售获得物品1
			rec.sell[0].num = reader.getInt(index++);	//出售获得物品数量1
			rec.sell[1].id = reader.getInt(index++);	//出售获得物品2
			rec.sell[1].num = reader.getInt(index++);	//出售获得物品数量2
			rec.sell[2].id = reader.getInt(index++);	//出售获得物品3
			rec.sell[2].num = reader.getInt(index++);	//出售获得物品数量3
			rec.instance = new int[4];
			rec.instance[0] = reader.getInt(index++);	//副本1
			rec.instance[1] = reader.getInt(index++);	//副本1
			rec.instance[2] = reader.getInt(index++);	//副本1
			rec.instance[3] = reader.getInt(index++);	//副本1
			rec.remark = reader.getString(index++);	//备注
			m_configs.put(rec.id, rec);
		}
	}
}
