/**
 * \class MarkedMap
 * 
 * \brief MarkedMap class
 * 
 * \note This class the child of the Map class. In here we read the new kind of map and, do the same like in the Map class.
 * 
 * \author team GitCraft
 * 
 * \date 2020.12.03. 11:17:23
*/
#ifndef MARKEDMAP_H
#define MARKEDMAP_H
#include "Map.h"

#include <vector>

struct MonsterPos{
    int x;///< The x coordinate of the monster
    int y;///< The y coordinate of the monster
};
class MarkedMap: public Map
{
private:
    
public:
    /// The constructor of the MarkedMap class
    explicit MarkedMap(const std::string& filename/** [in] The input file name of the character*/);
    ///Basic constructor
    MarkedMap markedMap(/**< [in] There's no parameter here*/);
    ///This function is a getter for the position of the hero
    std::vector<int> getHeroPosition(/**< [in] There's no parameter here*/) const;
    ///This function is a getter for the position of the hero
    std::vector<MonsterPos> getMonsterPositions(char c/** [in] The input monster id*/) const;
};

#endif