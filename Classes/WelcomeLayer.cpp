//
//  WelcomeLayer.cpp
//  gamePlay
//
//  Created by 涛 吴 on 15/12/11.
//
//

#include "WelcomeLayer.h"
#include "GameLayerLoader.h"
#include "RankLayerLoader.h"
#include "GameLayer.h"
#include "RankLayer.h"
#include "RankLogic.h"
#include "ui/CocosGUI.h"
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
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "onPressRankBtn", WelcomeLayer::onPressRank);
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "onPressExit", WelcomeLayer::onPressExit);
    return nullptr;
}

void WelcomeLayer::initUI()
{
    RankLogic::getInstance()->initRank();
}
void WelcomeLayer::onMenuItemStart(cocos2d::Ref * sender)
{
    
}

void WelcomeLayer::onHelp(cocos2d::Ref *sender, cocos2d::extension::Control::EventType pControlEvent)
{
    auto nodeLoaderLibrary = NodeLoaderLibrary::newDefaultNodeLoaderLibrary();
    
    nodeLoaderLibrary->registerNodeLoader("GameLayer", GameLayerLoader::loader());
    
    cocosbuilder::CCBReader * ccbReader = new cocosbuilder::CCBReader(nodeLoaderLibrary);
    
    auto node = ccbReader->readNodeGraphFromFile("GameLayer.ccbi", this);
    
    ccbReader->release();
    
    if (node != nullptr) {
        Layout *layout = Layout::create();
        layout->setContentSize(Size(640, 1136));
        this->addChild(layout, 9999);
        layout->setTouchEnabled(true);
        layout->addChild(node);
    }
    TDCCTalkingDataGA::onEvent("newGame");
    GameLayer * gameLayer = dynamic_cast<GameLayer *>(node);
    gameLayer->initUI();
}

void WelcomeLayer::onPressRank(cocos2d::Ref *sender, cocos2d::extension::Control::EventType pControlEvent)
{
    auto nodeLoaderLibrary = NodeLoaderLibrary::newDefaultNodeLoaderLibrary();
    
    nodeLoaderLibrary->registerNodeLoader("RankLayer", RankLayerLoader::loader());
    
    cocosbuilder::CCBReader * ccbReader = new cocosbuilder::CCBReader(nodeLoaderLibrary);
    
    auto node = ccbReader->readNodeGraphFromFile("RankLayer.ccbi", this);
    
    ccbReader->release();
    
    if (node != nullptr) {
        this->addChild(node);
    }
    
    RankLayer * rankLayer = dynamic_cast<RankLayer *>(node);
    rankLayer->initUI();
}
void WelcomeLayer::onPressExit(cocos2d::Ref *sender, cocos2d::extension::Control::EventType pControlEvent)
{
    std::cout<<"on exit"<<std::endl;
    Director::getInstance()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
