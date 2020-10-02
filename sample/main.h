#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED


#include"Song.h"
#include"new.h"
#include"old.h"
#include<iostream>
#include<list>
#include<iterator>

class Songg
{
    std::list <NewSong> nw;
public:
    void addd(int Id,std::string name,std::string artist,double price, int quantity);
    void removee(int);
    NewSong* findbyId(int);
    void writeSong();
void display();
//case '4': cout<<"\nPlease enter the song : \n"; cin>>n;
void modifySong(int);
//case '5': cout<<"\nPlease enter the song: \n"; cin>>n;
void deleteSong(int);
};
#endif
