//
//  WelcomeLayer.hpp
//  gamePlay
//
//  Created by 涛 吴 on 15/12/11.
//
//

#ifndef WelcomeLayer_hpp
#define WelcomeLayer_hpp

#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "cocosbuilder/CocosBuilder.h"
#include "TalkingData.h"
class WelcomeLayer
    : public cocos2d::Layer
    , public cocosbuilder::CCBMemberVariableAssigner
    , public cocosbuilder::CCBSelectorResolver
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(WelcomeLayer, create);
    virtual bool onAssignCCBMemberVariable(cocos2d::Ref *pTarget, const char * pMemberiableName, cocos2d::Node *node);
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::Ref *pTarget, const char * pSelectName);
    virtual cocos2d::extension::Control::Handler onResolveCCBCCControlSelector(cocos2d::Ref *pTarget,const char
                                                                              *pSelectName);
    void onMenuItemStart(cocos2d::Ref * sender);
    void onHelp(cocos2d::Ref * sender, cocos2d::extension::Control::EventType pControlEvent);
    void onPressHardGame(cocos2d::Ref * sender, cocos2d::extension::Control::EventType pControlEvent);
    void onPressSuper(cocos2d::Ref * sender, cocos2d::extension::Control::EventType pControlEvent);
    void onPressUFOSuper(cocos2d::Ref * sender, cocos2d::extension::Control::EventType pControlEvent);
    void onPressExit(cocos2d::Ref *sender, cocos2d::extension::Control::EventType pControlEvent);
    void onPressRank(cocos2d::Ref *sender, cocos2d::extension::Control::EventType pControlEvent);
    void initUI();
private:
    cocos2d::Label * title;
};
#endif /* WelcomeLayer_hpp */
