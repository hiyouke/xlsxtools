
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
{
	ItemItem = [ItemItemConfigTable configs];
	MsgErrcode = [MsgErrcodeConfigTable configs];
	MsgMsg = [MsgMsgConfigTable configs];
}