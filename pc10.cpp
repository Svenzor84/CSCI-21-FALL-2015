/*
 * Programming Challenge 10
 * Created by Steve Ross-Byers on Sept 22 2015
 */
#include <cassert>
#include <iomanip>
#include <iostream>
using namespace std;

/*
 * Class Converter.
 * A class that performs a variety of conversions.
 */
class Converter {
	public:
		
		/*
		 * Convert a temperature from metric to imperial units or from
		 * imperial to metric units.
		 * @param temp the temperature to be converted -- in degrees Fahrenheit
		 *        or degrees Celsius
		 * @param targetUnits a char representing the system to convert the
		 *        temperature to -- 'M' to convert to metric, 'I' to convert
		 *        to imperial
		 * @return a float containing the converted temperature
		 */
		float convertTemperature (float temp, char targetUnits);
		
		/*
		 * Convert a distance from metric to imperial units or from
		 * imperial to metric units.
		 * @param distance the distance to be converted -- in feet or meters
		 * @param targetUnits a char representing the system to convert the
		 *        temperature to -- 'M' to convert to metric, 'I' to convert
		 *        to imperial
		 * @return a float containing the converted distance
		 */
		float convertDistance (float distance, char targetUnits);
		
	private:
	
		/* Called by convertTemperature if target units is 'M' */
		float fahrenheitToCelsius (float temp);
		
		/* Called by convertTemperature if target units is 'I' */
		float celsiusToFahrenheit (float temp);
		
		/* Called by convertDistance if target units is 'M' */
		float feetToMeters (float distance);
		
		/* Called by convertDistance if target units is 'I' */
		float metersToFeet (float distance);
};

/* for unit testing -- do not alter */
template <typename X, typename A>
void btassert(A assertion);
void unittest ();

int main (int argc, char* argv[]) {
	unittest();
	
	return 0;
}

// CODE HERE -- FUNCTION DEFINITIONS

//Decides which function to call (to convert temperature) depending on arguments
float Converter::convertTemperature (float temp, char targetUnits){
	if (targetUnits == 'M'){
		return fahrenheitToCelsius(temp);
	}
	if (targetUnits == 'I'){
		return celsiusToFahrenheit(temp);
	}
}

//Decides which function to call (to convert distance) depending on arguments
float Converter::convertDistance (float distance, char targetUnits){
	if (targetUnits == 'M'){
		return feetToMeters(distance);
	}
	if (targetUnits == 'I'){
		return metersToFeet(distance);
	}
}

//Converts temperature from fahrenheit to celsius when target unit is 'M'
float Converter::fahrenheitToCelsius (float temp){
	return ((temp -32) * (0.56));
}

//Converts temperature from celsius to fahrenheit when target unit is 'I'
float Converter::celsiusToFahrenheit (float temp){
	return (temp * (1.80) + 32);
}

//Converts distance from feet to meters when target unit is 'M'
float Converter::feetToMeters (float distance){
	return (distance/3.2808);
}

//Converts distance from meters to feet when target unit is 'I'
float Converter::metersToFeet (float distance){
	return (distance * 3.2808);
}

/*
 * Unit testing functions. Do not alter.
 */

void unittest () {
	unsigned short utCount = 10;
	unsigned short utPassed = 0;

	cout << "\nSTARTING UNIT TEST\n\n";
	
	Converter c;
	
	try {
		btassert<bool>(static_cast<int>(c.convertTemperature(32, 'M')) == 0);
		cout << "Passed TEST 1: convertTemperature(32, 'M')\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 1 convertTemperature(32, 'M') #\n";
	}
	
	try {
		btassert<bool>(static_cast<int>(c.convertTemperature(212, 'M')) == 100);
		cout << "Passed TEST 2: convertTemperature(212, 'M')\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 2 convertTemperature(212, 'M') #\n";
	}
	
	try {
		btassert<bool>(static_cast<int>(c.convertTemperature(98.6, 'M')) == 37);
		cout << "Passed TEST 3: convertTemperature(98.6, 'M')\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 3 convertTemperature(98.6, 'M') #\n";
	}
	
	try {
		btassert<bool>(static_cast<int>(c.convertTemperature(0, 'I')) == 32);
		cout << "Passed TEST 4: convertTemperature(0, 'I')\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 4 convertTemperature(0, 'I') #\n";
	}
	
	try {
		btassert<bool>(static_cast<int>(c.convertTemperature(100, 'I')) == 212);
		cout << "Passed TEST 5: convertTemperature(100, 'I')\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 5 convertTemperature(100, 'I') #\n";
	}
	
	try {
		btassert<bool>(c.convertDistance(300, 'M') > 91.43f && c.convertDistance(300, 'M') < 91.45f);
		cout << "Passed TEST 6: convertDistance(300, 'M')\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 6 convertDistance(300, 'M') #\n";
	}
	
	try {
		btassert<bool>(c.convertDistance(5280, 'M') > 1609.3f && c.convertDistance(5280, 'M') < 1609.4f);
		cout << "Passed TEST 7: convertDistance(5280, 'M')\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 7 convertDistance(5280, 'M') #\n";
	}
	
	try {
		btassert<bool>(c.convertDistance(1, 'M') > .30f && c.convertDistance(1, 'M') < .31f);
		cout << "Passed TEST 8: convertDistance(1, 'M')\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 8 convertDistance(1, 'M') #\n";
	}
	
	try {
		btassert<bool>(c.convertDistance(1, 'I') > 3.28f && c.convertDistance(1, 'I') < 3.29f);
		cout << "Passed TEST 9: convertDistance(1, 'I')\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 9 convertDistance(1, 'I') #\n";
	}
	
	try {
		btassert<bool>(c.convertDistance(.5f, 'I') > 1.6f && c.convertDistance(.5f, 'I') < 1.7f);
		cout << "Passed TEST 10: convertDistance(.5f, 'I')\n";
		++utPassed;
	} catch (bool b) {
		cout << "# FAILED TEST 10 convertDistance(.5f, 'I') #\n";
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
