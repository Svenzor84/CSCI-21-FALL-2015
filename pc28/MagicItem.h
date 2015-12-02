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
    
      MagicItem(string newName = "magicitem", unsigned int newValue = 0, string newDescription = "no description", unsigned int newManaRequired = 0);
      virtual ~MagicItem();
      void setDescription(string newDescription);
      void setManaRequired(unsigned int newManaRequired);
      string getDescription();
      unsigned int getManaRequired();
      string toString();
      
    private:
      
      string description;
      unsigned int manaRequired;
      
  };