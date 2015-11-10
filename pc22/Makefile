# Makefile for programming challenge 22
#
# CSCI 21, Fall 2015
#
# Programmer: Steve Ross-Byers
#

FLAGS = -Wall -Wextra -pedantic

# Targets for programming project 20
# Date completed: 11-8-2015
pc22: pc22.o
	g++ -o pc22 $(FLAGS) pc22.o

pc22.o: pc22.cpp
	g++ $(FLAGS) -c pc22.cpp

clean: 	
	rm -f *.o
	
cleanall: clean
	rm -f pc22