/*
 * Programming Challenge 28 Item Implementation
 *
 * Steve Ross-Byers
 * Date created: 12/1/2015
 * Last date modified: 12/1/2015
 */
 
 #include "Item.h"
 
 Item::Item(string newName, unsigned int newValue)
 : name(newName), value(newValue)
 {}
 
 Item::~Item() {}
 
 void  Item::setName(string newName) {
     name = newName;
 }
 
 void  Item::setValue(unsigned int newValue) {
     value = newValue;
 }
 
 string  Item::getName() {
     return name;
 }
 
 unsigned int  Item::getValue() {
     return value;
 }
 
 string  Item::toString() {
     stringstream ss;
     ss << getName() << ", $" << getValue();
     return ss.str();
 }