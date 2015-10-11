# Makefile for programming challenges
#
# CSCI 21, Fall 2015
#
# Programmer: Steve Ross-Byers
#

# Target for programming challenge 1
# Date completed: 8-25-2015
pc1: pc1.cpp
	g++ -o pc1 pc1.cpp

# Target for programming challenge 2
# Date completed: 8-26-2015
pc2: pc2.cpp
	g++ -o pc2 pc2.cpp

# Target for programming challenge 3
# Date completed: 8-27-2015
pc3: pc3.cpp
	g++ -o pc3 pc3.cpp
	
# Target for programming challenge 4
# Date completed: 9-2-2015
pc4: pc4.cpp
	g++ -o pc4 pc4.cpp
	
# Target for programming challenge 5
# Date completed: 9-6-2015
pc5: pc5.cpp
	g++ -o pc5 pc5.cpp
	
# Target for programming challenge 6
# Date completed: 9-10-2015
pc6: pc6.cpp
	g++ -o pc6 pc6.cpp
	
# Target for programming challenge 7
# Date completed: 9-13-2015
pc7: pc7.cpp
	g++ -o pc7 pc7.cpp
	
# Target for programming challenge 8
# Date completed: 9-15-2015
pc8: pc8.cpp
	g++ -o pc8 pc8.cpp
	
# Target for programming challenge 9
# Date completed: 9-20-2015
pc9: pc9.cpp
	g++ -o pc9 pc9.cpp

# Target for programming challenge 10
# Date completed: 9-22-2015
pc10: pc10.cpp
	g++ -o pc10 pc10.cpp

# Target for programming challenge 11
# Date completed: 9-22-2015
pc11: pc11.cpp
	g++ -o pc11 pc11.cpp

# Target for programming challenge 12
# Date completed: 9-29-2015
pc12: pc12.cpp
	g++ -o pc12 pc12.cpp

# Target for programming challenge 13
# Date completed: 10-3-2015
pc13: pc13.cpp
	g++ -o pc13 pc13.cpp

# Target for programming challenge 14
# Date completed: 10-3-2015
pc14: pc14.cpp
	g++ -o pc14 pc14.cpp

# Target for programming challenge 15
# Date completed: 10-5-2015
pc15: pc15.cpp
	g++ -o pc15 pc15.cpp

# Target for programming project 1
# Date completed: 9-13-2015
project1: project1.cpp
	g++ -o project1 project1.cpp
	
# Target for programming project 2 (with individual objects and clean options)
# Date completed: 10-11-2015
project2: project2.o box.o prize.o
	g++ -o project2 project2.o box.o prize.o
	
project2.o: project2.cpp
	g++ -c project2.cpp
	
box.o: box.cpp
	g++ -c box.cpp
	
prize.o: prize.cpp
	g++ -c prize.cpp
	
clean:
	rm box.o prize.o project2.o
	
cleanall:
	rm box.o prize.o project2.o project2