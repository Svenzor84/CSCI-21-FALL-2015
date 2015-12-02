/*
 * Programming Challenge 28 FoodItem Header
 *
 * Steve Ross-Byers
 * Date created: 12/1/2015
 * Last date modified: 12/1/2015
 */
  #pragma once
  
  #include "Item.h"
  
  class FoodItem: public Item {
      
    public:
      
      FoodItem(string newName = "fooditem", unsigned int newValue = 0, unsigned int newCalories = 0, string newUnitOfMeasure = "nounits", float newUnits = 0);
      virtual ~FoodItem();
      void setCalories(unsigned int newCalories);
      void setUnitOfMeasure(string newUnitOfMeasure);
      void setUnits(float newUnits);
      unsigned int getCalories();
      string getUnitOfMeasure();
      float getUnits();
      string toString();
      
    private:
    
    unsigned int calories;
    string unitOfMeasure;
    float units;
      
  };