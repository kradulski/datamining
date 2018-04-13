CC = g++ -std=c++11 -Wall

all: assignment3.x

assignment3.x: assignment3.o
	$(CC) -o assignment3.x assignment3.o

assignment3.o: assignment3.cpp
	$(CC) -c assignment3.cpp


clean:
	rm *.o *.x
