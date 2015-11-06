/*
 * Programming Project 3 DLNode Header
 *
 * Steve Ross-Byers
 * Date created: 11/4/2015
 * Last date modified: 11/4/2015
 */

#pragma once

#include <cstdlib>
 
using namespace std;

class DLNode {
    
    private:
    
        /*
         * @member nextNode points to the next node in a doubly-linked list
         */
        DLNode* next;
        
        /*
         * @member prevNode points to the previous node in a doubly-linked list
         */
        DLNode* previous;
        
        /*
         * @member contents stores the data contents of this DLNode
         */
        int contents;
        
    public:
    
        /*
         * DLNode default Constructor
         */
        DLNode();
        
        /*
         * Overloaded DLNode Constructor
         * @param customContents assigns this value to member contents
         */
        DLNode(int newContents);
        
        /*
         * DLNode Destructor frees memory assigned to nextNode pointer
         */
        virtual ~DLNode();
        
        /*
         * Contents setter
         * @param newContents assigns this value to member contents
         */
        void setContents(int newContents);
        
        /*
         * Contents getter
         * @return an int containing the data from this DLNode
         */
        int getContents() const;
        
        /*
         * nextNode setter
         * @param nextDLNode points nextNode at an DLNode
         */
        void setNext(DLNode* newNext);
        
        /*
         * nextNode getter
         * @return an DLNode* pointing at the next node
         */
         DLNode* getNext ()const;
         
         /*
         * prevNode setter
         * @param prevDLNode points prevNode at a DLNode
         */
        void setPrevious(DLNode* newPrevious);
        
        /*
         * prevNode getter
         * @return an DLNode* pointing at the previous node
         */
         DLNode* getPrevious () const;
};