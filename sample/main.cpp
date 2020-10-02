#include<iostream>
#include "main.h"
#include"Song.h"
#include"new.h"
#include"old.h"
#include<iomanip>

#include<list>
#include<iterator>

void writeSong();
void display();
//case '3': cout<<"\nPlease enter the song: \n"; cin>>n;
//searchSong(n); break;
//case '4': cout<<"\nPlease enter the song : \n"; cin>>n;
void modifySong(n);
//case '5': cout<<"\nPlease enter the song: \n"; cin>>n;
void deleteSong(n);

void Songg::addd(int Id,std::string name,std::string artist,double price, int quantity)
{
    nw.push_back(NewSong(Id,name,artist,price,quantity));
}

void Songg::removee(int Id)
{
    std::list<NewSong> :: iterator iter;
    for(iter=nw.begin();iter!=nw.end();iter++)
    {
        if(iter->getSongId()==Id)
        {
            nw.erase(iter);
            break;
        }
    }
}

int main()
{
char ch;
int n;
cout.setf(ios::fixed|ios::showpoint);
cout<<setprecision(2);
do
{
system("cls");
cout<<"\n1. Add Song";
cout<<"\n2. Display Playlist";
cout<<"\n3. Search Song ";
cout<<"\n4. Modify Song";
cout<<"\n5. Delete Song";;
cout<<"\n6. Exit";
cout<<"\nPress(1-6): ";
cin>>ch;
system("cls");
switch(ch)
{
case '1': writeSong(); break;
case '2': display(); break;
//case '3': cout<<"\nPlease enter the song: \n"; cin>>n;
//searchSong(n); break;
case '4': cout<<"\nPlease enter the song : \n"; cin>>n;
modifySong(n);break;
case '5': cout<<"\nPlease enter the song: \n"; cin>>n;
deleteSong(n);break;
case '6': exit(0);;
default: cout<<"\a";
    }
}while(ch!='6');
return 0;
}

