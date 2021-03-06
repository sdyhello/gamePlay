//
//  RankLayer.cpp
//  gamePlay
//
//  Created by 涛 吴 on 15/12/17.
//
//

#include "RankLayer.h"
#include "RankLogic.h"
#include <iostream>
USING_NS_CC;
USING_NS_CC_EXT;
using namespace std;
bool RankLayer::onAssignCCBMemberVariable(Ref * pTarget, const char * pMemberVariableName, Node * pNode) {
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "m_rank_1", Label *, labelTable[0]);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "m_rank_2", Label *, labelTable[1]);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "m_rank_3", Label *, labelTable[2]);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "m_rank_4", Label *, labelTable[3]);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "m_rank_5", Label *, labelTable[4]);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "m_rank_6", Label *, labelTable[5]);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "m_rank_7", Label *, labelTable[6]);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "m_rank_8", Label *, labelTable[7]);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "m_rank_9", Label *, labelTable[8]);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "m_rank_10", Label *, labelTable[9]);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "m_pSuperCount", Label *, m_pSuperCount);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "m_pAllSuperCount", Label *, m_pAllSuperCount);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "m_pWinrate", Label *, m_pWinrate);
    
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "m_pUFOSuperCount", Label *, m_pUFOSuperCount);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "m_pUFOAllSuperCount", Label *, m_pUFOAllSuperCount);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "m_pUFOWinrate", Label *, m_pUFOWinrate);
    return false;
}

SEL_MenuHandler RankLayer::onResolveCCBCCMenuItemSelector(Ref * pTarget, const char * pSelectorName) {
    return nullptr;
}

Control::Handler RankLayer::onResolveCCBCCControlSelector(Ref * pTarget, const char * pSelectorName) {
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "onPressBack", RankLayer::onPressBack);
    return nullptr;
}

void RankLayer::onPressBack(cocos2d::Ref * sender, cocos2d::extension::Control::EventType pControlEvent)
{
    this->removeFromParent();
}

void RankLayer::initUI()
{
    vector<int> rankTable = RankLogic::getInstance()->getRankTable();
    if (rankTable.size() == 0) {
        return;
    }
    int index = 0;
    for (vector<int>::iterator iter = rankTable.begin(); iter != rankTable.end(); iter++)
    {
        char tempStr[100];
        sprintf(tempStr, "第%d名:  %d",index+1, *iter);
        labelTable[index]->setString(tempStr);
        index++;
        if (index >= 10) {
            break;
        }
    }
    int SuperCount = cocos2d::UserDefault::getInstance()->getIntegerForKey("SuperCount", 0);
    char str[100];
    sprintf(str, "%d", SuperCount);
    m_pSuperCount->setString(str);
    
    int allSuperCount = cocos2d::UserDefault::getInstance()->getIntegerForKey("AllSuperCount", 0);
    char strAll[100];
    sprintf(strAll, "%d", allSuperCount);
    m_pAllSuperCount->setString(strAll);
    
    if (allSuperCount > 0) {
        char strWinrate[100];
        sprintf(strWinrate, "%.2f%%", (float)SuperCount/allSuperCount*100);
        m_pWinrate->setString(strWinrate);
    }
    else
    {
        m_pWinrate->setString("0.00%");
    }
    
    
    int UFOSuperCount = cocos2d::UserDefault::getInstance()->getIntegerForKey("UFOSuperCount", 0);
    char strUFO[100];
    sprintf(strUFO, "%d", UFOSuperCount);
    m_pUFOSuperCount->setString(strUFO);
    
    int allUFOSuperCount = cocos2d::UserDefault::getInstance()->getIntegerForKey("AllUFOSuperCount", 0);
    char strAllUFO[100];
    sprintf(strAllUFO, "%d", allUFOSuperCount);
    m_pUFOAllSuperCount->setString(strAllUFO);
    
    if (allUFOSuperCount > 0) {
        char strWinrateUFO[100];
        sprintf(strWinrateUFO, "%.2f%%", (float)UFOSuperCount/allUFOSuperCount*100);
        m_pUFOWinrate->setString(strWinrateUFO);
    }
    else
    {
        m_pUFOWinrate->setString("0.00%");
    }
    
}