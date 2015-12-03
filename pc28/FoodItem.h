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
      
      /*
       * FoodItem default Constructor
       * @param newName the string passed into the Item constructor parameter newName (default argument is "fooditem")
       * @param newValue the unsigned int passed into the Item constructor parameter newValue (default argument is 0)
       * @param newCalories assigns this value to the member calories (default argument is 0)
       * @param newUnitOfMeasure assigns this value to the member unitOfMeasure (default argument is "nounits")
       * @param newUnits assigns this value to the member units (default argument is 0)
       */
      FoodItem(string newName = "fooditem", unsigned int newValue = 0, unsigned int newCalories = 0, string newUnitOfMeasure = "nounits", float newUnits = 0);
      
      /*
       * FoodItem Destructor does nothing
       */
      virtual ~FoodItem();
      
      /*
       * Calories setter
       * @param newCalories assigns this value to the member calories
       */
      void setCalories(unsigned int newCalories);
      
      /*
       * UnitOfMeasure setter
       * @param newUnitOfMeasure assigns this value to the member unitOfMeasure
       */
      void setUnitOfMeasure(string newUnitOfMeasure);
      
      /*
       * Units setter
       * @param newUnits assigns this value to the member units
       */
      void setUnits(float newUnits);
      
      /*
       * Calories getter
       * @return an unsigned int containing the value of the member calories
       */
      unsigned int getCalories();
      
      /*
       * UnitOfMeasure getter
       * @return a string containing the value of the member unitOfMeasure
       */
      string getUnitOfMeasure();
      
      /*
       * Units getter
       * @return a float containing the value of the member units
       */
      float getUnits();
      
      /*
       * ToString returns a string containing the members of the FoodItem
       * @return a string containing the result of the Item::toString function, followed by the FoodItem members units, unitsOfMeasure, and calories
       */
      string toString();
      
    private:
    
    /*
     * @member calories an unsigned int containing a value representing the calories of the FoodItem
     */
    unsigned int calories;
    
    /*
     * @member unitOfMeasure a string containing the unit of measure for the FoodItem
     */
    string unitOfMeasure;
    
    /*
     * @member units a float containing the number of units of the FoodItem
     */
    float units;
      
  };