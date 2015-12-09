//
//  OPTestLayer.hpp
//  gamePlay
//
//  Created by 涛 吴 on 15/12/8.
//
//

#ifndef OPTestLayer_hpp
#define OPTestLayer_hpp

#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "cocosbuilder/CocosBuilder.h"

class OPTestLayer
    : public cocos2d::Layer
    , public cocosbuilder::CCBMemberVariableAssigner
    , public cocosbuilder::CCBSelectorResolver
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(OPTestLayer, create);
    virtual bool onAssignCCBMemberVariable(cocos2d::Ref * pTarget, const char * pMemberVariableName, cocos2d::Node * node);
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::Ref * pTarget, const char * pSelectorName);
    virtual cocos2d::extension::Control::Handler onResolveCCBCCControlSelector(cocos2d::Ref * pTarget, const char * pSelectorName);
    void onPressButton(cocos2d::Ref * sender);
    void onControlButtonClicked(cocos2d::Ref * sender, cocos2d::extension::Control::EventType pControlEvent);
private:
    cocos2d::Label *helloLabel;
};
#endif /* OPTestLayer_hpp */
