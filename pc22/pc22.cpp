/*
 * Programming Challenge 22 - UNIT TEST
 */

#include "SList.hpp"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

//#include <string>
using std::string;

TEST_CASE ("SList<int> full functionality") {
	SList<int> intList;

	CHECK(intList.getSize() == 0);
	CHECK(intList.toString() == "");

	intList.insert(10);
	CHECK(intList.getSize() == 1);
	CHECK(intList.toString() == "10");

	intList.insert(10);
	CHECK(intList.getSize() == 2);
	CHECK(intList.toString() == "10,10");

	intList.insert(30);
	CHECK(intList.getSize() == 3);
	CHECK(intList.toString() == "10,10,30");

	intList.insert(30);
	CHECK(intList.getSize() == 4);
	CHECK(intList.toString() == "10,10,30,30");

	intList.insert(15);
	CHECK(intList.getSize() == 5);
	CHECK(intList.toString() == "10,10,15,30,30");

	intList.insertHead(5);
	CHECK(intList.getSize() == 6);
	CHECK(intList.toString() == "5,10,10,15,30,30");

	intList.insert(50);
	CHECK(intList.getSize() == 7);
	CHECK(intList.toString() == "5,10,10,15,30,30,50");

	CHECK(intList.removeFirst(1) == false);
	CHECK(intList.removeAll(100) == false);

	CHECK(intList.removeFirst(10) == true);
	CHECK(intList.getSize() == 6);
	CHECK(intList.toString() == "5,10,15,30,30,50");

	CHECK(intList.removeAll(30) == true);
	CHECK(intList.getSize() == 4);
	CHECK(intList.toString() == "5,10,15,50");

	intList.removeHead();
	CHECK(intList.getSize() == 3);
	CHECK(intList.toString() == "10,15,50");

	intList.removeTail();
	CHECK(intList.getSize() == 2);
	CHECK(intList.toString() == "10,15");

	intList.clear();
	CHECK(intList.getSize() == 0);
	CHECK(intList.toString() == "");
}

TEST_CASE ("SList<string> full functionality") {
	SList<string> stringList;

	CHECK(stringList.getSize() == 0);
	CHECK(stringList.toString() == "");

	stringList.insert("hello");
	CHECK(stringList.getSize() == 1);
	CHECK(stringList.toString() == "hello");

	stringList.insert("hello");
	CHECK(stringList.getSize() == 2);
	CHECK(stringList.toString() == "hello,hello");

	stringList.insert("mellow");
	CHECK(stringList.getSize() == 3);
	CHECK(stringList.toString() == "hello,hello,mellow");

	stringList.insert("mellow");
	CHECK(stringList.getSize() == 4);
	CHECK(stringList.toString() == "hello,hello,mellow,mellow");

	stringList.insert("jello");
	CHECK(stringList.getSize() == 5);
	CHECK(stringList.toString() == "hello,hello,jello,mellow,mellow");

	stringList.insertHead("cello");
	CHECK(stringList.getSize() == 6);
	CHECK(stringList.toString() == "cello,hello,hello,jello,mellow,mellow");

	stringList.insert("yellow");
	CHECK(stringList.getSize() == 7);
	CHECK(stringList.toString() == "cello,hello,hello,jello,mellow,mellow,yellow");

	CHECK(stringList.removeFirst("fellow") == false);
	CHECK(stringList.removeAll("bellow") == false);

	CHECK(stringList.removeFirst("hello") == true);
	CHECK(stringList.getSize() == 6);
	CHECK(stringList.toString() == "cello,hello,jello,mellow,mellow,yellow");

	CHECK(stringList.removeAll("mellow") == true);
	CHECK(stringList.getSize() == 4);
	CHECK(stringList.toString() == "cello,hello,jello,yellow");

	stringList.removeHead();
	CHECK(stringList.getSize() == 3);
	CHECK(stringList.toString() == "hello,jello,yellow");

	stringList.removeTail();
	CHECK(stringList.getSize() == 2);
	CHECK(stringList.toString() == "hello,jello");

	stringList.clear();
	CHECK(stringList.getSize() == 0);
	CHECK(stringList.toString() == "");	
}
