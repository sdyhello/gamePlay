#include "HelloWorldScene.h"
#include "cocosbuilder/CocosBuilder.h"
#include "OPTestLayer.h"
#include "OPTestLayerLoader.h"
#include "WelcomeLayer.h"
#include "WelcomeLayerLoader.h"
USING_NS_CC;
using namespace cocosbuilder;
Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    auto nodeLoaderLibrary = NodeLoaderLibrary::newDefaultNodeLoaderLibrary();
    
    nodeLoaderLibrary->registerNodeLoader("WelcomeLayer", WelcomeLayerLoader::loader());
    
    /* Create an autorelease CCBReader. */
    cocosbuilder::CCBReader * ccbReader = new cocosbuilder::CCBReader(nodeLoaderLibrary);
    
    /* Read a ccbi file. */
    auto node = ccbReader->readNodeGraphFromFile("ccb/WelcomeLayer.ccbi", this);
    
    ccbReader->release();
    
    if (node != nullptr) {
        this->addChild(node);
    }
    WelcomeLayer * welcomeLayer = dynamic_cast<WelcomeLayer *>(node);
    welcomeLayer->initUI();
    return true;
}



void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
