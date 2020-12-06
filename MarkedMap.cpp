 #include "MarkedMap.h"

 MarkedMap::MarkedMap(const std::string& filename): Map(filename)
 { }

 std::vector<int> MarkedMap::getHeroPosition() const
 {
    std::vector<int> hero_position;
    for(int i=0;i<map.size();i++)
    {
         for(int j=0;j<map[i].length();j++)
         {
             if(map[i][j]=='H')
             {
                 hero_position.push_back(i);
                 hero_position.push_back(j);
             }
         }
     }
     return hero_position;
 }
 std::vector<MonsterPos> MarkedMap::getMonsterPositions(char c) const
 {
     std::vector<MonsterPos> monster_position;
     MonsterPos monster;
    for(int i=0; i < (int)map.size();i++)
    {
        for (int j = 0; j < (int) map[i].length(); j++)
        {
            if(map[i][j] == c)
            {
                monster.x=i;
                monster.y=j;
                monster_position.push_back(monster);
            }
        }
    }
     return monster_position;
 }