//
//  RankLogic.hpp
//  gamePlay
//
//  Created by 涛 吴 on 15/12/17.
//
//

#ifndef RankLogic_hpp
#define RankLogic_hpp

#include <vector>
using namespace std;
class RankLogic
{
public:
    RankLogic();
    static RankLogic * getInstance();
    void initRank();
    void addScoreInRank(int score);
    vector<int> getRankTable();
    void setData(const char* key);
    void getData(const char* key);
private:
    vector<int> rankTable;
};

#endif /* RankLogic_hpp */
