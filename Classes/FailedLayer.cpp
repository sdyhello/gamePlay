//
//  FailedLayer.cpp
//  gamePlay
//
//  Created by 涛 吴 on 15/12/17.
//
//

#include "FailedLayer.h"
#include <iostream>
USING_NS_CC;
USING_NS_CC_EXT;

bool FailedLayer::onAssignCCBMemberVariable(Ref * pTarget, const char * pMemberVariableName, Node * pNode) {
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "m_numStr", Label *, this->m_numStr);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "m_score", Label *, this->m_score);
    return false;
}

SEL_MenuHandler FailedLayer::onResolveCCBCCMenuItemSelector(Ref * pTarget, const char * pSelectorName) {
    return nullptr;
}

Control::Handler FailedLayer::onResolveCCBCCControlSelector(Ref * pTarget, const char * pSelectorName) {
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "onPressExit", FailedLayer::onPressExit);
    return nullptr;
}

void FailedLayer::onPressExit(cocos2d::Ref * sender, cocos2d::extension::Control::EventType pControlEvent)
{
    this->getParent()->removeFromParent();
}

void FailedLayer::initUI(string score, string numStr)
{
    m_score->setString(score);
    m_numStr->setString(numStr);
}