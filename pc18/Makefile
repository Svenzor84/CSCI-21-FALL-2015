# Makefile for programming challenge 18
#
# CSCI 21, Fall 2015
#
# Programmer: Steve Ross-Byers
#

FLAGS = -Wall -Wextra -pedantic

# Targets for programming project 18
# Date completed: 10-22-2015
pc18: pc18.o SList.o SLNode.o
	g++ -o pc18 $(FLAGS) pc18.o SList.o SLNode.o
	
pc18.o: pc18.cpp
	g++ $(FLAGS) -c pc18.cpp
	
SList.o: SList.cpp
	g++ $(FLAGS) -c SList.cpp
	
SLNode.o: SLNode.cpp
	g++ $(FLAGS) -c SLNode.cpp
	
clean: 	
	rm -f *.o
	
cleanall: clean
	rm -f pc18