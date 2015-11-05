# Makefile for programming challenge 21
#
# CSCI 21, Fall 2015
#
# Programmer: Steve Ross-Byers
#

FLAGS = -Wall -Wextra -pedantic

# Targets for programming project 21
# Date completed: 11-3-2015

pc21: pc21.o
	g++ -o pc21 $(FLAGS) pc21.o

pc21.o: pc21.cpp
	g++ $(FLAGS) -c pc21.cpp
	
clean: 	
	rm -f *.o
	
cleanall: clean
	rm -f pc21