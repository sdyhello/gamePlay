//
//  GameLayer.cpp
//  gamePlay
//
//  Created by 涛 吴 on 15/12/16.
//
//

#include "GameLayer.h"
#include "GameLogic.h"
#include <iostream>
USING_NS_CC;
USING_NS_CC_EXT;
using namespace cocos2d::ui;
using namespace std;
bool GameLayer::onAssignCCBMemberVariable(cocos2d::Ref *pTarget, const char * pMemberVariableName, cocos2d::Node *pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "sprite_1", Scale9Sprite *, sprite_table[0]);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "sprite_2", Scale9Sprite *, sprite_table[1]);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "sprite_3", Scale9Sprite *, sprite_table[2]);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "sprite_4", Scale9Sprite *, sprite_table[3]);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "sprite_5", Scale9Sprite *, sprite_table[4]);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "sprite_6", Scale9Sprite *, sprite_table[5]);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "sprite_7", Scale9Sprite *, sprite_table[6]);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "sprite_8", Scale9Sprite *, sprite_table[7]);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "sprite_9", Scale9Sprite *, sprite_table[8]);
    return false;
}

SEL_MenuHandler GameLayer::onResolveCCBCCMenuItemSelector(Ref * pTarget, const char * pSelectorName)
{
    return nullptr;
}

Control::Handler GameLayer::onResolveCCBCCControlSelector(Ref * pTarget, const char * pSelectorName)
{
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "onPressExit", GameLayer::onPressExit);
    return nullptr;
}

void GameLayer::schedUpdate(float dt)
{
    int num = gmLogic->getNum(curPos++);
    if (num == -1) {
        return;
    }
    auto  pSeq = Sequence::create(Show::create(), DelayTime::create(1), Hide::create(), NULL);
    sprite_table[num]->runAction(pSeq);

}
void GameLayer::onPressExit(cocos2d::Ref * sender, cocos2d::extension::Control::EventType pControlEvent)
{
    curPos = 0;
    gmLogic = new GameLogic();
    gmLogic->addNum(0);
    gmLogic->addNum(1);
    gmLogic->addNum(2);
    this->schedule(CC_SCHEDULE_SELECTOR(GameLayer::schedUpdate), 2, 2 , 3.f);
    //this->removeFromParent();
}