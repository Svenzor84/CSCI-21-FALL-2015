# Makefile for programming challenge 19
#
# CSCI 21, Fall 2015
#
# Programmer: Steve Ross-Byers
#

FLAGS = -Wall -Wextra -pedantic

# Targets for programming project 19
# Date completed: 10-22-2015
pc19: pc19.o SList.o SLNode.o
	g++ -o pc19 $(FLAGS) pc19.o SList.o SLNode.o
	
pc19.o: pc19.cpp
	g++ $(FLAGS) -c pc19.cpp
	
SList.o: SList.cpp
	g++ $(FLAGS) -c SList.cpp
	
SLNode.o: SLNode.cpp
	g++ $(FLAGS) -c SLNode.cpp
	
clean: 	
	rm -f *.o
	
cleanall: clean
	rm -f pc19