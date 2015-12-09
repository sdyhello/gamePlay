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

SEL_MenuHandler OPTestLayer::onResolveCCBCCMenuItemSelector(Ref * pTarget, const char * pSelectorName) {
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "onPressMenuItem", OPTestLayer::onPressButton);
    return nullptr;
}

Control::Handler OPTestLayer::onResolveCCBCCControlSelector(Ref * pTarget, const char * pSelectorName) {
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "onPressButton", OPTestLayer::onControlButtonClicked);
    
    return nullptr;
}

void OPTestLayer::onControlButtonClicked(cocos2d::Ref *pSender, Control::EventType pControlEvent) {
    switch(pControlEvent) {
        case Control::EventType::TOUCH_DOWN:
            this->helloLabel->setString("Touch Down.");
            break;
        case Control::EventType::DRAG_INSIDE:
            this->helloLabel->setString("Touch Drag Inside.");
            break;
        case Control::EventType::DRAG_OUTSIDE:
            this->helloLabel->setString("Touch Drag Outside.");
            break;
        case Control::EventType::DRAG_ENTER:
            this->helloLabel->setString("Touch Drag Enter.");
            break;
        case Control::EventType::DRAG_EXIT:
            this->helloLabel->setString("Touch Drag Exit.");
            break;
        case Control::EventType::TOUCH_UP_INSIDE:
            this->helloLabel->setString("Touch Up Inside.");
            break;
        case Control::EventType::TOUCH_UP_OUTSIDE:
            this->helloLabel->setString("Touch Up Outside.");
            break;
        case Control::EventType::TOUCH_CANCEL:
            this->helloLabel->setString("Touch Cancel.");
            break;
        case Control::EventType::VALUE_CHANGED:
            this->helloLabel->setString("Value Changed.");
            break;
        default:
            assert(false); // OH SHIT!
    }
}

void OPTestLayer::onPressButton(cocos2d::Ref * sender)
{
    std::cout<<"hello"<<std::endl;
    this->helloLabel->setString("1111111");
}