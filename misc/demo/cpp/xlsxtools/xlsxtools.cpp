// xlsxtools.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdlib.h>
#include<map>
#include "Config/CSVReader.h"
#include "Config/ConfigMgr.h"

using namespace std;

int main()
{
	system("CHCP 65001");

	printf(u8"\r\n");

	map<int, ItemItemConfig> configs0 = ConfigMgr::GetInstance()->ItemItem.GetConfigs();
	printf("ItemItemConfig size : %d\r\n",configs0.size());
	for (map<int, ItemItemConfig>::iterator item0 = configs0.begin(); item0 != configs0.end(); item0++)
	{
		printf("ItemItemConfig id : %d name : %s\r\n", item0->second.id, item0->second.name.c_str());
	}
	printf(u8"\r\n");

	map<int, MsgErrcodeConfig> configs1 = ConfigMgr::GetInstance()->MsgErrcode.GetConfigs();
	printf("MsgErrcodeConfig size : %d\r\n", configs1.size());
	for(map<int, MsgErrcodeConfig>::iterator item = configs1.begin();item != configs1.end();item++)
	{
		printf("MsgErrcodeConfig key : %d value : %s\r\n", item->first,item->second.ch.c_str());
	}

	printf(u8"\r\n");

	map<int, MsgMsgConfig> configs2 = ConfigMgr::GetInstance()->MsgMsg.GetConfigs();
	printf("MsgMsgConfig size : %d\r\n", configs2.size());
	for (map<int, MsgMsgConfig>::iterator item = configs2.begin(); item != configs2.end(); item++)
	{
		printf("MsgMsgConfig key : %d value : %s\r\n", item->first,item->second.content.c_str());
	}

	printf(u8"\n��������˳���");
	getchar();

    return 0;
}