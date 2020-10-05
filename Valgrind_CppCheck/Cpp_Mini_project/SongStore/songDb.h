#include<string>
#include<cstdint>
#include "song.h"
#include "songGenre.h"
#pragma once
#include <list>
#include <iterator>
#pragma once

class SongDb :  public SongGenre {
  public :
    std::list <SongGenre> sg;
  public :

    void addSong(int, std::string, double, std::string,std::string, std::string );
    void removeSong(std::string);
    SongGenre* findSongById(int);
    int countAll();
};





