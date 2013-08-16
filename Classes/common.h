#ifndef _COMMON_H_
#define  _COMMON_H_
//includes
#include "VisibleRect.h"
#include "cocos2d.h"
//namespaces
USING_NS_CC;
//defined
#define SPRITE(imageName) CCSprite::create(#imageName)
#define SPRITE_P(url) CCSprite::createWithSpriteFrameName(#url)

#endif