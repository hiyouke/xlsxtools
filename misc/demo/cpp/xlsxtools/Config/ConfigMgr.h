#pragma once
#include "MsgErrcodeConfigTable.h"
#include "MsgMsgConfigTable.h"
#include "ItemItemConfigTable.h"

class MsgErrcodeConfigTable;

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
	ItemItemConfigTable ItemItem;

	MsgErrcodeConfigTable MsgErrcode;

	MsgMsgConfigTable MsgMsg;
};

