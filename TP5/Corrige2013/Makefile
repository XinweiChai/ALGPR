CC=g++

CXXFLAGS=-Wall -W -O0 -g

INCLUDEFLAGS= -I/opt/X11/include

all: fourmiz.out

clean:
	rm -f *.o fourmiz.out

fourmiz.out: main.o affichage.o fourmi.o monde.o proba.o
	$(CC) $(CXXFLAGS) -o fourmiz.out main.o affichage.o fourmi.o monde.o proba.o -lX11 -L/usr/X11R6/lib

main.o: main.cpp affichage.h fourmi.h monde.h constantes.h
	$(CC) $(CXXFLAGS) -c main.cpp

fourmi.o: fourmi.cpp fourmi.h proba.h constantes.h
	$(CC) $(CXXFLAGS) -c fourmi.cpp

monde.o: monde.cpp constantes.h
	$(CC) $(CXXFLAGS) -c monde.cpp

affichage.o: affichage.cpp fourmi.h affichage.h
	$(CC) $(CXXFLAGS) $(INCLUDEFLAGS) -c affichage.cpp

proba.o: proba.h proba.cpp
	$(CC) $(CXXFLAGS) -c proba.cpp
