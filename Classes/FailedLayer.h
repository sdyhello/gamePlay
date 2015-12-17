//
//  FailedLayer.hpp
//  gamePlay
//
//  Created by 涛 吴 on 15/12/17.
//
//

#ifndef FailedLayer_hpp
#define FailedLayer_hpp

#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "cocosbuilder/CocosBuilder.h"

class FailedLayer
: public cocos2d::Layer
, public cocosbuilder::CCBMemberVariableAssigner
, public cocosbuilder::CCBSelectorResolver
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(FailedLayer, create);
    virtual bool onAssignCCBMemberVariable(cocos2d::Ref * pTarget, const char * pMemberVariableName, cocos2d::Node * node);
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::Ref * pTarget, const char * pSelectorName);
    virtual cocos2d::extension::Control::Handler onResolveCCBCCControlSelector(cocos2d::Ref * pTarget, const char * pSelectorName);
    void onPressExit(cocos2d::Ref * sender, cocos2d::extension::Control::EventType pControlEvent);
private:
    cocos2d::Label *labResult;
};
#endif /* FailedLayer_hpp */
