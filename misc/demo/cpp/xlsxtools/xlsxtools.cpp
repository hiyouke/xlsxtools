// xlsxtools.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "CSVReader.h"
#include <stdlib.h>


int main()
{
	system("CHCP 65001");

	CSVReader reader = CSVReader();
	reader.LoadText("Msg_Errcode.txt",3);

	printf(u8"��������˳���");
	getchar();

    return 0;
}