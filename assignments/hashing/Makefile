main: main.o node.o list.o set.o person.o
	g++ -o main set.o list.o node.o main.o person.o
tests: tests.o node.o list.o set.o person.o
	g++ -o tests set.o list.o tests.o node.o person.o
main.o: set.h main.cpp 
	g++ -c main.cpp
node.o: node.cpp node.h
	g++ -c node.cpp 
tests.o: bstree.h tests.cpp 
	g++ -c tests.cpp
set.o: set.cpp set.h
	g++ -c set.cpp
person.o: person.cpp person.h
	g++ -c person.cpp
list.o: list.cpp list.h
	g++ -c list.cpp
clean:
	rm -f set.o list.o person.o node.o main.o tests.o