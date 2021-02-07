CC = g++
CFLAGS = -std=c++11 -c -g -Og -Wall -Werror -pedantic
OBJ =  PhotoMagic.o LFSR.o
DEPS = LFSR.hpp
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
EXE = PhotoMagic

all: PhotoMagic

PhotoMagic: PhotoMagic.o LFSR.o
	$(CC) PhotoMagic.o LFSR.o -o PhotoMagic $(LIBS)

LFSR.o: LFSR.cpp $(DEPS)
	$(CC) $(CFLAGS) -o LFSR.o LFSR.cpp

PhotoMagic.o: PhotoMagic.cpp $(DEPS)
	$(CC) $(CFLAGS) -o PhotoMagic.o PhotoMagic.cpp

clean:
	rm $(OBJ) $(EXE)
