#ifndef _MAINSCENE_H_
#define _MAINSCENE_H_

#include "common.h"

class MainScene:public CCLayer{
public:
	CREATE_FUNC(MainScene);
	virtual bool init();
	static CCScene* scene();

public:
	void initMenu();
	void initStaticUI();
public:
	void exitGameHandler(CCObject* pSender);
	void startGameHandler(CCObject* pSender);
	void gameHelpHandler(CCObject* pSender);
	void soundSettingHandler(CCObject* pSender);
	void shareHandler(CCObject* pSender);
};

#endif