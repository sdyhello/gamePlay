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
#include "TalkingData.h"
#include <vector>

using namespace cocos2d::ui;
class GameLayer
    : public cocos2d::Layer
    , public cocosbuilder::CCBMemberVariableAssigner
    , public cocosbuilder::CCBSelectorResolver
{
public:
    GameLayer();
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(GameLayer, create);
    virtual bool onAssignCCBMemberVariable(cocos2d::Ref *pTarget, const char * pMemberiableName, cocos2d::Node *node);
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::Ref *pTarget, const char * pSelectName);
    virtual cocos2d::extension::Control::Handler onResolveCCBCCControlSelector(cocos2d::Ref *pTarget,const char
                                                                               *pSelectName);
    void onPressExit(cocos2d::Ref * sender, cocos2d::extension::Control::EventType pControlEvent);
    void onPressMagicBtn_1(cocos2d::Ref * sender, cocos2d::extension::Control::EventType pControlEvent);
    void onPressMagicBtn_2(cocos2d::Ref * sender, cocos2d::extension::Control::EventType pControlEvent);
    void onPressMagicBtn_3(cocos2d::Ref * sender, cocos2d::extension::Control::EventType pControlEvent);
    void onPressMagicBtn_4(cocos2d::Ref * sender, cocos2d::extension::Control::EventType pControlEvent);
    void onPressMagicBtn_5(cocos2d::Ref * sender, cocos2d::extension::Control::EventType pControlEvent);
    void onPressMagicBtn_6(cocos2d::Ref * sender, cocos2d::extension::Control::EventType pControlEvent);
    void onPressMagicBtn_7(cocos2d::Ref * sender, cocos2d::extension::Control::EventType pControlEvent);
    void onPressMagicBtn_8(cocos2d::Ref * sender, cocos2d::extension::Control::EventType pControlEvent);
    void onPressMagicBtn_9(cocos2d::Ref * sender, cocos2d::extension::Control::EventType pControlEvent);
    
    void schedUpdate(float dt);
    void TrigerAutoShow();
    void tapMagicBtn(int num);
    void disableAllButton();
    void ableAllButton();
    void initUI(bool isSuper, bool isUFOSuper, bool bHard);
    void checkShowEnd();
    void jumpToEnd();
private:
    cocos2d::Label * title;
    cocos2d::Label * labScore;
    cocos2d::Label * m_pTips;
    cocos2d::extension::ControlButton * m_pButton;
    cocos2d::Node * node_1;
    Scale9Sprite * sprite_table[9];
    cocos2d::extension::ControlButton * button_table[9];
    GameLogic * gmLogic;
    int curPos;
    float updateTime;
    cocos2d::DrawNode *drawNode;
    bool isSuper;
    bool bisUFOSuper;
    bool bHard;
};
#endif /* GameLayer_hpp */
