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
#include "FailedLayer.h"
#include "RankLogic.h"
#include <iostream>
USING_NS_CC;
USING_NS_CC_EXT;
using namespace cocos2d::ui;
using namespace std;
using namespace cocosbuilder;
GameLayer::GameLayer()
: gmLogic (new GameLogic())
{
    
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
    
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "m_pButton_1", ControlButton *, button_table[0]);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "m_pButton_2", ControlButton *, button_table[1]);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "m_pButton_3", ControlButton *, button_table[2]);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "m_pButton_4", ControlButton *, button_table[3]);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "m_pButton_5", ControlButton *, button_table[4]);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "m_pButton_6", ControlButton *, button_table[5]);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "m_pButton_7", ControlButton *, button_table[6]);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "m_pButton_8", ControlButton *, button_table[7]);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "m_pButton_9", ControlButton *, button_table[8]);
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

void GameLayer::initUI()
{
    gmLogic->createNextNum();
    TrigerAutoShow();
}

void GameLayer::disableAllButton()
{
    for (int i = 0; i < 9; i++) {
        button_table[i]->setEnabled(false);
    }
}
void GameLayer::ableAllButton()
{
    for (int i = 0; i < 9; i++) {
        button_table[i]->setEnabled(true);
    }
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

        EventParamMap paramMap;
        char scoreStr[10];
        sprintf(scoreStr, "%d", gmLogic->getScore());
        paramMap.insert(EventParamPair("score", scoreStr));
        paramMap.insert(EventParamPair("score_str", gmLogic->getNumberString()));
        TDCCTalkingDataGA::onEvent("onEnd", &paramMap);
        
        FailedLayer * failedLayer = dynamic_cast<FailedLayer*>(node);
        failedLayer->initUI(scoreStr, gmLogic->getNumberString());
        
        RankLogic::getInstance()->addScoreInRank(gmLogic->getScore());
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

void GameLayer::checkShowEnd()
{
    int nextNum = gmLogic->getNumByIndex(curPos);
    if (nextNum == -1)
        ableAllButton();
}

void GameLayer::schedUpdate(float dt)
{
    int num = gmLogic->getNumByIndex(curPos++);
    
    if (num == -1) {
        return;
    }
    
    auto  pSeq = Sequence::create(Show::create(), DelayTime::create(0.5), Hide::create(), DelayTime::create(0.5),
                                  CallFuncN::create(CC_CALLBACK_0(GameLayer::checkShowEnd, this)),
                                  NULL);
    sprite_table[num]->runAction(pSeq);

}
void GameLayer::TrigerAutoShow()
{
    disableAllButton();
    curPos = 0;
    int numCount = gmLogic->getNumCount();
    this->schedule(CC_SCHEDULE_SELECTOR(GameLayer::schedUpdate), 1, numCount, 1.f);
    
}
void GameLayer::onPressExit(cocos2d::Ref * sender, cocos2d::extension::Control::EventType pControlEvent)
{
    this->getParent()->removeFromParent();
}