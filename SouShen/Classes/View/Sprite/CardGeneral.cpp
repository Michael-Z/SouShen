#include "Config.h"
#include "CardGeneral.h"

CardGeneral::CardGeneral(UInt8 cValue, UInt8 color):CardBase(cValue, color),pSpriteZi(NULL), pSpriteHua(NULL), pSpriteGrain(NULL)
{
	drawCard();
}

CardGeneral::~CardGeneral()
{
	clearCard();
}

void CardNormal::setCardZiP()
{
	if (pSpriteZi)
	{
		pSpriteZi->setAnchorPoint(CCPoint(0, 0));         //set anchor point
		pSpriteZi->setPosition(CCPoint(0,70));            //set position
	}
}

void CardNormal::setCardHuaP()
{
	if (pSpriteHua)
	{
		pSpriteHua->setAnchorPoint(CCPoint(0, 0));         //set anchor point
		pSpriteHua->setPosition(CCPoint(0,40));            //set position
	}
}

void CardNormal::setCardGrainP()
{
	if (pSpriteGrain)
	{
		pSpriteGrain->setAnchorPoint(CCPoint(0, 0));         //set anchor point
		pSpriteGrain->setPosition(CCPoint(0,40));            //set position
	}
}

void CardGeneral::drawCard()
{
	UInt8 _keyValue = 0;
	if (cardValue >= 3 && cardValue <= 13)
	{
		_keyValue = cardValue-1;
	}
	else if (cardValue >= 14 && cardValue <= 15)
	{
		_keyValue = cardValue - 14;
	}
	else
	{
		//Logger
		LOGERROR<<"card Value error";
		return;

	}
	//draw card zi
	if (cardColor == 0 || cardColor == 1)
	{
		pSpriteZi = CCSprite::createWithSpriteFrameName(s_pNameListNormalCardRedZi[_keyValue].c_str());
		//set zi position
		setCardZiP();
	}
	else if (cardColor == 2 || cardColor == 3)
	{
		pSpriteZi = CCSprite::createWithSpriteFrameName(s_pNameListNormalCardBlackZi[_keyValue].c_str());
		//set zi position
		setCardZiP();
	}
	else
	{
		LOGERROR<<"card Color error";
	}

	if (cardColor >= 0 && cardColor <= 3)
	{
		//draw hua
		pSpriteHua = CCSprite::createWithSpriteFrameName(s_pNameListNormalCardHua[cardColor].c_str());
		setCardHuaP();

		//draw card background
		pSpriteGrain = CCSprite::createWithSpriteFrameName(s_pNameListNormalCardGrain[cardColor].c_str());
		setCardGrainP();
	}
	else
	{
		//Logger
		LOGERROR<<"card Color error";
		return;
	}
}
void CardGeneral::clearCard()
{
	this->removeChild(pSpriteZi, true);
	this->removeChild(pSpriteHua, true);
	this->removeChild(pSpriteGrain, true);
}