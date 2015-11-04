/*
 * Programming Challenge 20 SList Header
 *
 * Steve Ross-Byers
 * Date created: 11/01/2015
 * Last date modified: 11/01/2015
 */

#pragma once

#include <string>
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
        void insertHead(int nodeContents);
        
        /*
         * Function to create an SLNode and attatch it to the end of the list
         * @param nodeContents assigns this value to the node that is created
         */
        void insertTail(int nodeContents);
        
        /*
         * Function to remove the first (head) node of the list
         */
        void removeHead();
        
        /*
         * Function to remove the last (tail) node of the list
         */
        void removeTail();
        
        /*
         * Function that inserts a node with contents in ascending order
         * @param contents assigns this value to the contents of the inserted node
         */
        void insert(int contents);
        
        /*
         * Function that removes a node with specific contents from the list
         * @param contents the first node in the list with this value as contents is removed
         */
        bool removeFirst(int contents);
        
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