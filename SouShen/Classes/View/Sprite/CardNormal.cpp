#include "Config.h"
#include "CardNormal.h"
#include "../../Utils/MobileLog.h"

CardNormal::CardNormal(UInt8 cValue, UInt8 color):CardBase(cValue, color),pSpriteZi(NULL), pSpriteHua(NULL), pSpriteGrain(NULL)
{

}

CardNormal::~CardNormal()
{

}

void CardNormal::drawCard()
{
	if (cardColor == 0 || cardColor == 1)
	{
		UInt8 _keyValue = 0;
		if (cardValue >= 3 && cardValue <= 13)
		{
			_keyValue = cardValue - 1;
		}
		else if (cardValue >= 14 && cardValue <= 15)
		{
			_keyValue = cardValue - 14;
		}
		else
		{
			//Logger
			MBLOG->prolog(LogError);
			
		}
		//pSpriteZi = CCSprite::createWithSpriteFrameName()
	}
	else if (cardColor == 2 || cardColor == 3)
	{
	//	pSpriteZi = CCSprite::createWithSpriteFrameName()
	}
}
void CardNormal::clearCard()
{

}