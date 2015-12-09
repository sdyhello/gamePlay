//
//  OPTestLayer.cpp
//  gamePlay
//
//  Created by 涛 吴 on 15/12/8.
//
//
#include <iostream>
#include "OPTestLayer.h"
USING_NS_CC;
USING_NS_CC_EXT;

bool OPTestLayer::onAssignCCBMemberVariable(Ref * pTarget, const char * pMemberVariableName, Node * pNode) {
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "helloLabel", Label *, this->helloLabel);
    std::cout<<"hello"<<std::endl;
    return false;
}
//菜单按钮
SEL_MenuHandler OPTestLayer::onResolveCCBCCMenuItemSelector(Ref * pTarget, const char * pSelectorName) {
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "onPressMenuItem", OPTestLayer::onPressButton);
    return nullptr;
}

void OPTestLayer::onPressButton(cocos2d::Ref * sender)
{
    std::cout<<"hello"<<std::endl;
    this->helloLabel->setString("1111111");
}

//普通按钮
Control::Handler OPTestLayer::onResolveCCBCCControlSelector(Ref * pTarget, const char * pSelectorName) {
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "onPressButton", OPTestLayer::onControlButtonClicked);
    return nullptr;
}

void OPTestLayer::onControlButtonClicked(cocos2d::Ref *pSender, Control::EventType pControlEvent) {
    this->helloLabel->setString("Value Changed.");
}

