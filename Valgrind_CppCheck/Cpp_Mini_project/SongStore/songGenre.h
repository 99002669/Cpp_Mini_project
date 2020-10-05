#include <string>
#include "song.h"
#pragma once

class SongGenre : public Song {
  private :
    std::string genre;
    std::string year;
  public :
    SongGenre();
    SongGenre(int,std::string,double, std::string,std::string,std::string);
    int getID();
    std::string getGenre();
    std::string getName();
    double getPrice();
};
