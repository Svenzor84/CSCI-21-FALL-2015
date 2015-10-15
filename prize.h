/*
 * Project 2 Prize Header
 *
 * Steve Ross-Byers
 * Date created: 10/11/2015
 * Last date modified: 10/11/2015
 */
  
#pragma once 
 
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class Prize {
    
    public:
        /*
         * Prize default Constructor
         */
         Prize();
         
        /*
         * Overloaded Prize Constructor
         * @param newPrizeName assign this value to the member prizeName
         * @param newPrizeValue assign this value to the member prizeValue
         */
         Prize(string newPrizeName, unsigned int newPrizeValue);
         
        /*
         * Box Desctructor doesn't actually do anything
         */
         ~Prize();
         
        /*
         * Get the value of member prizeValue
         * @return an unsigned int containing the member prizeValue
         */
         unsigned int getPrizeValue();
         
        /*
         * Set the value of member prizeValue
         * @return an unsigned int containing the member prizeValue
         */
         void setPrizeValue(unsigned int newPrizeValue);
         
        /*
         * Get the value of member prizeName
         * @return an unsigned int containing the member prizeName
         */
         string getPrizeName();
         
        /*
         * Set the value of member prizeName
         * @param newPrizeName assigns this value to member prizeName
         */
         void setPrizeName(string newPrizeName);
         
         /*
         * Overloaded == operator compares the prizeName and prizeValue of two Prize objects
         * @param p1 the first Prize object to be compared
         * @param p2 the second Prize objec to be compared
         * @return true if the compared Prize objects have equivalent prizeName and prizeValues
         *  otherwise return false
         */
         friend bool operator==(Prize p1, Prize p2);
         
    private:
        string prizeName;
        unsigned int prizeValue;
        
};
