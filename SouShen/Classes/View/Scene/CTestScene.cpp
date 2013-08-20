#include "Config.h"
#include "CTestScene.h"
#include "Utils/CharacterConver.h"
#include "../../Game/GameManager.h"
#include "../GameResources.h"
namespace View
{
	void CTestScene::InitScene()
	{
		//CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
		//CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

		//CCLayer *testLayer = CCLayer::create();
	
		//CCSprite *pbgSprite = CCSprite::create("Images/BackGround/background_2.jpg");

		//CCLabelTTF* label = CCLabelTTF::create("first scene", "Arial", 20);
		////#endif
		//CCMenuItemLabel* pMenuItem = CCMenuItemLabel::create(label, this, menu_selector(CTestScene::OnTextmenu_Click));


		// CCMenu* pMenu =CCMenu::create(pMenuItem, NULL);

		// pbgSprite->setPosition(ccp(origin.x + visibleSize.width/2 , origin.y + visibleSize.height/2));
		// pMenu->setPosition(ccp(origin.x + visibleSize.width/2 , origin.y + visibleSize.height/2));

		//testLayer->addChild(pbgSprite);
		//testLayer->addChild(pMenu);
		//testLayer->scheduleOnce(schedule_selector(CTestScene::ShowOtherScene), 10.0f);

		//this->addChild(testLayer);

		////add animation
		//CCSpriteFrameCache *cache = CCSpriteFrameCache::sharedSpriteFrameCache();
		//cache->addSpriteFramesWithFile("Images/animation/chooserole/mt/chooserole_mt_part1.plist");
		//cache->addSpriteFramesWithFile("Images/animation/chooserole/mt/chooserole_mt_part2.plist");
		////cache->addSpriteFramesWithFile("Images/animation/chooserole/mt/skill_tenarmy.plist");
		//

		//CCSprite *plistSprite=CCSprite::createWithSpriteFrameName("mt_0001.png");
		////CCSprite *plistSprite=CCSprite::createWithSpriteFrameName("tenarmy_01.png");

		//testLayer->addChild(plistSprite);
		//plistSprite->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width/2,CCDirector::sharedDirector()->getWinSize().height/2 + plistSprite->getContentSize().width));

		////为帧创建图片
		//CCArray *walkFrames = CCArray::createWithCapacity(11);
		//for (int i = 1; i <= 11; i++)  
		//{  
		//	CCSpriteFrame *frame;
		//	//if (i == 4 || i == 6 || i == 8)
		//	//{
		//	//	continue;
		//	//}
		//	if (i < 10)
		//	{
		//		frame = cache->spriteFrameByName(CCString::createWithFormat("mt_000%d.png", i)->getCString());   
		//	}
		//	else
		//	{
		//		frame = cache->spriteFrameByName(CCString::createWithFormat("mt_00%d.png", i)->getCString());  
		//	}


		//	walkFrames->addObject(frame);  
		//}  

		//// 创建动画  
		//CCAnimation *walkAnimation = CCAnimation::createWithSpriteFrames(walkFrames, 1.0f / 15.0f);  
		////CC_BREAK_IF(!walkAnimation);  
		//CCAnimate* walkAnimate = CCAnimate::create(walkAnimation);  
		////CC_BREAK_IF(!walkAnimate);  

		//// 运行动画动作  
		//plistSprite->runAction(CCRepeatForever::create(walkAnimate));  

		//testLayer->setTouchEnabled(true);

		//test
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

		this->addChild(testLayer);


		CCTexture2D *pTexture = CCTextureCache::sharedTextureCache()->addImage(s_pPathDDZMainGame0);
		CCSprite *pSprite;
		pSprite = CCSprite::createWithTexture(pTexture, CCRect(200, 200, 300, 300));
		testLayer->addChild(pSprite);
		pSprite->setPosition(CCPoint(200, 200));
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