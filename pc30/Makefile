# Makefile for programming challange 30
#
# CSCI 21, Fall 2015
#
# Programmer: Steve Ross-Byers
#

FLAGS = -Wall -Wextra -pedantic -std=c++11

# Date completed: 12-9-2015
pc30: pc30.o
	g++ -o pc30 $(FLAGS) pc30.o
	
pc30.o: pc30.cpp
	g++ $(FLAGS) -c pc30.cpp
	
clean: 	
	rm -f *.o
	
cleanall: clean
	rm -f pc30