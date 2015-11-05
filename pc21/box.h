/*
 * Programming Challenge 21 Box Header
 *
 * Steve Ross-Byers
 * Date created: 11/03/2015
 * Last date modified: 11/05/2015
 */

#pragma once

#include<iostream>
using namespace std;

template <class T>

class Box {
    
    public:
 
        /*
         * Box overloaded Constructor
         * @param newContents assigns this value to the private member contents
         */
        Box (T newContents)
        : contents(newContents) 
        {}
        
        /*
         * Contents getter
         * @return a variable type T containing the content value of this box
         */
        T getContents() {
            return contents;
        }
        
        /*
         * Contents setter
         * @param newContents assigns this value to the private member contents
         */
        void setContents (T newContents) {
            contents = newContents;
        }
        
         /*
         * Overloaded << (insertion) operator
         * @param out a reference to the output stream
         * @param box a reference to the box to be streamed
         * @return a rerence to the output stream
         */
        friend ostream& operator<< (ostream& out, const Box& box) {
            out << box.contents;
            return out;
        }
    
    private:
    
        /*
         * @member contents the value stored in the box
         */
        T contents;
};