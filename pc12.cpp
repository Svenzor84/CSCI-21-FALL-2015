/*
 * Programming Challenge 12
 * Created by Steve Ross-Byers on Sept 29 2015
 */
#include <cassert>
#include <iostream>
#include <string>
using namespace std;

/*
 * Allocate memory for a dynamic array of integers.
 * @param size the desired size of the dynamic array
 * @return a pointer to the newly allocated integer array
 */
int* makeDynoIntArray (unsigned int size);

/*
 * Free the memory associated with a dynamic array and NULL out its pointer.
 * @param theArray a pointer (passed by reference) to a dynamic array of integers
 */
void clearDynoIntArray (int*& theArray);

/*
 * Compute the sum of an array.
 * @param theArray the array for which the sum will be computed
 * @param arraySize the size of theArray
 * @return an integer containing the sum of the array
 * @throw ArrayException with the message "NULL ARRAY REFERENCE" if theArray is NULL
 */
int sum (int* theArray, unsigned int arraySize);

/*
 * Identify the max value in an array.
 * @param theArray the array for which the max value will be identified
 * @param arraySize the size of theArray
 * @return an integer containing the max value in the array
 * @throw ArrayException with the message "NULL ARRAY REFERENCE" if theArray is NULL
 */
int max (int* theArray, unsigned int arraySize);

/*
 * Identify the min value in an array.
 * @param theArray the array for which the min value will be identified
 * @param arraySize the size of theArray
 * @return an integer containing the min value in the array
 * @throw ArrayException with the message "NULL ARRAY REFERENCE" if theArray is NULL
 */
int min (int* theArray, unsigned int arraySize);

/* for unit testing -- do not alter */
struct ArrayException {
	ArrayException (string newMessage="error")
	: message(newMessage) {
	}
	
	string message;
};

template <typename X, typename A>
void btassert(A assertion);
void unittest ();

int main (int argc, char* argv[]) {
	unittest();
	
	return 0;
}

// CODE HERE -- FUNCTION DEFINITIONS

//allocate memory for a dynamic int array of "size", return a pointer to the array
int* makeDynoIntArray (unsigned int size){
	int* dynoArray;
	dynoArray = new int[size];
	return dynoArray;
}

//clear the memory of the dynamic array and NULL the pointer
void clearDynoIntArray (int*& theArray){
	if (theArray != NULL){
		delete [] theArray;
		theArray = NULL;
	}
}

//return the sum of the dynamic array unless NULL array exception is thrown
int sum (int* theArray, unsigned int arraySize){
	if (theArray == NULL){
		throw ArrayException("NULL ARRAY REFERENCE");
	} else {
		int arraySum = 0;
		for (int i = 0; i < arraySize; i++){
			arraySum+= theArray[i];
		}
	return arraySum;
	}
}

//return the highest value int from the array unless NULL array exception is thrown
int max (int* theArray, unsigned int arraySize){
	if (theArray == NULL){
		throw ArrayException("NULL ARRAY REFERENCE");
	} else {
		int arrayMax = theArray[0];
		for (int i = 1; i < arraySize; i++){
			if (theArray[i] > arrayMax){
				arrayMax = theArray[i];
			}
		}
		return arrayMax;
	}
}

//return the lowest value int from the array unless NULL array exception is thrown
int min (int* theArray, unsigned int arraySize){
	if (theArray == NULL){
		throw ArrayException("NULL ARRAY REFERENCE");
	} else {
		int arrayMin = theArray[0];
		for (int i = 1; i < arraySize; i++){
			if (theArray[i] < arrayMin){
				arrayMin = theArray[i];
			}
		}
		return arrayMin;
	}
}

/*
 * Unit testing functions. Do not alter.
 */

void unittest () {

	unsigned short utCount = 10;
	unsigned short utPassed = 0;

	cout << "\nSTARTING UNIT TEST\n\n";
	
	int* myArray = 0; // = makeDynoIntArray(10);
	unsigned int myArraySize = 0;
	
	try {
		sum(myArray, myArraySize);
		btassert<bool>(false);
	} catch (ArrayException e) {
		try {
			btassert<bool>(e.message == "NULL ARRAY REFERENCE");
			cout << "Passed TEST 1: sum EXCEPTION HANDLING (INT*) () \n";
			++utPassed;
		} catch (bool b) {
			cout << "# FAILED TEST 1: sum EXCEPTION HANDLING (INT*) () #\n";
		}
	} catch (bool) {
		cout << "# FAILED TEST 1: sum MISSING EXCEPTION #\n";
	}
	
	try {
		min(myArray, myArraySize);
		btassert<bool>(false);
	} catch (ArrayException e) {
		try {
			btassert<bool>(e.message == "NULL ARRAY REFERENCE");
			cout << "Passed TEST 2: min EXCEPTION HANDLING (INT*) () \n";
			++utPassed;
		} catch (bool b) {
			cout << "# FAILED TEST 2: min EXCEPTION HANDLING (INT*) () #\n";
		}
	} catch (bool) {
		cout << "# FAILED TEST 2: min MISSING EXCEPTION #\n";
	}
	
	try {
		max(myArray, myArraySize);
		btassert<bool>(false);
	} catch (ArrayException e) {
		try {
			btassert<bool>(e.message == "NULL ARRAY REFERENCE");
			cout << "Passed TEST 3: max EXCEPTION HANDLING (INT*) () \n";
			++utPassed;
		} catch (bool b) {
			cout << "# FAILED TEST 3: max EXCEPTION HANDLING (INT*) () #\n";
		}
	} catch (bool) {
		cout << "# FAILED TEST 3: max MISSING EXCEPTION #\n";
	}
	
	myArray = makeDynoIntArray(3);
	
	try {
		btassert<bool>(myArray != 0);
		cout << "Passed TEST 4: INT ARRAY INITIALIZATION () \n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 4: INT ARRAY INITIALIZATION () #\n";
	}
	
	myArray[0] = 30, myArray[1] = 20, myArray[2] = 10;
	
	try {
		btassert<bool>(sum(myArray, 3) == 60);
		cout << "Passed TEST 5: sum (array) \n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 5: sum (array) #\n";
	}
	
	try {
		btassert<bool>(min(myArray, 3) == 10);
		cout << "Passed TEST 6: min (array) \n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 6: min (array) #\n";
	}
	
	myArray[0] = 30, myArray[1] = 10, myArray[2] = 20;
	
	try {
		btassert<bool>(min(myArray, 3) == 10);
		cout << "Passed TEST 7: min (array) \n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 7: min (array) #\n";
	}
	
	myArray[0] = 30, myArray[1] = 20, myArray[2] = 10;
	
	try {
		btassert<bool>(max(myArray, 3) == 30);
		cout << "Passed TEST 8: max (array) \n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 8: max (array) #\n";
	}
	
	myArray[0] = 20, myArray[1] = 10, myArray[2] = 30;
	
	try {
		btassert<bool>(max(myArray, 3) == 30);
		cout << "Passed TEST 9: max (array) \n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 9: max (array) #\n";
	}
	
	clearDynoIntArray(myArray);
	
	try {
		btassert<bool>(myArray == 0);
		cout << "Passed TEST 10: clearDynoArray () \n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 10: clearDynoArray () #\n";
	}
		
	cout << "\nUNIT TEST COMPLETE\n\n";

	cout << "PASSED " << utPassed << " OF " << utCount << " UNIT TEST";
	if (utCount > 1) {
		cout << "S";
	}
	cout << "\n\n";
}

template <typename X, typename A>
void btassert (A assertion) {
    if (!assertion)
		throw X();
}