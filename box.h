/*
 * Project 2 Box Header
 *
 * Steve Ross-Byers
 * Date created: 10/11/2015
 * Last date modified: 10/11/2015
 */
 
#pragma once
 
#include <cstdlib>
#include <iostream>
#include <string>

#include "prize.h"

using namespace std;

class Box {
    public:
        /*
         * Box default Constructor
         */
        Box();
        /*
         * Overloaded Box Constructor
         * @param newBoxNumber assigns this value to member boxNumber
         * @param newPrizeCapacity assigns this value to member prizeCapacity
         * @param newBoxColor assigns this value to member boxColor
         */
        Box(unsigned int newBoxNumber, string newBoxColor, unsigned int newPrizeCapacity);
        /*
         * Box Destructor frees memory assigned to prize array
         */
        ~Box();
        
        /*
         * Get the value of member boxNumber
         * @return an unsigned int containing the member boxNumber
         */
        unsigned int getBoxNumber();
        
        /*
         * Set the value of member boxNumber
         * @param newBoxNumber assigns this value to member boxNumber
         */
        void setBoxNumber(unsigned int newBoxNumber);
        
        /*
         * Get the value of member boxColor
         * @return a string containing the value of member boxColor
         */
        string getBoxColor();
        
        /*
         * Set the value of member boxColor
         * @param newBoxColor assigns this value to member boxColor
         */
        void setBoxColor(string newBoxColor);
        
        /*
         * Get the value of member prizeCapacity
         * @return an unsigned int containing the value of member prizeCapacity
         */
        unsigned int getPrizeCapacity();
        
        /*
         * Get the value of member prizeCapacity
         * @return an unsigned int containing the value of member prizeCount
         */
        unsigned int getPrizeCount();
        
        /*
         * Add a prize to the array prizes if there is space
         * @param Prize add this prize to the prizes array if there is space
         * @return true if prize add is successful, otherwise return false
         */
        bool addPrize(Prize prize);
        
        /*
         * Get the prize at prizes[index] if index is valid
         * @param index use this value to index the requested prize
         * @return a reference to the requested prize if successful, else return a reference to the member scratch
         */
        Prize& getPrize(unsigned int index);
        
        /*
         * Remove the prize at prizes[index] if index is valid
         * @param index use this value to index the requested prize
         * @return a reference to the removed prize if successful, else return a reference to the member scratch
         */
        Prize removePrize(unsigned int index);
    
    private:
        unsigned int boxNumber, prizeCapacity, prizeCount;
        string boxColor;
        Prize scratch;
        Prize* prizes;
    
};