main: main.o Node.o List.o
	g++ -o main main.o Node.o List.o 
tests: test.o Node.o List.o
	g++ -o tests test.o Node.o List.o
test.o: test.cpp Node.h List.h
	g++ -c test.cpp
main.o: main.cpp Node.h List.h
	g++ -c main.cpp
Node.o: Node.cpp Node.h
	g++ -c Node.cpp
List.o: List.cpp List.h Node.h
	g++ -c List.cpp
clean:
	rm -f List.o main.o Node.o  test.o