//
//  GameLogic.cpp
//  gamePlay
//
//  Created by 涛 吴 on 15/12/16.
//
//

#include "GameLogic.h"
#include <iostream>
#include <random>
GameLogic::GameLogic()
: curPosition(0)
, score(0)
{
    
}

int GameLogic::genRandNum()
{
    std::random_device rd;
    std::mt19937 mt(rd());
    int newNum = (mt()%9)+1;
    return newNum;
}

void GameLogic::addNum(int num)
{
    numTable.push_back(num - 1);
}

int GameLogic::getNumByIndex(int index)
{
    if (index < numTable.size()) {
        return numTable[index];
    }
    return -1;
}

int GameLogic::getNumCount()
{
    return (int)numTable.size();
}

void GameLogic::createNextNum()
{
    int newNum = genRandNum();
    addNum(newNum);
}

int GameLogic::trigerOneBtn(int num)
{
    if (curPosition < numTable.size()) {
        if (numTable[curPosition] != num) {
            cout<<numTable[curPosition]<<num<<endl;
            return -1;
        }
    }
    curPosition++;
    addScore(curPosition);
    if (curPosition == numTable.size()) {
        createNextNum();
        curPosition = 0;
        return 1;
    }
    return 0;
}

void GameLogic::addScore(int num)
{
    score += num;
}

int GameLogic::getScore()
{
    return score;
}