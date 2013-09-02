#ifndef _CARDBASE_H_
#define _CARDBASE_H_

#include "cocos2d.h"
USING_NS_CC;
class CardBase : public CCNode
{
public:
	CardBase(UInt8 cValue, UInt8 color); //card value , card color
	virtual ~CardBase();
public:
	virtual void drawCard();
	virtual void clearCard();
	inline CCSprite* getCardBackGround() { return backGround; }
	inline UInt8 getCardValue() { return cardValue; }
	inline UInt8 getCardColor() { return cardColor; }
protected:
	CCSprite *backGround;
protected:
	UInt8 cardValue;
	UInt8 cardColor;
};

#endif