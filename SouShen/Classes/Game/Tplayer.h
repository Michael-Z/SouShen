#ifndef _TPLAYER_H_
#define _TPLAYER_H_
class Tplayer
{
public:
	Tplayer();
	virtual ~Tplayer();
	virtual void UpdateHandCards() {}
	virtual void UpdatePutCards() {}
	virtual void Init() {}
	virtual void ReInit() {}
	virtual void AddCard(int nCard, int x, int y);
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