//
//  WelcomeLayer.cpp
//  gamePlay
//
//  Created by 涛 吴 on 15/12/11.
//
//

#include "WelcomeLayer.h"

bool WelcomeLayer::onAssignCCBMemberVariable(cocos2d::Ref *pTarget, const char * pMemberiableName, cocos2d::Node *node)
{
    return false;
}
cocos2d::SEL_MenuHandler WelcomeLayer::onResolveCCBCCMenuItemSelector(cocos2d::Ref *pTarget, const char * pSelectName)
{
    return nullptr;
}
cocos2d::extension::Control::Handler WelcomeLayer::onResolveCCBCCControlSelector(cocos2d::Ref *pTarget,const char
                                                                           *pSelectName)
{
    return nullptr;
}