#include "songGenre.h"
#include "song.h"
#include "songDb.h"
#include <string>
#include <list>
#include <iterator>
#include <thread>
#include <semaphore.h>
#include <iostream>

void SongDb::addSong(int ID, std::string name, double price, std::string artist,std::string genre, std::string year) {
    sg.push_back(SongGenre(ID, name, price, artist, genre, year));
}

void SongDb::removeSong(std::string name) {
    std::list<SongGenre> :: iterator iter;
    for(iter=sg.begin(); iter!=sg.end(); iter++) {
        if(iter->getName()== name) {
            sg.erase(iter);
            break;
        }
    }
}

int SongDb::countAll() {
    return sg.size();
}

