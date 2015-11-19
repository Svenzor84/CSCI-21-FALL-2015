# Makefile for programming challange 25
#
# CSCI 21, Fall 2015
#
# Programmer: Steve Ross-Byers
#

FLAGS = -Wall -Wextra -pedantic

# Targets for programming challenge 25
# Date completed: 11-17-2015
pc25: pc25.o BSTNode.o BSTree.o
	g++ -o pc25 $(FLAGS) pc25.o BSTNode.o BSTree.o
	
pc25.o: pc25.cpp
	g++ $(FLAGS) -c pc25.cpp
	
BSTNode.o: BSTNode.cpp
	g++ $(FLAGS) -c BSTNode.cpp
	
BSTree.o: BSTree.cpp
	g++ $(FLAGS) -c BSTree.cpp

clean: 	
	rm -f *.o
	
cleanall: clean
	rm -f pc25