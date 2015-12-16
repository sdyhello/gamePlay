//
//  WelcomeLayer.cpp
//  gamePlay
//
//  Created by 涛 吴 on 15/12/11.
//
//

#include "WelcomeLayer.h"
#include <iostream>
USING_NS_CC;
USING_NS_CC_EXT;

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

Control::Handler WelcomeLayer::onResolveCCBCCControlSelector(Ref *pTarget,const char *pSelectorName)
{
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "onPressHelp", WelcomeLayer::onHelp);
    return nullptr;
}

void WelcomeLayer::onMenuItemStart(cocos2d::Ref * sender)
{
    std::cout<<"hello"<<std::endl;
    this->title->setString("onMenuItemStart");
}

void WelcomeLayer::onHelp(cocos2d::Ref *sender, cocos2d::extension::Control::EventType pControlEvent)
{
    std::cout<<"on help"<<std::endl;
    this->title->setString("on help");
}
