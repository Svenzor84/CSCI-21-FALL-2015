/*
 * Project 2 Box Implementation
 *
 * Steve Ross-Byers
 * Date created: 10/11/2015
 * Last date modified: 10/11/2015
 */
 
 #include "box.h"
 
 Box::Box() : boxNumber(0), prizeCapacity(5), prizeCount(0), boxColor("NO COLOR") {
     prizes = new Prize[prizeCapacity];
 }
 
 Box::Box(unsigned int newBoxNumber, string newBoxColor, unsigned int newPrizeCapacity) 
        : boxNumber(newBoxNumber), prizeCapacity(newPrizeCapacity), prizeCount(0), boxColor(newBoxColor) {
     prizes = new Prize[prizeCapacity];
 }
 
 Box::~Box(){
     if (prizes != NULL){
        delete [] prizes;
        prizes = NULL;
     }
 }
 
 unsigned int Box::getBoxNumber(){
     return boxNumber;
 }
 
 void Box::setBoxNumber(unsigned int newBoxNumber){
     boxNumber = newBoxNumber;
 }
 
 string Box::getBoxColor(){
     return boxColor;
 }
 
 void Box::setBoxColor(string newBoxColor){
     boxColor = newBoxColor;
 }
 
 unsigned int Box::getPrizeCapacity(){
     return prizeCapacity;
 }
 
 unsigned int Box::getPrizeCount(){
     return prizeCount;
 }
 
 bool Box::addPrize(Prize prize){
     if (prizeCount < prizeCapacity){
         prizes[prizeCount] = prize;
         prizeCount++;
         return true;
     } else {
         return false;
     }
 }
 
 Prize& Box::getPrize(unsigned int index){
     if (index < prizeCount) {
         
         return prizes[index];
     } else {
         return scratch;
     }
 }
 
 Prize Box::removePrize(unsigned int index){
     if (index < prizeCount) {
        //save the value of the item to be deleted, delete the item, and
        //decrement item count
        Prize toBeDeleted = prizes[index];
        prizeCount--;
        
        //pack the array so all items are contiguous
        while (index < prizeCount){
            prizes[index] = prizes[(index + 1)];
            index++;
        }
        
        //return the item that was deleted
        return toBeDeleted;
     } else {
         return scratch;
     }
 }