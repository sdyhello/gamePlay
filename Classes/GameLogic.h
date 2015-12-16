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
    void addNum(int num);
    int getNum(int index);
    
private:
    vector<int> numTable;
};

#endif /* GameLogic_hpp */
