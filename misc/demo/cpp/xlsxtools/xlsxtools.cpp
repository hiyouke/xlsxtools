// xlsxtools.cpp : �������̨Ӧ�ó������ڵ㡣
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

	cout << u8"��������˳���" << endl;
	getchar();

    return 0;
}