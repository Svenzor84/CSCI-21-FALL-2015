/*
 * Programming Challenge 28 FoodItem Implementation
 *
 * Steve Ross-Byers
 * Date created: 12/1/2015
 * Last date modified: 12/1/2015
 */
 
 #include "FoodItem.h"
 
 FoodItem::FoodItem(string newName, unsigned int newValue, unsigned int newCalories, string newUnitOfMeasure, float newUnits) 
 : Item(newName, newValue), calories(newCalories), unitOfMeasure(newUnitOfMeasure), units(newUnits)
 {}
    
 FoodItem::~FoodItem() {
        
 }
    
 void FoodItem::setCalories(unsigned int newCalories) {
     calories = newCalories;
 }
 
 void FoodItem::setUnitOfMeasure(string newUnitOfMeasure) {
     unitOfMeasure = newUnitOfMeasure;
 }
 
 void FoodItem::setUnits(float newUnits) {
     units = newUnits;
 }
 
 unsigned int FoodItem::getCalories() {
     return calories;
 }
 
 string FoodItem::getUnitOfMeasure() {
     return unitOfMeasure;
 }
 
 float FoodItem::getUnits() {
     return units;
 }
 
 string FoodItem::toString() {
     stringstream ss;
     
     ss.setf(std::ios::showpoint|std::ios::fixed);
     ss.precision(2);
     
     ss << Item::toString() << ", " << units << ' ' << unitOfMeasure << ", " << calories << " calories";
     return ss.str();
 }