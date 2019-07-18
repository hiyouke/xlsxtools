// xlsxtools.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "CSVReader.h"
#include <stdlib.h>


int main()
{
	system("CHCP 65001");

	CSVReader reader = CSVReader();
	reader.LoadText("Msg_Errcode.txt",3);

	printf(u8"按任意键退出！");
	getchar();

    return 0;
}