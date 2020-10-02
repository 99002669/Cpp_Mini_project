#include"new.h"
#include<iostream>
#include<fstream>
using namespace std;
NewSong::NewSong():SongBase(){}
NewSong::NewSong(int Id,std::string name,std::string artist,double price, int quantity):SongBase(Id,name,artist,price,quantity){}


void NewSong::getSong()
{
    writeagain:
        cout<<"enter Id";
        cin>>songId;
        NewSong ns;
        ifstream inFile;
        inFile.open("Song.dat",ios::binary);
        while(inFile.read(reinterpret_cast<char *> (&ns),sizeof(NewSong)))
        {
            if(songId==ns.songId)
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
    NewSong ns;
    ofstream outFile;
    outFile.open("Song.dat",ios::binary|ios::app);
    ns.getSong();
    outFile.write(reinterpret_cast<char *> (&ns),sizeof(NewSong));
    outFile.close();
    cout<<"song has been added";
    cin.ignore();
    cin.get();
}

void NewSong::modSong()
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

void modifySong(int n)
{
    bool found=false;
NewSong ns;
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

File.read(reinterpret_cast<char *> (&ns), sizeof(NewSong));
if(ns.getSongId()==n)
{
ns.showSong();
cout<<"\n\nPlease Enter The New Details of songs"<<endl;
ns.modSong();
    int pos=(-1)*static_cast<int>(sizeof(ns));
    File.seekp(pos,ios::cur);
    File.write(reinterpret_cast<char *> (&ns), sizeof(NewSong));
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


void NewSong::showSong()
{
    cout<<"Id is: "<<songId;
    cout<<"Name is: "<<songName;
    cout<<"Artist is: "<<songArtist;
    cout<<"Price is: "<<songPrice;
    cout<<"Quantity is: "<<songQuantity;
}

int NewSong::getSongId()
{
    return songId;
}

void deleteSong(int n)
{
NewSong ns;
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
while(inFile.read(reinterpret_cast<char *> (&ns), sizeof(NewSong)))
{
if(ns.getSongId()!=n)
{
outFile.write(reinterpret_cast<char *> (&ns), sizeof(NewSong));
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


