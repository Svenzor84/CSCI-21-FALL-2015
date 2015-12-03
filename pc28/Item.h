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
      
      /*
       * Item default Constructor
       * @param newName the string to be assigned to the member name (default argument is "item")
       * @param newValue assgins this value to the member value (default argument is 0)
       */
      Item(string newName = "item", unsigned int newValue = 0);
      
      /*
       * Item Destructor does nothing
       */
      virtual ~Item();
      
      /*
       * Name setter
       * @param newName assigns this string to the member name
       */
      void setName(string newName);
      
      /*
       * Value setter
       * @param newValue assigns this value to the member value
       */
      void setValue(unsigned int newValue);
      
      /*
       * Name getter
       * @return a string containing the value of the member name
       */
      string getName();
      
      /*
       * Value getter
       * @return an unsigned int containing the value of the member name
       */
      unsigned int getValue();
      
      /*
       * ToString returns a string containing the members of the Item
       * @return a string containing the item name followed by a comma, then a space, then a dollar sign and the value of the item
       */
      string toString();
      
    private:
      
      /*
       * @member name a string containing the name of the item
       */
      string name;
      
      /*
       * @member value an unsigned int that contains the value of the item
       */
      unsigned int value;
  };