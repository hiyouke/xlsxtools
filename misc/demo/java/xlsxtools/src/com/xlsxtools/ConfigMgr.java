package com.xlsxtools;

public class ConfigMgr 
{
	private static ConfigMgr mInstance = null;
	public static ConfigMgr  GetInstance() 
	{ 
		if(null == mInstance)
		{
			mInstance = new ConfigMgr();
			mInstance.Init(); 
		}
		return mInstance;
	}
	public ItemItemConfigTable	ItemItem = null;
	public MsgErrcodeConfigTable	MsgErrcode = null;
	public MsgMsgConfigTable	MsgMsg = null;

	public void Init () 
	{
		try
		{
			ItemItem = new ItemItemConfigTable();
			ItemItem.load();
			MsgErrcode = new MsgErrcodeConfigTable();
			MsgErrcode.load();
			MsgMsg = new MsgMsgConfigTable();
			MsgMsg.load();
		}
		catch(Exception ex)
		{
			ex.printStackTrace();
		}
	}
}