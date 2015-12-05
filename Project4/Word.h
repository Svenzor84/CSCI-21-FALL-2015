/*
 * Programming Project 4 Word Header
 *
 * Steve Ross-Byers
 * Date created: 12/3/2015
 * Last date modified: 12/4/2015
 */
 
 #pragma once
 
 #include <iostream>
 #include <string>
 #include <algorithm>
 
 using namespace std;
 
 class Word {
    
    public:
    
        /*
         * Word default Constructor
         */
        Word();
        
        /*
         * Word Overloaded Constructor
         * @param newWord assigns this value to the member word
         */
        Word(string newWord);
        
        /*
         * Virtual Destructor does nothing
         */
        virtual ~Word();
        
        /*
         * Word getter
         * @return a string containing the value of the member string
         */
        string getWord() const;
        
        /*
         * Word setter
         * @param newWord assigns this value to the member word
         */
        void setWord(string newWord);
        
        /*
         * Count getter
         * @return an unsigned int containing the value of the member count
         */
        unsigned int getCount();
        
        /*
         * IncrementCount adds 1 to the value of the member count each time the word is added to the tree
         */
        void incrementCount();
        
        /*
         * Overloaded == operator compares two word objects and determines if they are equivalent
         * @param lw the word on the left side of the operator
         * @param rw the word on the right side of the operator
         * @return true if the two words are equivalent (case insensitive)
         */
        friend bool operator==(const Word& lw, const Word& rw);
        
        /*
         * Overloaded < operator compares two word objects and determines which word comes first in alphabetical order
         * @param lw the word on the left side of the operator
         * @param rw the word on the right side of the operator
         * @return true if the left word comes first in alphabetical order (case insensitive), or false otherwise
         */
        friend bool operator<(const Word& lw, const Word& rw);
        
        /*
         * Overloaded > operator compares two word objects and determines which word comes first in alphabetical order
         * @param lw the word on the left side of the operator
         * @param rw the word on the right side of the operator
         * @return true if the right word comes first in alphabetical order (case insensitive), or false otherwise
         */
        friend bool operator>(const Word& lw, const Word& rw);
        
        /*
         * Overloaded << operator adds the private members of the word object to an output stream
         * @param os a reference to the output stream being used
         * @param word the word object being added to the output stream
         * @return true if the left word comes first in alphabetical order (case insensitive), or false otherwise
         */
        friend ostream& operator<<(ostream& os, const Word& word);
    
    private:
        
        /*
         * @member word contains the string that identifies the word object
         */
        string word;
        
        /*
         * @member count keeps track of how many times the word has been inserted into a binary search tree
         */
        unsigned int count;
        
        /*
         * UpperCase is a helper function used in <, >, and == operators to remove case-sensitivity from word comparison
         * @param s a const reference to the word being compared
         * @return a string containing the string argument transformed to all caps
         */
        static string upperCase(const string& s);
 };