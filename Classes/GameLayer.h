//
//  GameLayer.hpp
//  gamePlay
//
//  Created by 涛 吴 on 15/12/16.
//
//

#ifndef GameLayer_hpp
#define GameLayer_hpp

#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "cocosbuilder/CocosBuilder.h"
#include "GameLogic.h"
#include <vector>
using namespace cocos2d::ui;
class GameLayer
    : public cocos2d::Layer
    , public cocosbuilder::CCBMemberVariableAssigner
    , public cocosbuilder::CCBSelectorResolver
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(GameLayer, create);
    virtual bool onAssignCCBMemberVariable(cocos2d::Ref *pTarget, const char * pMemberiableName, cocos2d::Node *node);
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::Ref *pTarget, const char * pSelectName);
    virtual cocos2d::extension::Control::Handler onResolveCCBCCControlSelector(cocos2d::Ref *pTarget,const char
                                                                               *pSelectName);
    void onPressExit(cocos2d::Ref * sender, cocos2d::extension::Control::EventType pControlEvent);
    void schedUpdate(float dt);
private:
    cocos2d::Label * title;
    cocos2d::extension::ControlButton * m_pButton;
    cocos2d::Node * node_1;
    Scale9Sprite * sprite_table[9];
    GameLogic * gmLogic;
    int curPos;
    float updateTime;
};
#endif /* GameLayer_hpp */
