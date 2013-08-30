#ifndef _CARDBASE_H_
#define _CARDBASE_H_
class CardBase : public CCNode
{
public:
	CardBase(uint8_t cValue, uint8_t color); //card value , card color
protected:
	CCSprite backGround;
protected:
	uint8_t cardValue;
	uint8_t cardColor;
};

#endif