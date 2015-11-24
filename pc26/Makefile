# Makefile for programming challange 26
#
# CSCI 21, Fall 2015
#
# Programmer: Steve Ross-Byers
#

FLAGS = -Wall -Wextra -pedantic

# Date completed: 11-22-2015
pc26: pc26.o BSTNode.o BSTree.o
	g++ -o pc26 $(FLAGS) pc26.o BSTNode.o BSTree.o
	
pc26.o: pc26.cpp
	g++ $(FLAGS) -c pc26.cpp
	
BSTNode.o: BSTNode.cpp
	g++ $(FLAGS) -c BSTNode.cpp
	
BSTree.o: BSTree.cpp
	g++ $(FLAGS) -c BSTree.cpp

clean: 	
	rm -f *.o
	
cleanall: clean
	rm -f pc26