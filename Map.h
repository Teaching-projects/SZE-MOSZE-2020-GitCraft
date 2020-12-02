#ifndef MAP_H
#define MAP_H
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

class Map
{
private:
    std::vector<std::string> map;
    std::string filename;
public:
    Map(){};
    void print(){
        for(auto & i: map){
            std::cout<<i<<"\n";
        }
    }
    Map(const std::string& filename);
    enum type {
        Free,
        Wall
    };
    type get(int x, int y) const;
    int getMaxLength();
    int getHeight();
    int getRowLength(int y);
};
class WrongIndexException : public std::runtime_error{
    public:
        WrongIndexException(const std::string& message) : std::runtime_error(message){}
};



#endif