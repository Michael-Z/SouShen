#ifndef _CCARD_H_
#define _CCARD_H_
#include "CardNormal.h"
#include "CardGeneral.h"
#include "CardKing.h"
class CCard
{
public:
	CCard() : m_nColor(-1), m_nValue(-1), cardSprite(NULL) {}
	CCard(int nColor, int nValue) : m_nColor(nColor), m_nValue(nValue) {}
	CCard (const CCard &srcCard)
	{
		if(this == &srcCard)
			return;
		m_nColor = srcCard.m_nColor;
		m_nValue = srcCard.m_nValue;
	}
	CCard& operator = (const CCard &srcCard)
	{
		if (this == &srcCard)
			return *this;
		m_nColor = srcCard.m_nColor;
		m_nValue = srcCard.m_nValue;
		return *this;
	}
	bool operator == (const CCard &srcCard)
	{
		return (m_nColor == srcCard.m_nColor && m_nValue == srcCard.m_nValue);
	}
public:
	CardBase* getCardSprite()
	{
		if (cardSprite != NULL)
		{
			return cardSprite;
		}
		else
		{
			if ((m_nValue >= 3 && m_nValue <= 10) || m_nValue == 14 || m_nValue == 15 )
			{
				cardSprite = new CardNormal(m_nValue, m_nColor);
			}
			else if (m_nValue>= 11 && m_nValue<= 13)
			{
				cardSprite = new CardGeneral(m_nValue, m_nColor);
			}
			else if (m_nValue == 16 || m_nValue == 17)
			{
				cardSprite = new CardKing(m_nValue, m_nColor);
			}
			return cardSprite;
		}
	}
public:
	char m_nColor;  //花色,-1表示没有任意花色
	char m_nValue;  //数值,-1表示还没有牌
private:
	CardBase *cardSprite;
};

#endif