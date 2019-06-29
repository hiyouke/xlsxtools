package com.xlsxtools;

import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

public class MsgConfigCache {

	public class MsgConfig {
		public int id;
		public String title;
		public String content;
		public String a[];
		public MsgConfigSell b[];
	}

	public class MsgConfigSell
	{
		public int id;
		public int num;
	}
	
	private Map<Integer, MsgConfig> msgConfigMap = new HashMap<Integer, MsgConfig>();

	public Map<Integer, MsgConfig> getMsgConfigMap() {
		return msgConfigMap;
	}

	public void load() throws IOException {
		// 获取reader
		CSVReader reader = new CSVReader("./Config/Msg_msg.txt", 3, "#");
		while (reader.next()) {
			int index = 0;
			MsgConfig msg = new MsgConfig();
            msg.id = reader.getInt(index++);
            msg.title = reader.getString(index++);
            msg.content = reader.getString(index++);
            msg.a = new String[10];
            for(int i=0;i<10;i++)
            {
                msg.a[i] = reader.getString(index++);
            }
            msg.b = new MsgConfigSell[12];
            for(int i=0;i<12;i++)
            {
                msg.b[i] = new MsgConfigSell();
                msg.b[i].id = reader.getInt(index++);
                msg.b[i].num = reader.getInt(index++);
            }
            
			msgConfigMap.put(msg.id, msg);
		}
	}
}
