
#include "song.h"
#include "songGenre.h"
#include "songDb.h"
#include <gtest/gtest.h>
#include<iostream>
#include<pthread.h>
#include<semaphore.h>
#include<list>
#include<iterator>
#include<cstdint>


pthread_mutex_t m1=PTHREAD_MUTEX_INITIALIZER;
sem_t s1;
SongDb songs;


void* efun1(void* pv) {



    pthread_mutex_lock(&m1);

    songs.addSong(1,"Believer", 23.00, "Imagine Dragons", "Pop Rock","2017");
    songs.addSong(2,"Despacito", 30.00, "Luis Fonsi", "Latin Pop","2017");
    songs.addSong(3,"Barbie Girl", 25.00, "Aqua", "Bubblegum Pop","1997");
    songs.addSong(4,"Count on me", 27.00, "Bruno Mars", "Folk","2011");
    songs.addSong(5,"Faded", 35.00, "Alan Walker", "Electro House","2015");
    songs.addSong(6,"Worth it", 60.21, "Fifth Harmony", "Dance Pop","2015");

    pthread_mutex_unlock(&m1);
    sem_post(&s1);

}


void* efun2(void* pv) {


    sem_wait(&s1);            //changing sequence lead to deadlock
    pthread_mutex_lock(&m1);

    std::cout<<"\n";
    std::cout<<"The owner added :"<<songs.countAll()<<" Songs\n";
    std::cout<<"\n";

    pthread_mutex_unlock(&m1);
    //pthread_exit(NULL);
}

namespace {

class SongGenreDbTest : public ::testing::Test {

  protected:
    void SetUp() {

    }
    void TearDown() {}
};

TEST_F(SongGenreDbTest, AddSongTest) {

    pthread_t pt1,pt2;    //thread handles
    sem_init(&s1,0,0);
    pthread_create(&pt1,NULL,efun1,NULL);
    pthread_create(&pt2,NULL,efun2,NULL);
    pthread_join(pt1,NULL);
    pthread_join(pt2,NULL);

    songs.addSong(7,"I like me better", 32.00, "Lauv", "Electro Pop","2017");
    EXPECT_EQ(7, songs.countAll());

    sem_destroy(&s1);
    pthread_mutex_destroy(&m1);
}


TEST_F(SongGenreDbTest, RemoveSongTest) {
    songs.removeSong("Believer");
    EXPECT_EQ(6, songs.countAll());
}
TEST_F(SongGenreDbTest, CountTest) {             //Just After Setup
    EXPECT_EQ(6, songs.countAll());
}

TEST_F(SongGenreDbTest, AnotherTest) {         //Just After Setup
    songs.addSong(8,"Little bit", 10.00, "MattyBRaps", "Indie Pop","2018");
    songs.addSong(9,"See you again", 29.00, "Wiz Khalifa", "Hip Hop","2015");
    EXPECT_EQ(8, songs.countAll());

}
}

