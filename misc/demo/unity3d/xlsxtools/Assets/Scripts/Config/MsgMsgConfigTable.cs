using System.Collections;
using System.Collections.Generic;
public class MsgMsgConfig
{
	public	int	id;	//id
	public	string	title;	//标题
	public	string	content;	//内容
	public	MsgMsgSellConfig[]	sell;
	public	int[]	instance;	//副本1
	public	string	remark;	//备注
}

public class MsgMsgSellConfig
{
	public int	id;	//出售获得物品1
	public int	num;	//出售获得物品数量1
}

public class MsgMsgConfigTable
{
	Dictionary<int, MsgMsgConfig> m_configs = new Dictionary<int,MsgMsgConfig>();
	public Dictionary<int, MsgMsgConfig> configs
	{
		get {
			return m_configs;
		}
	}

	public MsgMsgConfig GetConfigById(int cid)
	{
		if(m_configs.ContainsKey(cid)){
			return m_configs[cid];
		}
		return null;
	}

	public object ConfigProcess(string[] row)
	{
		if (row.Length < 14)
		{
			return null;
		}

		RowHelper rh = new RowHelper(row);
		MsgMsgConfig rec = new MsgMsgConfig();

		rec.id = CSVUtility.ToInt(rh.Read());	//id
		rec.title = rh.Read();	//标题
		rec.content = rh.Read();	//内容
		rec.sell = new MsgMsgSellConfig[3];
		for (int i = 0;i < 3;i ++) {
			rec.sell[i] = new MsgMsgSellConfig();
		}
		rec.sell[0].id = CSVUtility.ToInt(rh.Read());	//出售获得物品1
		rec.sell[0].num = CSVUtility.ToInt(rh.Read());	//出售获得物品数量1
		rec.sell[1].id = CSVUtility.ToInt(rh.Read());	//出售获得物品2
		rec.sell[1].num = CSVUtility.ToInt(rh.Read());	//出售获得物品数量2
		rec.sell[2].id = CSVUtility.ToInt(rh.Read());	//出售获得物品3
		rec.sell[2].num = CSVUtility.ToInt(rh.Read());	//出售获得物品数量3
		rec.instance = new int[4];
		rec.instance[0] = CSVUtility.ToInt(rh.Read());	//副本1
		rec.instance[1] = CSVUtility.ToInt(rh.Read());	//副本1
		rec.instance[2] = CSVUtility.ToInt(rh.Read());	//副本1
		rec.instance[3] = CSVUtility.ToInt(rh.Read());	//副本1
		rec.remark = rh.Read();	//备注
		return rec;
	}

	public void Load()
	{
		CSVReader reader = new CSVReader();
		reader.LoadText("Config/Msg_Msg.txt", 3);
		int rows = reader.GetRowCount();
		for (int r = 0; r < rows; ++r)
		{
			string[] row = reader.GetRow(r);
			MsgMsgConfig ac = ConfigProcess(row) as MsgMsgConfig;
			configs.Add(ac.id, ac);
		}
	}
}
