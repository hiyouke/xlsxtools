﻿#xlsxtools
xlsxtools游戏配置表工具，开源跨平台，支持多语言。Unity3D等游戏引擎使用Excel做游戏配置表的解决方案，将xlsx文件转换成txt文本文件，并生成解析代码的工具。已支持C#，Java，即将支持C，C++，OC等。

一、开源地址

    1.git oschina地址：https://git.oschina.net/youke/xlsxtools.git
	
二、简介

      1.xlsxtools是一个将xlsx文件转换成txt文本文件，并生成解析代码的工具

      2.xlsxtools使用python脚本开发，能快速实现跨平台功能

      3.目前支持生成C#，Java语言，C，C++，OC正在开发中

      4.结合Jenkins，可以实现一键转化，自动同步。

三、参与人员

    星仔(QQ:197279437),卡哇(QQ:240886393)

四、xlsxtools环境搭建
	1.安装Python,推荐使用2.7.10（已安装略过）
	
	2.安装Python插件setuptools（已安装略过）
	
		a.xlsxtools/zip目录下,推荐setuptools-7.0.zip
		
		b.执行sudo python setup.py install
		
	3.安装Python插件openpyxl（已安装略过）
	
		a. xlsxtools/zip目录下,推荐openpyxl_1.7.0.zip
		
		b.执行sudo python setup.py install
		
	4.执行sh batch_trans.sh转换支持语言代码

五、详细使用过程，参考README.docx		