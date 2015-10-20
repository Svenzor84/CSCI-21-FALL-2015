# Makefile for programming challenges
#
# CSCI 21, Fall 2015
#
# Programmer: Steve Ross-Byers
#

FLAGS = -Wall -Wextra -pedantic


# Targets for programming project 2 (with individual objects and clean options)
# Date completed: 10-11-2015
project2: project2.o prize.o box.o CinReader.o
	g++ -o project2 $(FLAGS) project2.o box.o prize.o CinReader.o
	
project2.o: project2.cpp
	g++ $(FLAGS) -c project2.cpp

prize.o: prize.cpp
	g++ $(FLAGS) -c prize.cpp

box.o: box.cpp
	g++ $(FLAGS) -c box.cpp
	
CinReader.o: CinReader.cpp
	g++ $(FLAGS) -c CinReader.cpp

clean:
	rm -f *.o
	
cleanall: clean
	rm -f project2