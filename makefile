all: Boat
Boat: removal main.o boat.o
	g++ -o boat main.o boat.o
main.o: main.cpp
	g++ -c -g main.cpp
boat.o: boat.cpp
	g++ -c -g boat.cpp
removal:
	rm -f *.o