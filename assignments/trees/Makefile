main: main.o node.o bstree.o
	g++ -o main bstree.o node.o main.o
tests: tests.o node.o bstree.o
	g++ -o tests bstree.o tests.o node.o
main.o: bstree.h main.cpp 
	g++ -c main.cpp
node.o: node.cpp node.h
	g++ -c node.cpp 
tests.o: bstree.h tests.cpp 
	g++ -c tests.cpp
bstree.o: bstree.cpp bstree.h
	g++ -c bstree.cpp
clean:
	rm -f bstree.o node.o main.o tests.o