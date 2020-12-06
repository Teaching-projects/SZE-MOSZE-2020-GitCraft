#include "Map.h"

Map::Map(const std::string& filename): filename(filename)
{   
    std::ifstream mapfile(filename);
    std::string line;
    while(getline(mapfile, line)){
        map.push_back(line);       
    }
    mapfile.close();
}

Map::type Map::get(int x, int y) const
{
  if(x > map.size() || y > map[x].length())
  {
      throw WrongIndexException("Out of range from the Map!");
  } 
  else
  {
      if(map[x][y]=='#')
      {
          return Wall;
      }
      else
      {
          return Free;
      }
  }
}

int Map::getHeight(){
    return map.size();
}

int Map::getRowLength(int y){
    return map[y].length();
}

int Map::getMaxLength(){
    int max=0;
    for (int i = 0; i < (int) map.size(); i++){
        if ((int) map[i].length()>max){
            max = (int) map[i].length();
        }
    }
    return max;
}