#include "Config.h"
#include "CardBase.h"
#include "../GameResources.h"

CardBase::CardBase(UInt8 cValue, UInt8 color):CCNode(), cardValue(cValue), cardColor(color)
{

}
CardBase::~CardBase()
{

}
void CardBase::drawCard()
{
	CCSpriteFrameCache *cache = CCSpriteFrameCache::sharedSpriteFrameCache();
	cache->addSpriteFramesWithFile(s_pPlistDDZMainGame0);
	//backGround = CCSprite::createWithSpriteFrameName(s_pNameCardBackGround);
	//this->addChild(backGround);
	//backGround->autorelease();


	cache->addSpriteFramesWithFile("Images/animation/chooserole/mt/skill_tenarmy.plist");


	CCSprite *plistSprite=CCSprite::createWithSpriteFrameName("tenarmy_01.png");
	this->addChild(plistSprite);
}

void CardBase::clearCard()
{
	this->removeChild(backGround, true);
}