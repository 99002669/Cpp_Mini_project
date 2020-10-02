#ifndef SONG_H_INCLUDED
#define SONG_H_INCLUDED


#include<string>

class SongBase
{
protected:
    int songId;
    std::string songName;
    std::string songArtist;
    double songPrice;
    int songQuantity;
public:
    SongBase();
    SongBase(int ,std::string ,std::string ,double , int );

    virtual void getSong()=0;
    virtual void writeSong()=0;
    virtual void modSong()=0;
    virtual void showSong()=0;
    virtual void deleteSong()=0;
    virtual void modifySong()=0;

    double getSongPrice();
    int getSongId();
    void display();
};
#endif
