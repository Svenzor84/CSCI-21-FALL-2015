/*
 * Project 2 Prize Implementation
 *
 * Steve Ross-Byers
 * Date created: 10/11/2015
 * Last date modified: 10/11/2015
 */
 
 #include "prize.h"
 
 Prize::Prize() : prizeName("NO NAME"), prizeValue(0) {
     
 }
 
 Prize::Prize(string newPrizeName, unsigned int newPrizeValue) 
        : prizeName(newPrizeName), prizeValue(newPrizeValue){
     
 }
 
 Prize::~Prize(){
     
 }
 
 unsigned int Prize::getPrizeValue(){
     return prizeValue;
 }
 
 void Prize::setPrizeValue(unsigned int newPrizeValue){
     prizeValue = newPrizeValue;
 }
 
 string Prize::getPrizeName(){
     return prizeName;
 }
 
 void Prize::setPrizeName(string newPrizeName){
     prizeName = newPrizeName;
 }
 
 bool operator==(Prize p1, Prize p2){
     if (p1.prizeValue == p2.prizeValue){
         if (p1.prizeName == p2.prizeName){
             return true;
         } else {
             return false;
         }
     } else {
         return false;
     }
 }