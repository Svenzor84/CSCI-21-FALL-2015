/*
 * Programming Project 4 Word Implementation
 *
 * Steve Ross-Byers
 * Date created: 12/3/2015
 * Last date modified: 12/4/2015
 */
 
 #include "Word.h"
 
 //private function
 
 string Word::upperCase (const string& s) {
    string us = s;
    transform(us.begin(), us.end(), us.begin(), ::toupper);
    return us;
 }
 
 //public functions
 
 Word::Word()
 : count(1)
 {}
        
 Word::Word(string newWord) 
 : word(newWord), count(1)
 {}
        
 Word::~Word()
 {}
        
 string Word::getWord() const {
     return word;
 }
        
 void Word::setWord(string newWord) {
     word = newWord;
 }
        
 unsigned int Word::getCount() {
     return count;
 }
        
 void Word::incrementCount() {
     count++;
 }
        
 bool operator==(const Word& lw, const Word& rw) {
     if(Word::upperCase(lw.word) == Word::upperCase(rw.word)) {
         return true;
     } else {
         return false;
     }
 }
        
 bool operator<(const Word& lw, const Word& rw) {
    if(Word::upperCase(lw.word) < Word::upperCase(rw.word)) {
        return true;
    } else {
        return false;
    }
 }
        
 bool operator>(const Word& lw, const Word& rw) {
    if (Word::upperCase(lw.word) > Word::upperCase(rw.word)) {
        return true;
    } else {
        return false;
    }
 }
        
 ostream& operator<<(ostream& os, const Word& word) {
    os << word.word << ' ' << word.count;
    return os;
 }