prog: main.o
	g++ -o run main.o

main.o: main.cpp
	g++ -g -Wall -std=c++11 -c main.cpp

clean:
	rm -f run main.o

rebuild:
	make clean
	make
