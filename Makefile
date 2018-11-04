CPP = g++
STD = -std=c++11
SRC = src/main.cpp src/calendar.cpp src/today.cpp

main: main.o calendar.o day.o month.o
	$(CPP) $(STD) main.o calendar.o day.o month.o -o a.out

main.o: src/main.cpp headers/calendar.h headers/day.h headers/month.h
	$(CPP) -c src/main.cpp -o main.o

calendar.o: src/calendar.cpp headers/calendar.h headers/today.h
	$(CPP) -c src/calendar.cpp -o calendar.o

today.o: src/today.cpp headers/today.h
	$(CPP) -c src/today.cpp -o today.o

month.o: src/month.cpp headers/month.h
	$(CPP) -c src/month.cpp -o month.o

day.o: src/day.cpp headers/day.h
	$(CPP) -c src/day.cpp -o day.o

.PHONY: clean
clean:
	$(RM) *.o $(objects) main
