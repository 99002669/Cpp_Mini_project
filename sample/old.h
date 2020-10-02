#ifndef OLD_H_INCLUDED
#define OLD_H_INCLUDED
#ifndef __OLD_H
#define __OLD_H

#include<string>
#include"Song.h"

class OldSong: public SongBase{
public:
    OldSong();
    OldSong(int Id,std::string name,std::string artist,double price, int quantity);
    void getSong();
    void writeSong();
    void modSong();
    void showSong();
    void deleteSong();
    void modifySong();
    int getSongId();

};
#endif
#endif
