//
//  WelcomeLayer.hpp
//  gamePlay
//
//  Created by 涛 吴 on 15/12/11.
//
//

#ifndef WelcomeLayer_hpp
#define WelcomeLayer_hpp

#include <stdio.h>
#include "extensions/cocos-ext.h"
#include "cocosbuilder/CocosBuilder.h"
class WelcomeLayer
    : public cocos2d::Layer
    , public cocosbuilder::CCBMemberVariableAssigner
    , public cocosbuilder::CCBSelectorResolver
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(WelcomeLayer, create);
    virtual bool onAssignCCBMemberiable(cocos2d::Ref *pTarget, const char * pMemberiableName, cocos2d::Node *node);
};
#endif /* WelcomeLayer_hpp */
