#include "Config.h"
#include "CardBase.h"
#include "../GameResources.h"

CardBase::CardBase(UInt8 cValue, UInt8 color):CCNode(), cardValue(cValue), cardColor(color)
{
	drawCard();
}
CardBase::~CardBase()
{
	clearCard();
}
void CardBase::drawCard()
{
	CCSpriteFrameCache *cache = CCSpriteFrameCache::sharedSpriteFrameCache();
	cache->addSpriteFramesWithFile(s_pPlistDDZMainGame0);
	backGround = CCSprite::createWithSpriteFrameName(s_pNameCardBackGround);
	this->addChild(backGround);
	//backGround->autorelease();

	//cache->addSpriteFramesWithFile("Images/animation/chooserole/mt/chooserole_mt_part1.plist");
	//backGround=CCSprite::createWithSpriteFrameName("mt_0001.png");
	//this->addChild(backGround);
}

void CardBase::clearCard()
{
	this->removeChild(backGround, true);
}