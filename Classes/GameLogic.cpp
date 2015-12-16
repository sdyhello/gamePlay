//
//  GameLogic.cpp
//  gamePlay
//
//  Created by 涛 吴 on 15/12/16.
//
//

#include "GameLogic.h"

void GameLogic::addNum(int num)
{
    numTable.push_back(num);
}
int GameLogic::getNum(int index)
{
    if (index < numTable.size()) {
        return numTable[index];
    }
    return -1;
}