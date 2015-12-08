# Makefile for programming challange 29
#
# CSCI 21, Fall 2015
#
# Programmer: Steve Ross-Byers
#

FLAGS = -Wall -Wextra -pedantic -std=c++11

# Date completed: 12-7-2015
pc29: pc29.o
	g++ -o pc29 $(FLAGS) pc29.o
	
pc29.o: pc29.cpp
	g++ $(FLAGS) -c pc29.cpp
	
clean: 	
	rm -f *.o
	
cleanall: clean
	rm -f pc29