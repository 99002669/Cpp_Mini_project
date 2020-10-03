#include <string>
#include "student.h"
#pragma once


class OldSong : public Song {

private :

    std::string grade;
    std::string address;
    int busDistance;


public :

    OldSong();
    OldSong(int ,std::string,double , std::string,std::string,std::string, int);


    double computeTravelTime();


    int getID();
    std::string getGender();
    std::string getName();
    double getPercantage();
    int getDistance();
};

