all: all.out
all.out: song.o songGenre.o songDb.o song-test.o songDb-test.o
        g++ $^ -o $@ -lgtest -lgtest_main -lpthread
songDb-test.o: songDb-test.cpp song.h songGenre.h songDb.h
        g++ $< -c
song-test.o: song-test.cpp song.h songGenre.h
        g++ $< -c
songDb.o: songDb.cpp songDb.h songGenre.h song.h
        g++ $< -c
songGenre.o: songGenre.cpp songGenre.h song.h
        g++ $< -c
song.o: song.cpp song.h
        g++ $< -c
clean:
        rm -rf *.o *.out

