#include <iostream>
#include <map>
#include <string>
#include <filesystem>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <list>

#include "JSON.h"
#include "Hero.h"
#include "Monster.h"
#include "Game.h"
#include "MarkedMap.h"
#include "PreparedGame.h"
#include "Renderer.h"

const std::map<int,std::string> error_messages = {
    { 1 , "Bad number of arguments." },
    { 2 , "The provided scenario file is not accessible." },
    { 3 , "The provided scenario file is invalid." },
    { 4 , "JSON parsing error." },
    { 5 , "Game already started error."},
    { 6 , "Field is already occupied."},
    { 7 , "Game already has a hero."},
    { 8 , "Game already has units."},
    { 9 , "Game could not be initialized."},
    { 10 , "Wrong index given."}
};

void bad_exit(int exitcode){
    std::cerr 
        << (error_messages.count(exitcode) ? error_messages.at(exitcode) : "Unknown error")
        << std::endl;
    exit(exitcode);
}

int main(int argc, char** argv){
    if (argc > 3 || argc < 2) bad_exit(1);
    //if (!std::filesystem::exists(argv[1])) bad_exit(2);
    std::string mode = "";
    mode += argv[1];
    
    if(mode=="prepared"){
        // Prepared game mode       
        PreparedGame game(argv[2]);
        game.run();
    }else{
        // Scenario mode
        std::string hero_file;
        std::list<std::string> monster_files;
        try {
            JSON scenario = JSON::parseFromFile(argv[1]); 
            if (!(scenario.count("hero")&&scenario.count("monsters"))) bad_exit(3);
            else {
                hero_file=scenario.get<std::string>("hero");
                JSON::list monster_file_list=scenario.get<JSON::list>("monsters");
                for(auto monster_file : monster_file_list)
                    monster_files.push_back(std::get<std::string>(monster_file));
            }
        } catch (const JSON::ParseException& e) {bad_exit(4);}
        try { 
            Hero hero{ Hero::parse(hero_file)};
            std::list<Monster> monsters;
            for (const auto& monster_file : monster_files){
                monsters.push_back(Monster::parse(monster_file)); 
            }
            std::cout<<"Map name:"<<std::endl;
            std::string mapname;
            std::cin>>mapname;
            Map map(mapname);
            Game game{};
            game.setMap(map);
            for(const auto& enemys : monsters)
            {
                game.print();
                int x,y;
                std::cout<<enemys.getName()<<std::endl;
                std::cout<<"Add the x coordinate of the monster"<<std::endl;
                std::cin>>x;
                std::cout<<"Add the  y  coordinate of the monster"<<std::endl;
                std::cin>>y;
                game.putMonster(enemys,x,y);
            }
            game.print();
            int x,y;
            std::cout<<hero.getName()<<std::endl;
            std::cout<<"Add the x coordinate of Hero"<<std::endl;
            std::cin>>x;
            std::cout<<"Add the y coordinate of Hero"<<std::endl;
            std::cin>>y;
            game.putHero(hero,x,y);
            game.print();

            game.run();
            MarkedMap markedmap("markedmap.txt");
            std::cout<<markedmap.getHeroPosition()[0]<<":"<<markedmap.getHeroPosition()[1];


        } catch (const JSON::ParseException& e) {bad_exit(4);}
        catch (const GameAlreadyStarted& e){bad_exit(5);}
        catch (const OccupiedException& e){bad_exit(6);}
        catch (const AlreadyHasHeroException& e){bad_exit(7);}
        catch (const AlreadyHasUnitsException& e){bad_exit(8);}
        catch (const NotInitializedException& e){bad_exit(9);}
        catch (const WrongIndexException& e){bad_exit(10);}
    }
    return 0;
}