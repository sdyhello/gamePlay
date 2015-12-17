//
//  RankLayer.hpp
//  gamePlay
//
//  Created by 涛 吴 on 15/12/17.
//
//

#ifndef RankLayer_hpp
#define RankLayer_hpp

#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "cocosbuilder/CocosBuilder.h"

class RankLayer
: public cocos2d::Layer
, public cocosbuilder::CCBMemberVariableAssigner
, public cocosbuilder::CCBSelectorResolver
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(RankLayer, create);
    virtual bool onAssignCCBMemberVariable(cocos2d::Ref * pTarget, const char * pMemberVariableName, cocos2d::Node * node);
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::Ref * pTarget, const char * pSelectorName);
    virtual cocos2d::extension::Control::Handler onResolveCCBCCControlSelector(cocos2d::Ref * pTarget, const char * pSelectorName);
    void onPressBack(cocos2d::Ref * sender, cocos2d::extension::Control::EventType pControlEvent);
    void initUI();
private:
    cocos2d::Label * labelTable[10];
};
#endif /* RankLayer_hpp */
