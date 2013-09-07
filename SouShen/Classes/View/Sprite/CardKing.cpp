#include "Config.h"
#include "CardKing.h"
#include "../../Utils/MobileLog.h"
#include "../GameResources.h"


CardKing::CardKing(UInt8 cValue, UInt8 color):CardBase(cValue, color), pSpriteHua(NULL), pSpriteGrain(NULL)
{

}

CardKing::~CardKing()
{

}

void CardKing::drawCard()
{
	UInt8 _keyValue = 0;

	if (cardValue >= 16 && cardValue <= 17)
	{
		_keyValue = cardValue - 16;
	}
	else
	{
		//Logger
		LOGERROR<<"card Value error";
		return;

	}

	if (cardColor >= 0 && cardColor <= 1)
	{
		//draw hua
		pSpriteHua = CCSprite::createWithSpriteFrameName(s_pNameListKingHua[cardColor].c_str());
		setCardHuaP();

		//draw card background
		pSpriteGrain = CCSprite::createWithSpriteFrameName(s_pNameListKingGrain[cardColor].c_str());
		setCardGrainP();
	}
	else
	{
		//Logger
		LOGERROR<<"card Color error";
		return;
	}
}
void CardKing::clearCard()
{

}

void CardKing::setCardHuaP()
{
	if (pSpriteHua)
	{
		pSpriteHua->setAnchorPoint(CCPoint(0, 0));         //set anchor point
		pSpriteHua->setPosition(CCPoint(0,40));            //set position
	}
}

void CardKing::setCardGrainP()
{
	if (pSpriteGrain)
	{
		pSpriteGrain->setAnchorPoint(CCPoint(0, 0));         //set anchor point
		pSpriteGrain->setPosition(CCPoint(0,40));            //set position
	}
}