#include <string>
#pragma once


class Song
{
    public:
        int ID;
        std::string name;
        double price;
        std::string artist;

    public:
        Song();
        Song(int ID, std::string name, double price, std::string artist);

        //virtual double computeTime()=0;
        virtual double getPrice()=0;
        virtual int getId()=0;

};


