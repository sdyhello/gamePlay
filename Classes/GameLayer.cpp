//
//  GameLayer.cpp
//  gamePlay
//
//  Created by 涛 吴 on 15/12/16.
//
//

#include "GameLayer.h"
#include "GameLogic.h"
#include "FailedLayerLoader.h"
#include <iostream>
USING_NS_CC;
USING_NS_CC_EXT;
using namespace cocos2d::ui;
using namespace std;
using namespace cocosbuilder;
GameLayer::GameLayer()
{
    gmLogic = new GameLogic();
    gmLogic->createNextNum();
    TrigerAutoShow();
}
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
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "m_pScore", Label *, labScore);
    return false;
}

SEL_MenuHandler GameLayer::onResolveCCBCCMenuItemSelector(Ref * pTarget, const char * pSelectorName)
{
    return nullptr;
}

Control::Handler GameLayer::onResolveCCBCCControlSelector(Ref * pTarget, const char * pSelectorName)
{
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "onPressExit", GameLayer::onPressExit);
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "onPressBtn_1", GameLayer::onPressMagicBtn_1);
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "onPressBtn_2", GameLayer::onPressMagicBtn_2);
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "onPressBtn_3", GameLayer::onPressMagicBtn_3);
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "onPressBtn_4", GameLayer::onPressMagicBtn_4);
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "onPressBtn_5", GameLayer::onPressMagicBtn_5);
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "onPressBtn_6", GameLayer::onPressMagicBtn_6);
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "onPressBtn_7", GameLayer::onPressMagicBtn_7);
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "onPressBtn_8", GameLayer::onPressMagicBtn_8);
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "onPressBtn_9", GameLayer::onPressMagicBtn_9);
    return nullptr;
}

void GameLayer::onPressMagicBtn_1(cocos2d::Ref * sender, cocos2d::extension::Control::EventType pControlEvent)
{
    tapMagicBtn(1);
}
void GameLayer::onPressMagicBtn_2(cocos2d::Ref * sender, cocos2d::extension::Control::EventType pControlEvent)
{
    tapMagicBtn(2);
}
void GameLayer::onPressMagicBtn_3(cocos2d::Ref * sender, cocos2d::extension::Control::EventType pControlEvent)
{
    tapMagicBtn(3);
}
void GameLayer::onPressMagicBtn_4(cocos2d::Ref * sender, cocos2d::extension::Control::EventType pControlEvent)
{
    tapMagicBtn(4);
}
void GameLayer::onPressMagicBtn_5(cocos2d::Ref * sender, cocos2d::extension::Control::EventType pControlEvent)
{
    tapMagicBtn(5);
}
void GameLayer::onPressMagicBtn_6(cocos2d::Ref * sender, cocos2d::extension::Control::EventType pControlEvent)
{
    tapMagicBtn(6);
}
void GameLayer::onPressMagicBtn_7(cocos2d::Ref * sender, cocos2d::extension::Control::EventType pControlEvent)
{
    tapMagicBtn(7);
}
void GameLayer::onPressMagicBtn_8(cocos2d::Ref * sender, cocos2d::extension::Control::EventType pControlEvent)
{
    tapMagicBtn(8);
}
void GameLayer::onPressMagicBtn_9(cocos2d::Ref * sender, cocos2d::extension::Control::EventType pControlEvent)
{
    tapMagicBtn(9);
}

void GameLayer::tapMagicBtn(int num)
{
    int status = gmLogic->trigerOneBtn(num - 1);
    if (status == -1) {
        auto nodeLoaderLibrary = NodeLoaderLibrary::newDefaultNodeLoaderLibrary();
        
        nodeLoaderLibrary->registerNodeLoader("FailedLayer", FailedLayerLoader::loader());
        
        cocosbuilder::CCBReader * ccbReader = new cocosbuilder::CCBReader(nodeLoaderLibrary);
        
        auto node = ccbReader->readNodeGraphFromFile("FailedLayer.ccbi", this);
        
        ccbReader->release();
        
        if (node != nullptr) {
            this->addChild(node);
        }
    }
    else if (status == 1)
    {
        TrigerAutoShow();
    }
    else if (status == 0)
    {
        
    }
    int curScore = gmLogic->getScore();
    char scoreStr[20];
    sprintf(scoreStr, "%d", curScore);
    labScore->setString(scoreStr);
}

void GameLayer::schedUpdate(float dt)
{
    int num = gmLogic->getNumByIndex(curPos++);
    if (num == -1) {
        return;
    }
    auto  pSeq = Sequence::create(Show::create(), DelayTime::create(1), Hide::create(), DelayTime::create(1), NULL);
    sprite_table[num]->runAction(pSeq);

}
void GameLayer::TrigerAutoShow()
{
    curPos = 0;
    int numCount = gmLogic->getNumCount();
    this->schedule(CC_SCHEDULE_SELECTOR(GameLayer::schedUpdate), 1, numCount , 1.f);
}
void GameLayer::onPressExit(cocos2d::Ref * sender, cocos2d::extension::Control::EventType pControlEvent)
{
    this->removeFromParent();
}