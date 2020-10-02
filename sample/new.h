#ifndef NEW_H_INCLUDED
#define NEW_H_INCLUDED

#include<string>
#include"Song.h"

class NewSong: public SongBase{
public:
    NewSong();
    NewSong(int Id,std::string name,std::string artist,double price, int quantity);
    void getSong();
    void writeSong();
    void modSong();
    void showSong();
    void deleteSong(int);
    void modifySong(int);
    int getSongId();

};
#endif // NEW_H_INCLUDED
