/*
 * Programming Challenge 18 SList Header
 *
 * Steve Ross-Byers
 * Date created: 10/24/2015
 * Last date modified: 10/24/2015
 */

#pragma once

#include <string>
#include <sstream>
#include "SLNode.h"

class SList {
    private:
    
        /*
         * @member head points to the first node in a singly-linked list
         */
        SLNode* head;
        
        /*
         * @member size is a count of the number of nodes in the list
         */
        unsigned int size;
        
    public:
    
        /*
         * SList default Constructor
         */
        SList();
        
        /*
         * SList Destructor calls the clear function to clear the list and free all memory
         */
        ~SList();
        
        /*
         * Function to create an SLNode and attatch it to the beginning of the list
         * @param nodeContents assigns this value to the node that is created
         */
        void insertHead(int headContents);
        
        /*
         * Function to remove the first (head) node of the list
         */
        void removeHead();
        
        /*
         * Function that clears the list of all nodes and frees up all associated memory
         */
        void clear();
        
        /*
         * Size getter
         * @return an unsigned int containing the value of the length of the list
         */
        unsigned int getSize() const;
        
        /*
         * Function that concatenates the contents of the entire list into a string
         * @return a string containing the contents of the list separated by , and ending with ;
         */
        string toString() const;
};