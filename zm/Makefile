CPP = g++
STD = -std=c++11

main: main.o
	$(CPP) $(STD) main.o -l sqlite3 -o zm.out

main.o: src/main.cpp 
	$(CPP) -l sqlite3 -c src/main.cpp -o main.o

.PHONY: clean
clean:
	$(RM) *.o $(objects) main
