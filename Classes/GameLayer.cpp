//
//  GameLayer.cpp
//  gamePlay
//
//  Created by 涛 吴 on 15/12/16.
//
//

#include "GameLayer.h"

#include <iostream>
USING_NS_CC;
USING_NS_CC_EXT;

bool GameLayer::onAssignCCBMemberVariable(cocos2d::Ref *pTarget, const char * pMemberVariableName, cocos2d::Node *pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "btn_demo", Node *, this->button);
    std::cout<<"enter gamelayer"<<std::endl;
    return false;
}

SEL_MenuHandler GameLayer::onResolveCCBCCMenuItemSelector(Ref * pTarget, const char * pSelectorName)
{
    return nullptr;
}

Control::Handler GameLayer::onResolveCCBCCControlSelector(Ref * pTarget, const char * pSelectorName)
{
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "onPressBtn", GameLayer::onPressBtn);
    return nullptr;
}

void GameLayer::onPressBtn(cocos2d::Ref * sender, cocos2d::extension::Control::EventType pControlEvent)
{
    this->removeFromParent();
}