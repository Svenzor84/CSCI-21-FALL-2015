/*
 * Programming Challenge 28 MagicItem Header
 *
 * Steve Ross-Byers
 * Date created: 12/1/2015
 * Last date modified: 12/1/2015
 */
  #pragma once
  
  #include "Item.h"
  
  class MagicItem: public Item {
      
    public:
    
      /*
       * MagicItem default Constructor
       * @param newName the string passed into the Item constructor parameter newName (default argument is "magicitem")
       * @param newValue the unsigned int passed into the Item constructor parameter newValue (default argument is 0)
       * @param newDescription assigns this value to the member desciption (default argument is "no description")
       * @param newManaRequired assigns this value to the member manaRequired (default argument is 0)
       * @param newUnits assigns this value to the member units (default argument is 0)
       */
      MagicItem(string newName = "magicitem", unsigned int newValue = 0, string newDescription = "no description", unsigned int newManaRequired = 0);
      
      /*
       * MagicItem Destructor does nothing
       */
      virtual ~MagicItem();
      
      /*
       * Description setter
       * @param newDescription assigns this value to the member description
       */
      void setDescription(string newDescription);
      
      /*
       * ManaRequired setter
       * @param newManaRequired assigns this value to the member manaRequired
       */
      void setManaRequired(unsigned int newManaRequired);
      
      /*
       * Description getter
       * @return a string containing the value of the member description
       */
      string getDescription();
      
      /*
       * ManaRequired getter
       * @return an unsigned int containing the value of the member manaRequired
       */
      unsigned int getManaRequired();
      
      /*
       * ToString returns a string containing the members of the MagicItem
       * @return a string containing the result of the Item::toString function, followed by the MagicItem members description and manaRequired
       */
      string toString();
      
    private:
      
      /*
       * @member description a string containing a description of the MagicItem
       */
      string description;
      
      /*
       * @member manaRequired an unsigned int containing the required mana cost for the MagicItem
       */
      unsigned int manaRequired;
      
  };