/**
 * \class PreparedGame
 * 
 * \brief PreparedGame class
 * 
 * \note This is the child of the Game class. Now this class is running the game.
 * 
 * \author team GitCraft
 * 
 * \date 2020.12.03. 11:17:23
*/
#ifndef PREPAREDGAME_H
#define PREPAREDGAME_H
#include "Game.h"
#include "MarkedMap.h"
#include "JSON.h"
#include <fstream>
#include <string>
#include <vector>

class PreparedGame:public Game
{
private:
    
public:
    /// This is the constructor of the PreparedGame class, here we set up the input file map name.
    PreparedGame(const std::string &inputFile);
    /// This method is running the game, in here we can add the destruction for the move.
    void run(/**< [in] There's no parameter here*/);
};




#endif