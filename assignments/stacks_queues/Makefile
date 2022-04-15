main: main.o list.o node.o stack.o queue.o
	g++ -o main stack.o main.o list.o node.o queue.o
tests: tests.o list.o node.o stack.o queue.o
	g++ -o tests stack.o tests.o list.o node.o queue.o
stack.o: stack.cpp stack.h 
	g++ -c stack.cpp
main.o: stack.h main.cpp queue.h
	g++ -c main.cpp
node.o: node.cpp node.h
	g++ -c node.cpp
list.o: list.cpp list.h node.h
	g++ -c list.cpp
queue.o: queue.cpp queue.h
	g++ -c queue.cpp
tests.o: stack.h tests.cpp queue.h
	g++ -c tests.cpp
clean:
	rm -f stack.o list.o node.o main.o 