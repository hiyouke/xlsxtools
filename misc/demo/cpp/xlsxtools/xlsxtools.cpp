// xlsxtools.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "CSVReader.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
	system("CHCP 65001");

	CSVReader reader = CSVReader();
	reader.LoadText("Msg_Errcode.txt",3);

	cout << u8"按任意键退出！" << endl;
	getchar();

    return 0;
}