#pragma once
#include "ItemItemConfigTable.h"
#include "MsgErrcodeConfigTable.h"
#include "MsgMsgConfigTable.h"

class ConfigMgr
{
public:
    ConfigMgr();
    ~ConfigMgr();

public:
    static ConfigMgr * GetInstance();

public:
    void Init();

public:
	NSDictionary *  ItemItem;
	NSDictionary *  MsgErrcode;
	NSDictionary *  MsgMsg;
};