#include "MainScene.h"

void MainScene::initStaticUI() {
    //背景图片
    CCSprite* sceneBG = SPRITE(images/startbj.jpg);
    sceneBG->setPosition(VisibleRect::center());
    addChild(sceneBG);
    //游戏名字
    CCSprite* bombermanName =SPRITE(images/name.png);
    bombermanName->setPosition(ccp(VisibleRect::top().x,VisibleRect::top().y-100));
    addChild(bombermanName);
}

void MainScene::initMenu() {
	//加载plist文件
	CCSpriteFrameCache* frameCache =CCSpriteFrameCache::sharedSpriteFrameCache();
	frameCache->addSpriteFramesWithFile("images/startlayer_tex.plist");
    CCMenuItemSprite* startMenu = CCMenuItemSprite::create(SPRITE_P(start_unpress.png),SPRITE_P(start_press.png),this,menu_selector(MainScene::startGameHandler));
    CCMenuItemSprite* exitMenu = CCMenuItemSprite::create(SPRITE_P(exit_unpress.png),SPRITE_P(exit_press.png),this,menu_selector(MainScene::startGameHandler));
	CCMenuItemSprite* helpMenu = CCMenuItemSprite::create(SPRITE_P(help_unpress.png),SPRITE_P(help_press.png),this,menu_selector(MainScene::startGameHandler));
	CCMenuItemSprite* moreMenu = CCMenuItemSprite::create(SPRITE_P(more_unpress.png),SPRITE_P(more_press.png),this,menu_selector(MainScene::startGameHandler));
	CCMenu* gameMenu = CCMenu::create(startMenu,helpMenu,moreMenu,exitMenu,NULL);
	gameMenu->alignItemsVerticallyWithPadding(5);
	gameMenu->setPosition(ccp(VisibleRect::right().x-100,VisibleRect::right().y));
	addChild(gameMenu);
	CCNode* settingNode = CCNode::create();
	CCMenuItemSprite* settingItem = CCMenuItemSprite::create(SPRITE_P(setting_unpress.png),SPRITE_P(setting_press.png));
	CCMenu* settingMenu = CCMenu::create(settingItem,NULL);
	settingNode->addChild(settingMenu);
	settingMenu->setPosition(CCPointZero);
	addChild(settingNode);
	settingNode->setPosition(ccp(82,VisibleRect::top().y-200));
}

bool MainScene::init() {
    do {
        CC_BREAK_IF(!CCLayer::init());
        initStaticUI();
        initMenu();
        return true;
    } while (0);
    return false;
}

CCScene* MainScene::scene() {
    CCScene* sceneWrapper = CCScene::create();
    MainScene* ms = MainScene::create();
    sceneWrapper->addChild(ms);
    return sceneWrapper;
}

void MainScene::exitGameHandler( CCObject* pSender ) {
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM==CC_PLATFORM_IOS)
    exit(0);
#endif
}

void MainScene::startGameHandler( CCObject* pSender ) {

}

