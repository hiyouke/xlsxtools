import os
import os.path
rootdir = "./Result/java/com/xlsxtools"                                   

class_names = []
for parent,dirnames,filenames in os.walk(rootdir):
	for filename in filenames:
		if filename.find("ConfigTable.java") > 0:
			name = filename[0:len(filename)-len("ConfigTable.java")]
			# print "filename is:" + name
			class_names.append(name)

mgr_path = "./Result/java/com/xlsxtools/ConfigMgr.java"
mgr_file = open(mgr_path,'w')

# import headers
mgr_file.write("package com.xlsxtools;"+os.linesep+""+os.linesep+"")

# declare ConfigMgr
mgr_file.write("public class ConfigMgr "+os.linesep+"{"+os.linesep+"")
mgr_file.write("\tprivate static ConfigMgr mInstance = null;"+os.linesep+"")
mgr_file.write("\tpublic static ConfigMgr  GetInstance() "+os.linesep+"\t{ "+os.linesep+"\t\tif(null == mInstance)"+os.linesep+"\t\t{"+os.linesep+"\t\t\tmInstance = new ConfigMgr();"+os.linesep+"\t\t\tmInstance.Init(); "+os.linesep+"\t\t}"+os.linesep+"\t\treturn mInstance;"+os.linesep+"\t}"+os.linesep+"")

# declare config members 
for i in range(len(class_names)):
    name = class_names[i]
    mgr_file.write("\tpublic "+name+"ConfigTable\t"+name+" = null;"+os.linesep+"")

mgr_file.write(""+os.linesep+"")
mgr_file.write("\tpublic void Init () "+os.linesep+"\t{"+os.linesep+"")
mgr_file.write("\t\ttry"+os.linesep+"\t\t{"+os.linesep+"")

# load member instances
for i in range(len(class_names)):
    name = class_names[i]
    mgr_file.write("\t\t\t"+name+" = new "+name+"ConfigTable();"+os.linesep+"")
    mgr_file.write("\t\t\t"+name+".load();"+os.linesep+"")

mgr_file.write("\t\t}"+os.linesep+"")
mgr_file.write("\t\tcatch(Exception ex)"+os.linesep+"\t\t{"+os.linesep+"\t\t\tex.printStackTrace();"+os.linesep+"\t\t}"+os.linesep+"")
mgr_file.write("\t}"+os.linesep+"}")
mgr_file.close()