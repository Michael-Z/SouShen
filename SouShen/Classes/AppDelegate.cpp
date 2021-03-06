#include "Config.h"
#include "cocos2d.h"
#include "CCEGLView.h"
#include "AppDelegate.h"
#include "CCLuaEngine.h"
#include "SimpleAudioEngine.h"

#include "Game/GameManager.h"
#include "View/PixelResolution.h"
#include "TcpNetwork/ClientNet.h"

#include "Packet/Builder.h"

using namespace CocosDenshion;

USING_NS_CC;

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate()
{
    SimpleAudioEngine::end();
}

bool AppDelegate::applicationDidFinishLaunching()
{
    // initialize director
    CCDirector *pDirector = CCDirector::sharedDirector();
    pDirector->setOpenGLView(CCEGLView::sharedOpenGLView());

	CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();
	pEGLView->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, kResolutionNoBorder);
	//pEGLView->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, kResolutionFixedHeight);
	//pEGLView->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, kResolutionFixedWidth);
	
	//set ScaleFactor
	pDirector->setContentScaleFactor( 640 / designResolutionSize.height);

    // turn on display FPS
    pDirector->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);

    // register lua engine
    //CCLuaEngine* pEngine = CCLuaEngine::defaultEngine();
    //CCScriptEngineManager::sharedManager()->setScriptEngine(pEngine);

    //std::string path = CCFileUtils::sharedFileUtils()->fullPathForFilename("hello.lua");
    //pEngine->executeScriptFile(path.c_str());

	//set first sence
	View::_gamemanager::instance()->DisplayNowScene(View::SCENE_INIT);

	//TcpNetWork::_clientnet.connect("192.168.0.106", 4444, 50);

	//Packet::UserLogin ulogin;
	//ulogin.setResult(1);
	//ulogin.send();

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
    CCDirector::sharedDirector()->stopAnimation();

    SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    CCDirector::sharedDirector()->startAnimation();

    SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
