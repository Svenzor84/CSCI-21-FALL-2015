/*
 * Programming Project 3 DLList Header
 *
 * Steve Ross-Byers
 * Date created: 11/4/2015
 * Last date modified: 11/6/2015
 */

#pragma once

#include <string>
#include "DLNode.h"

class DLList {
    private:
    
        /*
         * @member head points to the first node in a doubly-linked list
         */
        DLNode* head;
        
        /*
         * @member tail points to the last node in a doubly-linked list
         */
        DLNode* tail;
        
        /*
         * @member count is a count of the number of nodes in the list
         */
        unsigned int count;
        
    public:
    
        /*
         * DLList default Constructor
         */
        DLList();
        
        /*
         * DLList Destructor calls the clear function to clear the list and free all memory
         */
        ~DLList();
        
        /*
         * Function to create an DLNode and attatch it to the beginning of the list
         * @param newContents assigns this value to the node that is created
         */
        void pushFront(int newContents);
        
        /*
         * Function to create an DLNode and attatch it to the end of the list
         * @param newContents assigns this value to the node that is created
         */
        void pushBack(int newContents);
        
        /*
         * Function to remove the first (head) node of the list
         */
        void popFront();
        
        /*
         * Function to remove the last (tail) node of the list
         */
        void popBack();
        
        /*
         * Function that inserts a node with contents in ascending order
         * @param contents assigns this value to the contents of the inserted node
         */
        void insert(int newContents);
        
        /*
         * Function that removes a node with specific contents from the list
         * @param contents the first node in the list with this value as contents is removed
         */
        bool removeFirst(int target);
        
        /*
         * Function that removes all nodes with specific contents from the list
         * @param contents every node in the list with this value as contents is removed
         */
        bool removeAll (int target);
        
        /*
         * Function that clears the list of all nodes and frees up all associated memory
         */
        void clear();
        
        /*
         * count getter
         * @return an unsigned int containing the value of the length of the list
         */
        unsigned int getSize() const;
        
        /*
         * Head getter
         * @return an int containing the value stored in the head node
         */
        int getFront() const;
        
        /*
         * Tail getter
         * @return an int containing the value stored in the tail node
         */
        int getBack() const;
        
        /*
         * Function that concatenates the contents of the entire list into a string
         * @return a string containing the contents of the list separated by , and ending with ;
         */
        string toString() const;
        
        /*
         * target contents getter
         * @return true if the target contents are present, false if not
         */
        bool get(int target) const;
        
        /*
         * Overloaded << operator streams the contents of the list to the output stream
         * @param out a reference to the output stream
         * @param src a reference to the list to be streamed
         * @return a reference to the output stream
         */
        friend ostream& operator<< (ostream& out, const DLList& src);
};