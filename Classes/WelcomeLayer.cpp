//
//  WelcomeLayer.cpp
//  gamePlay
//
//  Created by 涛 吴 on 15/12/11.
//
//

#include "WelcomeLayer.h"
#include "GameLayerLoader.h"
#include <iostream>
USING_NS_CC;
USING_NS_CC_EXT;
using namespace cocosbuilder;

bool WelcomeLayer::onAssignCCBMemberVariable(cocos2d::Ref *pTarget, const char * pMemberVariableName, cocos2d::Node *pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "title", Label *, this->title);
    return false;
}
SEL_MenuHandler WelcomeLayer::onResolveCCBCCMenuItemSelector(Ref * pTarget, const char * pSelectorName)
{
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "onMenuItemStart", WelcomeLayer::onMenuItemStart);
    return nullptr;
}

Control::Handler WelcomeLayer::onResolveCCBCCControlSelector(Ref * pTarget, const char * pSelectorName)
{
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "onPressHelp", WelcomeLayer::onHelp);
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "onPressExit", WelcomeLayer::onExit);
    return nullptr;
}

void WelcomeLayer::onMenuItemStart(cocos2d::Ref * sender)
{
    
    auto nodeLoaderLibrary = NodeLoaderLibrary::newDefaultNodeLoaderLibrary();
    
    nodeLoaderLibrary->registerNodeLoader("GameLayer", GameLayerLoader::loader());
    
    cocosbuilder::CCBReader * ccbReader = new cocosbuilder::CCBReader(nodeLoaderLibrary);
    
    auto node = ccbReader->readNodeGraphFromFile("GameLayer.ccbi", this);
    
    ccbReader->release();
    
    if (node != nullptr) {
        this->addChild(node);
    }
    TDCCTalkingDataGA::onEvent("newGame");
}

void WelcomeLayer::onHelp(cocos2d::Ref *sender, cocos2d::extension::Control::EventType pControlEvent)
{
    std::cout<<"on help"<<std::endl;
    TDCCTalkingDataGA::onEvent("help");
    this->title->setString("on help");
}

void WelcomeLayer::onExit(cocos2d::Ref *sender, cocos2d::extension::Control::EventType pControlEvent)
{
    std::cout<<"on exit"<<std::endl;
    Director::getInstance()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
