/*
 * Programming Challenge 22 SLNode Header Only Template Class
 *
 * Steve Ross-Byers
 * Date created: 11/8/2015
 * Last date modified: 11/8/2015
 */

#pragma once

#include <cstdlib>
 
using namespace std;

template <class T>

class SLNode {
    
    private:
    
        /*
         * @member nextNode points to the next node in a singly-linked list
         */
        SLNode* nextNode;
        
        /*
         * @member contents stores the data contents of this SLNode
         */
        T contents;
        
    public:
    
        /*
         * SLNode default Constructor
         */
        SLNode()
        : nextNode(NULL)
        {}
        
        /*
         * Overloaded SLNode Constructor
         * @param customContents assigns this value to member contents
         */
        SLNode(T customContents)
        : nextNode(NULL), contents(customContents)
        {}
        
        /*
         * SLNode Destructor frees memory assigned to nextNode pointer
         */
        ~SLNode()
        {nextNode = NULL;}
        
        /*
         * Contents setter
         * @param newContents assigns this value to member contents
         */
        void setContents(T newContents)
        {contents = newContents;}
        
        /*
         * Contents getter
         * @return a T containing the data from this SLNode
         */
        T getContents() const
        {return contents;}
        
        /*
         * nextNode setter
         * @param nextSLNode points nextNode at an SLNode
         */
        void setNextNode(SLNode* nextSLNode)
        {nextNode = nextSLNode;}
        
        /*
         * nextNode getter
         * @return an SLNode* pointing at the next node
         */
         SLNode* getNextNode ()const
         {return nextNode;}
};