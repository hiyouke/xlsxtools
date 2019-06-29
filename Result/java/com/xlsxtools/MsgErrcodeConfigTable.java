package com.xlsxtools;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

public class MsgErrcodeConfigTable
{
	public class MsgErrcodeConfig
	{
		public	int		errcode;	//错误码
		public	String		en;	//英文名称
		public	String		ch;	//中文说明
	}
	
	private Map<Integer, MsgErrcodeConfig> m_configs = new HashMap<Integer,MsgErrcodeConfig>();
	public Map<Integer, MsgErrcodeConfig> getConfigs()
	{
		return m_configs;
	}

	public void load() throws IOException
	{
		String path = this.getClass().getClassLoader().getResource("Config/Msg_Errcode.txt").getPath();
		CSVReader reader = new CSVReader(path, 3, "#");
		while (reader.next()) {
			int index = 0;
			MsgErrcodeConfig rec = new MsgErrcodeConfig();

			rec.errcode = reader.getInt(index++);	//错误码
			rec.en = reader.getString(index++);	//英文名称
			rec.ch = reader.getString(index++);	//中文说明
			m_configs.put(rec.errcode, rec);
		}
	}
}
