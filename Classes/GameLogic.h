//
//  GameLogic.hpp
//  gamePlay
//
//  Created by 涛 吴 on 15/12/16.
//
//

#ifndef GameLogic_hpp
#define GameLogic_hpp
#include <vector>
using namespace std;
class GameLogic
{
public:
    GameLogic();
    void addNum(int num);
    int getNumByIndex(int index);
    int getNumCount();
    int genRandNum();
    void createNextNum();
    int trigerOneBtn(int num);
    void addScore(int num);
    int getScore();
    string getNumberString();
private:
    vector<int> numTable;
    int curPosition;
    int score;
};

#endif /* GameLogic_hpp */
