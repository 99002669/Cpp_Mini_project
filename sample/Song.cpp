#include<iostream>
#include"Song.h"


SongBase::SongBase():songId(),songName(""),songArtist(""),songPrice(0.0),songQuantity(){}

SongBase::SongBase(int Id,std::string name,std::string artist,double price, int quantity):songId(Id),songName(name),songArtist(artist),songPrice(price),songQuantity(quantity){}

double SongBase::getSongPrice()
{
    return songPrice;
}
void SongBase::display()
{
    std::cout<<songId<<","<<songName<<","<<songArtist<<","<<songPrice<<","<<songQuantity<<std::endl;
}
int SongBase::getSongId()
{
    return songId;
}
