#include <string>
#pragma once

class Song {
  public:
    int ID;
    std::string name;
    double price;
    std::string artist;
  public:
    Song();
    Song(int ID, std::string name, double price, std::string artist);
    virtual double getPrice()=0;
};

