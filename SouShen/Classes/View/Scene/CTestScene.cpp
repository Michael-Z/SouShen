#include "Config.h"
#include "CTestScene.h"
#include "Utils/CharacterConver.h"
#include "../GameManager.h"
#include "../GameResources.h"
namespace View
{
	void CTestScene::InitScene()
	{
		CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
		CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

		CCLayer *testLayer = CCLayer::create();
	
		CCSprite *pbgSprite = CCSprite::create("Images/BackGround/background_2.jpg");

		CCLabelTTF* label = CCLabelTTF::create("first scene", "Arial", 20);
		//#endif
		CCMenuItemLabel* pMenuItem = CCMenuItemLabel::create(label, this, menu_selector(CTestScene::OnTextmenu_Click));


		 CCMenu* pMenu =CCMenu::create(pMenuItem, NULL);

		 pbgSprite->setPosition(ccp(origin.x + visibleSize.width/2 , origin.y + visibleSize.height/2));
		 pMenu->setPosition(ccp(origin.x + visibleSize.width/2 , origin.y + visibleSize.height/2));

		testLayer->addChild(pbgSprite);
		testLayer->addChild(pMenu);
		testLayer->scheduleOnce(schedule_selector(CTestScene::ShowOtherScene), 3.0f);

		this->addChild(testLayer);

		//add animation
		CCSpriteFrameCache *cache = CCSpriteFrameCache::sharedSpriteFrameCache();
		cache->addSpriteFramesWithFile("Images/animation/chooserole/mt/chooserole_mt_part1.plist");
		CCSprite *plistSprite=CCSprite::createWithSpriteFrameName("Images/animation/chooserole/mt/chooserole_mt_part1.png");
		testLayer->addChild(plistSprite);
		plistSprite->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width-plistSprite->getContentSize().width,CCDirector::sharedDirector()->getWinSize().height/2));

		//为帧创建图片
		CCArray *walkFrames = CCArray::createWithCapacity(7);
		for (int i = 1; i <= 7; i++)  
		{  
			CCSpriteFrame *frame = cache->spriteFrameByName(CCString::createWithFormat("chooserole_mt_part%d.png", i)->getCString());  
			walkFrames->addObject(frame);  
		}  

		// 创建动画  
		CCAnimation *walkAnimation = CCAnimation::createWithSpriteFrames(walkFrames, 1.0f / 12.0f);  
		//CC_BREAK_IF(!walkAnimation);  
		CCAnimate* walkAnimate = CCAnimate::create(walkAnimation);  
		//CC_BREAK_IF(!walkAnimate);  

		// 运行动画动作  
		plistSprite->runAction(CCRepeatForever::create(walkAnimate));  

		testLayer->setTouchEnabled(true);
	}

	void CTestScene::runThisScene( )
	{
		//show some effect

		InitScene();

		if (!CCDirector::sharedDirector()->getRunningScene())
		{
			CCDirector::sharedDirector()->runWithScene(this);
		}
		else
		{
			CCDirector::sharedDirector()->replaceScene(this);
		}
	}

	void CTestScene::OnTextmenu_Click(CCObject *pSender)
	{
		printf("nothing");

		_gamemanager::instance()->DisplayNowScene(SCENE_MENU);
	}

	void CTestScene::ShowOtherScene(float t)
	{
	    _gamemanager::instance()->DisplayNowScene(SCENE_MENU);
		printf("do nothing");
	}
}