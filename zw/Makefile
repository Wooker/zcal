CPP = g++
STD = -std=c++11
SRC = main.cpp ../src/event.cpp ../src/day.cpp ../src/month.cpp

main: main.o
	$(CPP) $(STD) main.o -l sqlite3 -o zw.out

main.o: src/main.cpp 
	$(CPP) -l sqlite3 -c src/main.cpp -o main.o

month.o: ../src/month.cpp ../headers/month.h
	$(CPP) -c ../src/month.cpp -o month.o

day.o: ../src/day.cpp ../headers/day.h ../headers/month.h
	$(CPP) -c ../src/day.cpp -o day.o

event.o: ../src/event.cpp ../headers/event.h ../headers/day.h
	$(CPP) -c ../src/event.cpp -o event.o

.PHONY: clean
clean:
	$(RM) *.o $(objects) main
