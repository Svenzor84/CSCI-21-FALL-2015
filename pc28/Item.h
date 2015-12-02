/*
 * Programming Challenge 28 Item Header
 *
 * Steve Ross-Byers
 * Date created: 12/1/2015
 * Last date modified: 12/1/2015
 */
  #pragma once
  
  #include <string>
  #include <sstream>
  
  using namespace std;
  
  class Item {
      
    public:
      
      Item(string newName = "item", unsigned int newValue = 0);
      virtual ~Item();
      void setName(string newName);
      void setValue(unsigned int newValue);
      string getName();
      unsigned int getValue();
      string toString();
      
    private:
      
      string name;
      unsigned int value;
  };