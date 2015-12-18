//
//  RankLogic.cpp
//  gamePlay
//
//  Created by 涛 吴 on 15/12/17.
//
//

#include "RankLogic.h"
#include <vector>
#include<iomanip>
using namespace std;

RankLogic::RankLogic()
{
    
}

RankLogic * RankLogic::getInstance()
{
    static RankLogic * instance;
    if (!instance) {
        instance = new RankLogic();
    }
    return instance;
}

void RankLogic::initRank()
{
    if (rankTable.size() > 0) {
        return;
    }
    getData("rank");
}

void RankLogic::getData(const char* key)
{
    cocos2d::Data data = cocos2d::UserDefault::getInstance()->getDataForKey(key);
    int* buffer = (int*) data.getBytes();
    ssize_t length = data.getSize() / sizeof(int);
    for (int i = 0; i < length; i++)
    {
        rankTable.push_back(buffer[i]);
    }
}

void RankLogic::setData(const char* key)
{
    cocos2d::Data data;
    int saveSize =(int) rankTable.size();
    if (saveSize > 10) {
        saveSize = 10;
    }
    data.copy((unsigned char*) rankTable.data(), saveSize * sizeof(int));
    cocos2d::UserDefault::getInstance()->setDataForKey(key, data);
}

void RankLogic::addScoreInRank(int score)
{
    rankTable.push_back(score);
    sort(rankTable.begin(), rankTable.end(), greater<int>());
    setData("rank");
}

vector<int> RankLogic::getRankTable()
{
    return rankTable;
}
