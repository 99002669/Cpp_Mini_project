#include "song.h"
#include "songGenre.h"
#include "songDb.h"
#include <gtest/gtest.h>

namespace {

class SongTest : public ::testing::Test {

  protected:
    void SetUp() {
        ptr = new SongGenre(1,"Believer", 23.00, "Imagine Dragons", "Pop Rock","2017");
    }
    void TearDown() {
        delete ptr;
    }
    Song *ptr;
};

TEST_F(SongTest, DefaultConstructor) {
    SongGenre ft;
    EXPECT_EQ(0, ft.getID());
    EXPECT_EQ(0, ft.getGenre().length());
    EXPECT_EQ(0, ft.getName().length());
    EXPECT_EQ(0, ft.getPrice());
}
TEST_F(SongTest, ParameterizedConstructor) {
    SongGenre *fptr = dynamic_cast<SongGenre*>(ptr);
    EXPECT_EQ( 1, fptr->getID());
    EXPECT_STREQ("Pop Rock", fptr->getGenre().c_str());
    EXPECT_STREQ("Believer", fptr->getName().c_str());
    EXPECT_EQ(23.00, fptr->getPrice());
}
TEST_F(SongTest, AnotherTest) {
    SongGenre ft(2,"Despacito", 30.00, "Luis Fonsi", "Latin Pop","2017");
    Song *pt = &ft;
    EXPECT_EQ( 2, ft.getID());
    EXPECT_STREQ("Latin Pop", ft.getGenre().c_str());
    EXPECT_STREQ("Despacito", ft.getName().c_str());
    EXPECT_EQ(30.00, ft.getPrice());
}

}


