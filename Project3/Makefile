# Makefile for programming project 3
#
# CSCI 21, Fall 2015
#
# Programmer: Steve Ross-Byers
#

FLAGS = -Wall -Wextra -pedantic

# Targets for programming project 3
# Date completed: 11-6-2015
project3: project3.o DLList.o DLNode.o
	g++ -o project3 $(FLAGS) project3.o DLList.o DLNode.o
	
project3.o: project3.cpp
	g++ $(FLAGS) -c project3.cpp
	
DLList.o: DLList.cpp
	g++ $(FLAGS) -c DLList.cpp
	
DLNode.o: DLNode.cpp
	g++ $(FLAGS) -c DLNode.cpp
	
clean: 	
	rm -f *.o
	
cleanall: clean
	rm -f project3