/**
 * \class Map
 * 
 * \brief Map class
 * 
 * \note This class is read the txt file, and return with the parameters of the map for the print() method in the game class.
 * 
 * \author team GitCraft
 * 
 * \date 2020.12.03. 11:17:23
*/
#ifndef MAP_H
#define MAP_H
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

class Map
{
protected:
    std::vector<std::string> map;
    std::string filename;
public:
    /// This constructor is a simple default constructor
    Map(/**< [in] There's no parameter here*/){};
    ///This method is print out the map for a test.
    void print(/**< [in] There's no parameter here*/){
        for(auto & i: map){
            std::cout<<i<<"\n";
        }
    }
    /// This constructor is read the map from a txt file
    Map(const std::string& filename/**< [in] The input file name*/);
    /// This enum type containes the Wall and Free blocks on the map.
    enum type {
        Free,
        Wall
    };
    ///This method is return the type of field.
    type get(int x/**< [in] The x coordinate of the current position*/, int y/**< [in] The y coordinate of the current position*/) const;
    ///This method is return the max length of the Map.
    int getMaxLength(/**< [in] There's no parameter here*/);
    ///This method is return the height.
    int getHeight(/**< [in] There's no parameter here*/);
    ///This method is return the row length of the map.
    int getRowLength(int y/**< [in] The y coordinate for the getter method*/);
    ///This method returns the name of the map file.
    std::string getFileName(/**< [in] The name of the map file*/);
    //This method returns the map vector value.
    std::vector<std::string> getVector(/**< [in] The vector of the map file*/);
};
class WrongIndexException : public std::runtime_error{
    public:
        WrongIndexException(const std::string& message) : std::runtime_error(message){}
};



#endif