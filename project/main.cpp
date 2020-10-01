#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

class playlist
{
char category[5];
int songId;
char song[50];
char artist[50];
float price;
int quantity;
public:
void getSong();
void showSong() const;
void displayAllSongs() const;
int getId() const;
};

void playlist::getSong()
{
cout<<"\nEnter category of the song: ";
cin.ignore();
cin.getline(category,5);

cout<<"\nEnter song Id: ";
cin>>songId;

cout<<"\nEnter Song: ";
cin.ignore();
cin.getline(song,50);

cout<<"\nArtist: ";
cin.ignore();
cin.getline(artist,50);

cout<<"\nPrice: ";
cin>>price;

cout<<"\nQuantity: ";
cin>>quantity;
}

void playlist::showSong() const
{
cout<<"\nCategory: "<<category;
cout<<"\nSong Id: "<<songId;
cout<<"\nSong: "<<song;
cout<<"\nArtist: "<<artist;
cout<<"\nPrice: "<<price;
cout<<"\nQuantity: "<<quantity;
}

void playlist::displayAllSongs() const
{
cout<<category<<"\t"<<songId<<"\t"<<song<<"\t"<<artist<<"\t"<<price<<"\t"<<quantity<<endl;
}

int  playlist::getId() const
{
return songId;
}



void addSong();
void displayAllSongs();
void searchSong(int);
void editSong(int);
void deleteSong(int);
void songs();
//void DisplayResult();





void addSong()
{
playlist plylst;
ofstream outFile;
outFile.open("playlist.dat",ios::binary|ios::app);
plylst.getSong();
outFile.write(reinterpret_cast<char *> (&plylst), sizeof(playlist));
outFile.close();
    cout<<"\nAdded song to the playlist";
cin.ignore();
cin.get();
}



void displayAllSongs()
{
playlist plylst;
ifstream inFile;
inFile.open("playlist.dat",ios::binary);
if(!inFile)
{
cout<<"File could not be open !! Press any Key...";
cin.ignore();
cin.get();
return;
}
cout<<"\nPLAYLIST";
while(inFile.read(reinterpret_cast<char *> (&plylst), sizeof(playlist)))
{
plylst.showSong();
//cout<<"\t====================================\t";
}
inFile.close();
cin.ignore();
cin.get();
}




void searchSong(int n)
{
playlist plylst;
ifstream inFile;
inFile.open("playlist.dat",ios::binary);
if(!inFile)
{
cout<<"File could not be open !! Press any Key...";
cin.ignore();
cin.get();
return;
}
bool flag=false;
while(inFile.read(reinterpret_cast<char *> (&plylst), sizeof(playlist)))
{
if(plylst.getId()==n)
{
  plylst.showSong();
flag=true;
}
}
inFile.close();
if(flag==false)
cout<<"\n\nrecord not exist";
cin.ignore();
cin.get();
}


void editSong(int n)
{
bool found=false;
playlist plylst;
fstream File;
File.open("playlist.dat",ios::binary|ios::in|ios::out);
if(!File)
{
cout<<"File could not be open !! Press any Key...";
cin.ignore();
cin.get();
return;
}
    while(!File.eof() && found==false)
{

File.read(reinterpret_cast<char *> (&plylst), sizeof(playlist));
if(plylst.getId()==n)
{
plylst.showSong();
cout<<"\n\nPlease Enter The New Details of songs"<<endl;
plylst.getSong();
    int pos=(-1)*static_cast<int>(sizeof(plylst));
    File.seekp(pos,ios::cur);
    File.write(reinterpret_cast<char *> (&plylst), sizeof(playlist));
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
playlist plylst;
ifstream inFile;
inFile.open("playlist.dat",ios::binary);
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
while(inFile.read(reinterpret_cast<char *> (&plylst), sizeof(playlist)))
{
if(plylst.getId()!=n)
{
outFile.write(reinterpret_cast<char *> (&plylst), sizeof(playlist));
}
}
outFile.close();
inFile.close();
remove("playlist.dat");
rename("Temp.dat","playlist.dat");
cout<<"\n\n\tRecord Deleted ..";
cin.ignore();
cin.get();
}
/*

void songs()
{
playlist plylst;
ifstream inFile;
inFile.open("playlist.dat",ios::binary);
if(!inFile)
{
cout<<"File could not be open !! Press any Key...";
cin.ignore();
cin.get();
return;
}
cout<<"\tALL SONGS \t";
cout<<"==========================================================\n";
cout<<"R.No       Name        P   C   M   E   CS   %age   Grade"<<endl;
cout<<"==========================================================\n";
while(inFile.read(reinterpret_cast<char *> (&plylst), sizeof(playlist)))
{
plylst.displayAllSongs();
}
cin.ignore();
cin.get();
inFile.close();
}
*/



int main()
{
char ch;
int num;
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
case '1': addSong(); break;
case '2': displayAllSongs(); break;
case '3': cout<<"\nPlease enter the id"; cin>>num;
searchSong(num); break;
case '4': cout<<"\nPlease enter the id: "; cin>>num;
editSong(num);break;
case '5': cout<<"\nPlease enter the id: "; cin>>num;
deleteSong(num);break;
case '6': exit(0);;
default: cout<<"\a";

    }
}while(ch!='6');

return 0;
}

