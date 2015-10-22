/*
 * Programming Challenge 17 SLNode Header
 *
 * Steve Ross-Byers
 * Date created: 10/20/2015
 * Last date modified: 10/20/2015
 */

#pragma once

#include <cstdlib>
 
using namespace std;

class SLNode {
    
    private:
    
        /*
         * @member nextNode points to the next node in a singly-linked list
         */
        SLNode* nextNode;
        
        /*
         * @member contents stores the data contents of this SLNode
         */
        int contents;
        
    public:
    
        /*
         * SLNode default Constructor
         */
        SLNode();
        
        /*
         * Overloaded SLNode Constructor
         * @param customContents assigns this value to member contents
         */
        SLNode(int customContents);
        
        /*
         * SLNode Destructor frees memory assigned to nextNode pointer
         */
        ~SLNode();
        
        /*
         * Contents setter
         * @param newContents assigns this value to member contents
         */
        void setContents(int newContents);
        
        /*
         * Contents getter
         * @return an int containing the data from this SLNode
         */
        int getContents() const;
        
        /*
         * nextNode setter
         * @param nextSLNode points nextNode at an SLNode
         */
        void setNextNode(SLNode* nextSLNode);
        
        /*
         * nextNode getter
         * @return an SLNode* pointing at the next node
         */
         SLNode* getNextNode ()const;
};