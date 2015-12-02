# Makefile for programming challange 28
#
# CSCI 21, Fall 2015
#
# Programmer: Steve Ross-Byers
#

FLAGS = -Wall -Wextra -pedantic

# Date completed: 12-1-2015
pc28: pc28.o Item.o FoodItem.o MagicItem.o
	g++ -o pc28 $(FLAGS) pc28.o Item.o FoodItem.o MagicItem.o
	
pc28.o: pc28.cpp
	g++ $(FLAGS) -c pc28.cpp
	
Item.o: Item.cpp
	g++ $(FLAGS) -c Item.cpp
	
FoodItem.o: FoodItem.cpp
	g++ $(FLAGS) -c FoodItem.cpp

MagicItem.o: MagicItem.cpp
	g++ $(FLAGS) -c MagicItem.cpp

clean: 	
	rm -f *.o
	
cleanall: clean
	rm -f pc28