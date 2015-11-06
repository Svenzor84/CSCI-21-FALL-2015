/*
 * Programming Project 3 Driver
 *
 * Steve Ross-Byers
 * Date created: 11/4/2015
 * Last date modified: 11/5/2015
 */
 
 #include "DLList.h"
 #include <iostream>
 using namespace std;
 
 int main (int argc, char** argv) {
   
   DLList list;
   
   cout << list << endl;
   cout << list.getSize() << endl;

   list.insert(10);
   list.insert(9);
   list.insert(8);
   list.insert(7);
   list.insert(6);
   list.insert(1);
   list.insert(2);
   list.insert(3);
   list.insert(4);
   list.insert(5);
   list.insert(6);
    
   cout << list << endl;
   cout << list.getSize() << endl;
   try {
   cout << list.getFront() << endl;
   } catch (const char* err) {
        cout << err << endl;
    }
   try {
   cout << list.getBack() << endl;
   } catch (const char* err) {
        cout << err << endl;
    }
   
   list.removeAll(6);
   
   cout << list << endl;
   cout << list.getSize() << endl;
   cout << list.getFront() << endl;
   cout << list.getBack() << endl;
   
   list.clear();
   
   cout << list << endl;
   cout << list.getSize() << endl;
   cout << list.getFront() << endl;
   cout << list.getBack() << endl;
   
   return 0;
 }