#pragma once
#include "MsgErrcodeConfigTable.h"

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
	MsgErrcodeConfigTable MsgErrcode;
};

