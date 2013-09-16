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

void CardBase::onEnter()
{
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, kCCMenuHandlerPriority, true);
	CCNode::onEnter();
}

void CardBase::onExit()
{
	CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);  
	CCNode::onExit();  
}


bool CardBase::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
	ccDrawColor4B(255,0,0,255);
	CCPoint vertices[] = { ccp(0, 0), ccp(50, 50), ccp(100, 50), ccp(100, 100) };
	ccDrawPoly(vertices, 4, true);
	
	ccColor3B b;
	b.r = 255;
	b.g = 0;
	b.b = 0;
	backGround->setColor(b);
	CCLog("ccTouchBegan");
	return true;
}
void CardBase::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
	CCLog("ccTouchMoved");
}
void CardBase::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
	ccColor3B b;
	b.r = 255;
	b.g = 255;
	b.b = 255;
	backGround->setColor(b);
	CCLog("ccTouchEnded");
}