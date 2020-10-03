#include"song.h"
#include <string>

Song::Song():ID(0),name(""),price(0.0), artist("") {}
Song::Song(int ID, std::string name, double price, std::string artist) : ID(ID),name(name),price(price), artist(artist) {}
