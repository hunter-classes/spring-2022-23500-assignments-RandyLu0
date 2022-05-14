main: main.o node.o list.o map.o person.o
	g++ -o main map.o list.o node.o main.o person.o
tests: tests.o node.o list.o map.o person.o
	g++ -o tests map.o list.o tests.o node.o person.o
main.o: map.h main.cpp 
	g++ -c main.cpp
node.o: node.cpp node.h
	g++ -c node.cpp 
tests.o: bstree.h tests.cpp 
	g++ -c tests.cpp
map.o: map.cpp map.h
	g++ -c map.cpp
person.o: person.cpp person.h
	g++ -c person.cpp
list.o: list.cpp list.h
	g++ -c list.cpp
clean:
	rm -f map.o list.o person.o node.o main.o tests.o