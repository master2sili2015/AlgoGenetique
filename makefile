CFLAGS  = -std=c++11 -O3


all: main.o spa.o date.o
	g++ $(CFLAGS) *.cpp -o spa.exe

main.o: main.cpp spa.o date.o
	 g++ -c $(CFLAGS) main.cpp

spa.o: spa.cpp date.o
	g++ -c $(CFLAGS) spa.cpp
     
date.o: date.cpp
	g++ -c $(CFLAGS) date.cpp
     
clean:
	 rm *.exe *.o