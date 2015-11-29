# Makefile for programming challange 27
#
# CSCI 21, Fall 2015
#
# Programmer: Steve Ross-Byers
#

FLAGS = -Wall -Wextra -pedantic

# Date completed: 11-29-2015
pc27: pc27.o BSTNode.o BSTree.o Utility.o
	g++ -o pc27 $(FLAGS) pc27.o BSTNode.o BSTree.o Utility.o
	
pc27.o: pc27.cpp
	g++ $(FLAGS) -c pc27.cpp
	
BSTNode.o: BSTNode.cpp
	g++ $(FLAGS) -c BSTNode.cpp
	
BSTree.o: BSTree.cpp
	g++ $(FLAGS) -c BSTree.cpp

Utility.o: Utility.cpp
	g++ $(FLAGS) -c Utility.cpp

clean: 	
	rm -f *.o
	
cleanall: clean
	rm -f pc27