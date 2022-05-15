main: main.o heap.o
	g++ -o main main.o heap.o
tests: tests.o heap.o
	g++ -o tests tests.o heap.o
main.o: main.cpp heap.h
	g++ -c main.cpp
heap.o: heap.cpp heap.h
	g++ -c heap.cpp
clean: 
	rm -f heap.o tests.o main.o