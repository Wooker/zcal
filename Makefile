CPP = g++
RM  = rm -f
STD = -std=c++11
SRC = src/main.cpp src/calendar.cpp src/today.cpp


main: main.o calendar.o today.o
	$(CPP) main.o calendar.o today.o -o main

main.o: src/main.cpp headers/today.h headers/calendar.h
	$(CPP) -c src/main.cpp -o main.o

calendar.o: src/calendar.cpp headers/calendar.h headers/today.h
	$(CPP) -c src/calendar.cpp -o calendar.o

today.o: src/today.cpp headers/today.h
	$(CPP) -c src/today.cpp -o today.o

clean:
	rm -rf *.out
