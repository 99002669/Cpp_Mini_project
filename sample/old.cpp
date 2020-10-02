#include"old.h"
#include<iostream>
#include<fstream>
using namespace std;

OldSong::OldSong():SongBase(){}
OldSong::OldSong(int Id,std::string name,std::string artist,double price, int quantity):SongBase(Id,name,artist,price,quantity){}



void OldSong::getSong()
{
    writeagain:
        cout<<"enter Id";
        cin>>songId;
        OldSong od;
        ifstream inFile;
        inFile.open("Song.dat",ios::binary);
        while(inFile.read(reinterpret_cast<char *> (&od),sizeof(OldSong)))
        {
            if(songId==od.songId)
            {
                cout<<"please enter correct Id";
                goto writeagain;
            }
        }
        {
            cout<<"enter song name: ";
            cin>>songName;
            cout<<"enter song artist: ";
            cin>>songArtist;
            cout<<"enter song price: ";
            cin>>songPrice;
            cout<<"enter song quantity: ";
            cin>>songQuantity;
        }
}

void writeSong()
{
    OldSong od;
    ofstream outFile;
    outFile.open("Song.dat",ios::binary|ios::app);
    od.getSong();
    outFile.write(reinterpret_cast<char *> (&od),sizeof(OldSong));
    outFile.close();
    cout<<"song has been added";
    cin.ignore();
    cin.get();
}

void OldSong::modSong()
{
    cout<<"enter Id: ";
    cin>>songId;
    cout<<"enter song name: ";
    cin>>songName;
    cout<<"enter song artist: ";
    cin>>songArtist;
    cout<<"enter song price: ";
    cin>>songPrice;
    cout<<"enter song quantity: ";
    cin>>songQuantity;
}



void OldSong::showSong()
{
    cout<<"Id is: "<<songId;
    cout<<"Name is: "<<songName;
    cout<<"Artist is: "<<songArtist;
    cout<<"Price is: "<<songPrice;
    cout<<"Quantity is: "<<songQuantity;
}

int OldSong::getSongId()
{
    return songId;
}
void modifySong(int n)
{
    bool found=false;
OldSong od;
fstream File;
File.open("Song.dat",ios::binary|ios::in|ios::out);
if(!File)
{
cout<<"File could not be open !! Press any Key...";
cin.ignore();
cin.get();
return;
}
    while(!File.eof() && found==false)
{

File.read(reinterpret_cast<char *> (&od), sizeof(OldSong));
if(od.getSongId()==n)
{
od.showSong();
cout<<"\n\nPlease Enter The New Details of songs";
od.modSong();
    int pos=(-1)*static_cast<int>(sizeof(od));
    File.seekp(pos,ios::cur);
    File.write(reinterpret_cast<char *> (&od), sizeof(OldSong));
    cout<<"\n\n\t Record Updated";
    found=true;
}
}
File.close();
if(found==false)
cout<<"\n\n Record Not Found ";
cin.ignore();
cin.get();
}

void deleteSong(int n)
{
OldSong od;
ifstream inFile;
inFile.open("Song.dat",ios::binary);
if(!inFile)
{
cout<<"File could not be open !! Press any Key...";
cin.ignore();
cin.get();
return;
}
ofstream outFile;
outFile.open("Temp.dat",ios::out);
inFile.seekg(0,ios::beg);
while(inFile.read(reinterpret_cast<char *> (&od), sizeof(OldSong)))
{
if(od.getSongId()!=n)
{
outFile.write(reinterpret_cast<char *> (&od), sizeof(OldSong));
}
}
outFile.close();
inFile.close();
remove("Song.dat");
rename("Temp.dat","Song.dat");
cout<<"\n\n\tRecord Deleted ..";
cin.ignore();
cin.get();
}

