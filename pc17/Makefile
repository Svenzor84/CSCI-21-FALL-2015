# Makefile for programming challenge 17
#
# CSCI 21, Fall 2015
#
# Programmer: Steve Ross-Byers
#

FLAGS = -Wall -Wextra -pedantic

# Targets for programming project 17
# Date completed: 10-20-2015
pc17: pc17.o SLNode.o
	g++ -o pc17 $(FLAGS) pc17.o SLNode.o
	
pc17.o: pc17.cpp
	g++ $(FLAGS) -c pc17.cpp
	
SLNode.o: SLNode.cpp
	g++ $(FLAGS) -c SLNode.cpp
	
clean: 	
	rm -f *.o
	
cleanall: clean
	rm -f pc17