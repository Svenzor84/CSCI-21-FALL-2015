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
 
 bool operator==(const Prize& lp, const Prize& rp){
     if (lp.prizeValue == rp.prizeValue){
         if (lp.prizeName == rp.prizeName){
             return true;
         } else {
             return false;
         }
     } else {
         return false;
     }
 }