# Makefile for programming challange 24
#
# CSCI 21, Fall 2015
#
# Programmer: Steve Ross-Byers
#

FLAGS = -Wall -Wextra -pedantic

# Targets for programming challenge 24
# Date completed: 11-15-2015
pc24: pc24.o BSTNode.o
	g++ -o pc24 $(FLAGS) pc24.o BSTNode.o
	
pc24.o: pc24.cpp
	g++ $(FLAGS) -c pc24.cpp
	
BSTNode.o: BSTNode.cpp
	g++ $(FLAGS) -c BSTNode.cpp

clean: 	
	rm -f *.o
	
cleanall: clean
	rm -f pc24