#include"song.h"
#include <string>
using namespace std;

Song::Song():ID(0),name(""),price(0.0), artist("") {} //default constructor
Song::Song(int ID, const std::string name, double price, std::string artist) : ID(ID),name(name),price(price), artist(artist) {} //parameterized constructor
