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

void GameLogic::createThreeNum()
{
    for (int i = 0; i < 3; i++) {
        addNum(genRandNum());
    }
}

void GameLogic::addNineNum()
{
    bool isOk = false;
    std::set<int> superTable;
    int curIndex = 0;
    while (!isOk) {
        int num = genRandNum();
        if (superTable.count(num) == 0)
        {
            superTable.insert(num);
            addNum(num);
        }
        for (int i = 1; i <= 9; i++)
        {
            if (superTable.count(i) == 0) {
                break;
            }
            curIndex = i;
        }
        if (curIndex >= 9) {
            isOk = true;
        }
    }
}

string GameLogic::getNumberString()
{
    string numberString;
    char tempStr[10];
    for (vector<int>::iterator iter = numTable.begin(); iter != numTable.end(); iter++) {
        sprintf(tempStr, "%d", *iter+1);
        string numStr(tempStr);
        numberString+=numStr;
    }
    return numberString;
}

int GameLogic::trigerOneBtn(int num, bool bHard, bool bSuper)
{
    if (curPosition < numTable.size()) {
        if (numTable[curPosition] != num) {
            cout<<numTable[curPosition]<<num<<endl;
            return -1;
        }
    }
    curPosition++;
    if (bHard)
    {
        addScore(curPosition * 3);
    }
    else
    {
        addScore(curPosition);
    }
    if (curPosition == numTable.size()) {
        if (bHard) {
            createThreeNum();
        }
        else{
            if (!bSuper) {
                createNextNum();
            }
        }
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

