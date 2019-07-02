using System.Collections;

public class ConfigMgr
{
	public static ConfigMgr  GetInstance() 
	{ 
		if(null == mInstance)
		{
			mInstance = new ConfigMgr();
			mInstance.Init(); 
		}
		return mInstance;
	}
	private static ConfigMgr mInstance = null;

	public ItemItemConfigTable	ItemItem;
	public MsgErrcodeConfigTable	MsgErrcode;
	public MsgMsgConfigTable	MsgMsg;

	public void Init () 
	{
		ItemItem = new ItemItemConfigTable();
		ItemItem.Load();
		MsgErrcode = new MsgErrcodeConfigTable();
		MsgErrcode.Load();
		MsgMsg = new MsgMsgConfigTable();
		MsgMsg.Load();

	}
}