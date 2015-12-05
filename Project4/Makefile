# Makefile for programming project 4
#
# CSCI 21, Fall 2015
#
# Programmer: Steve Ross-Byers
#

FLAGS = -Wall -Wextra -pedantic

# Date completed: 12-3-2015
project4: project4.o Word.o
	g++ -o project4 $(FLAGS) project4.o Word.o
	
project4.o: project4.cpp
	g++ $(FLAGS) -c project4.cpp

Word.o: Word.cpp
	g++ $(FLAGS) -c Word.cpp

clean: 	
	rm -f *.o
	
cleanall: clean
	rm -f project4