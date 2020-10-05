#include <string>
#include "song.h"
#include "songGenre.h"

SongGenre::SongGenre():Song(),genre(""),
    year("") {}

SongGenre::SongGenre(int ID, std::string name, double price, std::string artist,std::string genre,std::string year):
    Song(ID,name,price,artist),genre(genre),year(year) {
}

int SongGenre::getID() {
    return ID;
}
std::string SongGenre::getGenre() {
    return genre;
}
std::string SongGenre::getName() {
    return name;
}
double SongGenre::getPrice() {
    return price;
}
