#ifndef _TPLAYER_H_
#define _TPLAYER_H_
class Tplayer
{
public:
	Tplayer();
	virtual ~Tplayer();
	virtual void updateHandCards() {}
	virtual void updatePutCards() {}
	virtual void init() {}
	virtual void reInit() {}
	virtual void addCard(int nCard, int x, int y);
	virtual void playAni(int nAni);
	virtual void drawPlayerInfo();
public:
	void setUserData();
	void getUserData();
};


class LeftTplayer : public Tplayer
{

};

class TopTplayer : public Tplayer
{

};

class RightTplayer : public Tplayer
{

};

class SelfTplayer : public Tplayer
{
public:
	SelfTplayer();
	~SelfTplayer();

};

#endif