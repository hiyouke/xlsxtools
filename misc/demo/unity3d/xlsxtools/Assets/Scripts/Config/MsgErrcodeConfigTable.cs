using System.Collections;
using System.Collections.Generic;
public class MsgErrcodeConfig
{
	public	int	errcode;	//错误码
	public	string	en;	//英文名称
	public	string	ch;	//中文说明
}

public class MsgErrcodeConfigTable
{
	Dictionary<int, MsgErrcodeConfig> m_configs = new Dictionary<int,MsgErrcodeConfig>();
	public Dictionary<int, MsgErrcodeConfig> configs
	{
		get {
			return m_configs;
		}
	}

	public MsgErrcodeConfig GetConfigById(int cid)
	{
		if(m_configs.ContainsKey(cid)){
			return m_configs[cid];
		}
		return null;
	}

	public object ConfigProcess(string[] row)
	{
		if (row.Length < 3)
		{
			return null;
		}

		RowHelper rh = new RowHelper(row);
		MsgErrcodeConfig rec = new MsgErrcodeConfig();

		rec.errcode = CSVUtility.ToInt(rh.Read());	//错误码
		rec.en = rh.Read();	//英文名称
		rec.ch = rh.Read();	//中文说明
		return rec;
	}

	public void Load()
	{
		CSVReader reader = new CSVReader();
		reader.LoadText("Config/Msg_Errcode.txt", 3);
		int rows = reader.GetRowCount();
		for (int r = 0; r < rows; ++r)
		{
			string[] row = reader.GetRow(r);
			MsgErrcodeConfig ac = ConfigProcess(row) as MsgErrcodeConfig;
			configs.Add(ac.errcode, ac);
		}
	}
}
