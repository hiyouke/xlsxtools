// xlsxtools.cpp : 定义控制台应用程序的入口点。
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


	//CSVReader reader = CSVReader();
	//reader.LoadText("Msg_Errcode.txt",3);


	map<int, MsgErrcodeConfig> configs = ConfigMgr::GetInstance()->MsgErrcode.GetConfigs();
	for(map<int, MsgErrcodeConfig>::iterator item = configs.begin();item != configs.end();item++)
	{
		printf("key : %d value : %s\r", item->first,item->second.ch.c_str());
	}


	printf(u8"按任意键退出！");
	getchar();

    return 0;
}