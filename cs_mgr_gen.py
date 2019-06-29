import os
import os.path
rootdir = "./Result/cs"                                   

class_names = []
for parent,dirnames,filenames in os.walk(rootdir):
	for filename in filenames:
		if filename.find("ConfigTable.cs") > 0:
			name = filename[0:len(filename)-len("ConfigTable.cs")]
			# print "filename is:" + name
			class_names.append(name)

mgr_path = "./Result/cs/ConfigMgr.cs"
mgr_file = open(mgr_path,'w')
# import headers
mgr_file.write("using System.Collections;"+os.linesep+""+os.linesep+"public class ConfigMgr"+os.linesep+"{"+os.linesep+"\tpublic static ConfigMgr  GetInstance() "+os.linesep+"\t{ "+os.linesep+"\t\tif(null == mInstance)"+os.linesep+"\t\t{"+os.linesep+"\t\t\tmInstance = new ConfigMgr();"+os.linesep+"\t\t\tmInstance.Init(); "+os.linesep+"\t\t}"+os.linesep+"\t\treturn mInstance;"+os.linesep+"\t}"+os.linesep+"\tprivate static ConfigMgr mInstance = null;"+os.linesep+""+os.linesep+"")

# declare config members 
for i in range(len(class_names)):
    name = class_names[i]
    mgr_file.write("\tpublic "+name+"ConfigTable\t"+name+";"+os.linesep+"")
mgr_file.write(""+os.linesep+"")
mgr_file.write("\tpublic void Init () "+os.linesep+"\t{"+os.linesep+"")

# load member instances
for i in range(len(class_names)):
    name = class_names[i]
    mgr_file.write("\t\t"+name+" = new "+name+"ConfigTable();"+os.linesep+"")
    mgr_file.write("\t\t"+name+".Load();"+os.linesep)
mgr_file.write(""+os.linesep+"\t}"+os.linesep+"}")
mgr_file.close()