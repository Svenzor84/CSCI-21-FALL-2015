# Makefile for programming challenge 20
#
# CSCI 21, Fall 2015
#
# Programmer: Steve Ross-Byers
#

FLAGS = -Wall -Wextra -pedantic

# Targets for programming project 20
# Date completed: 11-1-2015
pc20: pc20.o SList.o SLNode.o
	g++ -o pc20 $(FLAGS) pc20.o SList.o SLNode.o
	
pc20.o: pc20.cpp
	g++ $(FLAGS) -c pc20.cpp
	
SList.o: SList.cpp
	g++ $(FLAGS) -c SList.cpp
	
SLNode.o: SLNode.cpp
	g++ $(FLAGS) -c SLNode.cpp
	
clean: 	
	rm -f *.o
	
cleanall: clean
	rm -f pc20