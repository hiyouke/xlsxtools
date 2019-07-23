import os
import os.path

rootdir = "./Result/oc"

class_names = []
for parent, dirnames, filenames in os.walk(rootdir):
    for filename in filenames:
        if filename.find("ConfigTable.mm") > 0:
            name = filename[0:len(filename) - len("ConfigTable.mm")]
            # print "filename is:" + name
            class_names.append(name)

head_mgr_path = "./Result/oc/ConfigMgr.h"
head_mgr_file = open(head_mgr_path, 'w')
head_mgr_file.write('#pragma once\n')
for i in range(len(class_names)):
    head_mgr_file.write('#include "%sConfigTable.h"\n' % (class_names[i],))
head_mgr_file.write('''
class ConfigMgr
{
public:
    ConfigMgr();
    ~ConfigMgr();

public:
    static ConfigMgr * GetInstance();

public:
    void Init();

public:\n''')
for i in range(len(class_names)):
    head_mgr_file.write('\tNSDictionary *  %s;\n' % (class_names[i]))
head_mgr_file.write('};')

mgr_path = "./Result/oc/ConfigMgr.mm"
mgr_file = open(mgr_path, 'w')
# import headers
mgr_file.write('''#include "stdafx.h"
#include "ConfigMgr.h"

static ConfigMgr * mInstance = NULL;

ConfigMgr::ConfigMgr()
{
}


ConfigMgr::~ConfigMgr()
{
}


ConfigMgr * ConfigMgr::GetInstance() 
{
    if (NULL == mInstance)
    {
        mInstance = new ConfigMgr();
        mInstance->Init();
    }
    return mInstance;
}

void ConfigMgr::Init()
{\n''')
for i in range(len(class_names)):
    mgr_file.write('\t%s = [%sConfigTable configs];\n' % (class_names[i], class_names[i]))
mgr_file.write('}')
