/*
 * Programming Project 3 Driver
 *
 * Steve Ross-Byers
 * Date created: 11/4/2015
 * Last date modified: 11/6/2015
 */

#include "DLList.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

/*
 * Helper function that opens the input file, processes the file contents, 
 * executes commands based on the contents of the input file, and displays 
 * output messages to the console.
 * @param filename the name of the input file (passed in from argv[1])
 */
void processFile(char* filename);


/*
 * This is the program's main function/entry point.
 */
int main (int argc, char** argv) {
    
    //check to make sure there are exactly 2 arguments in the argv array
    if (argc != 2) {
        
        //if not, explain the usage of this program
        cout << "USAGE: " << argv[0] << " FILENAME" << endl;
        
    //otherwise
    } else {
        
        //call the process file function and pass in the name of the input file
        processFile(argv[1]);
    }
    return 0;
}

void processFile(char* filename) {
    
    //set up the input file stream and attempt to open the file
    ifstream fin;
    fin.open(filename);
    
    //if the file is successfully opened
    if (!fin.fail()) {
        
        //create a Doubly Linked List pointer (set to NULL)
        DLList* list = NULL;
        
        //set up reusable string stream object, int variable, and string nextLine
        stringstream ss;
        int value = 0;
        string nextLine;
        
        //while loop that continues until the end of the file is reached
        while (!fin.eof()){
            
            //get the next line from the file
            getline(fin, nextLine);
            
            //pull the first character from nextLine and make sure it is uppercase
            char firstCharacter = toupper(nextLine[0]);
            
            //if the character is C
            if (firstCharacter == 'C') {
                
                //if there is already a list, delete it first
                if (list != NULL) {
                    delete list;
                    list = NULL;
                }
                
                //create a new list and output success to the console
                list = new DLList;
                cout << "LIST CREATED" << endl;
                
            //if the first character is #
            } else if (firstCharacter == '#') {
                
                //do nothing
                
            } else {
                
                //any operation other than C requires a list instance
                //if there is no list instance
                if (list == NULL) {
                    
                    //output requirement to the console
                    cout << "MUST CREATE LIST INSTANCE" << endl;
                    
                } else {
                    
                    //if there is a list instance perform an operation based on the first character of nextLine
                    switch(firstCharacter) {
                        
                        //if the character is X
                        case 'X':
                        
                            //clear the list and output success to the console
                            list->clear();
                            cout << "LIST CLEARED" << endl;
                        break;
                        
                        //if the character is D
                        case 'D':
                        
                            //delete the list, set the list pointer to NULL, and output success to the console
                            delete list;
                            list = NULL;
                            cout << "LIST DELETED" << endl;
                        break;
                        
                        //if the character is I
                        case 'I':
                        
                            //get the integer value that follows the character
                            ss.str(nextLine.substr(2));
                            ss >> value;
                            
                            //insert a Node into the list with the integer value from the input file as contents (ascending order)
                            list->insert(value);
                            
                            //output success to the console
                            cout << "VALUE " << value << " INSERTED" << endl;
                            
                            //clear the stringstream
                            ss.clear();
                        break;
                        
                        //if the character is F
                        case 'F':
                        
                            //get the integer that follows the character
                            ss.str(nextLine.substr(2));
                            ss >> value;
                            
                            //insert a Node at the head pointer with the value from the input file as contents
                            list->pushFront(value);
                            
                            //output success to the console
                            cout << "VALUE " << value << " ADDED TO HEAD" << endl;
                            
                            //clear the stringstream
                            ss.clear();
                        break;
                        
                        //if the character is B
                        case 'B':
                        
                            //get the integer that follows the character
                            ss.str(nextLine.substr(2));
                            ss >> value;
                            
                            //insert a Node at the tail pointer with the value from the input file as contents
                            list->pushBack(value);
                            
                            //output success to the console
                            cout << "VALUE " << value << " ADDED TO TAIL" << endl;
                            
                            //clear the stringstream
                            ss.clear();
                        break;
                        
                        //if the character is A
                        case 'A':
                        
                            //attempt to output the value of the Node a the head pointer to the console
                            try {
                                
                                //output success to the console
                                cout << "VALUE " << list->getFront() << " AT HEAD" << endl;
                                
                            //if the attempt is unsuccessful (head is NULL)
                            } catch (string err) {
                                
                                //output failure to the console
                                cout << err << endl;
                            }
                        break;
                        
                        //if the character is Z
                        case 'Z':
                        
                            //attempt to output the value of the Node at the tail pointer to the console
                            try {
                                
                                //output success to the console
                                cout << "VALUE " << list->getBack() << " AT TAIL" << endl;
                                
                            //if the attempt is unsuccessful (tail is NULL)    
                            } catch (string err) {
                                
                                //output failure to the console
                                cout << err << endl;
                            }
                        break;
                        
                        //if the character is T
                        case 'T':
                        
                            //if the list is empty
                            if (list->getSize() < 1) {
                                
                                //output failure to the console
                                cout << "LIST EMPTY" << endl;
                                
                            } else {
                                
                                //remove the Node at the head pointer and output success to the console
                                list->popFront();
                                cout << "REMOVED HEAD" << endl;
                            }
                        break;
                        
                        //if the character is K
                        case 'K':
                        
                            //if the list is empty
                            if (list->getSize() < 1) {
                                
                                //output failure to the console
                                cout << "LIST EMPTY" << endl;
                                
                            } else {
                                
                                //remove the Node at the tail pointer and output success to the console
                                list->popBack();
                                cout << "REMOVED TAIL" << endl;
                            }
                        break;
                        
                        //if the character is E
                        case 'E':
                        
                            //get the integer that follows the character
                            ss.str(nextLine.substr(2));
                            ss >> value;
                            
                            //attempt to remove all instances of Nodes with the integer value from the list
                            if (list->removeAll(value) == true) {
                                
                                //output success to the console
                                cout << "VALUE " << value << " ELIMINATED" << endl;
                                
                            } else {
                                
                                //output failure to the console
                                cout << "VALUE " << value << " NOT FOUND" << endl;
                            }
                            
                            //clear the stringstream
                            ss.clear();
                        break;
                        
                        //if the character is R
                        case 'R':
                        
                            //get the integer value that follows the character  
                            ss.str(nextLine.substr(2));
                            ss >> value;
                            
                            //attempt to remove the first instance of a Node with the integer value from the list
                            if (list->removeFirst(value) == true) {
                                
                                //output success to the console
                                cout << "VALUE " << value << " REMOVED" << endl;
                                
                            } else {
                                
                                //output failure to the console
                                cout << "VALUE " << value << " NOT FOUND" << endl;
                            }
                            
                            //clear the stringstream
                            ss.clear();
                        break;
                        
                        //if the character is G
                        case 'G':
                        
                            //get the integer value that follows the character
                            ss.str(nextLine.substr(2));
                            ss >> value;
                            
                            //attempt to locate a Node with the integer value
                            if (list->get(value) == true) {
                                
                                //output success to the console
                                cout << "VALUE " << value << " FOUND" << endl;
                                
                            } else {
                                
                                //output failure to the console
                                cout << "VALUE " << value << " NOT FOUND" << endl;
                            }
                            
                            //clear the stringstream
                            ss.clear();
                        break;
                        
                        //if the character is N
                        case 'N':
                        
                            //output the number of Nodes in the list
                            cout << "LIST SIZE IS " << list->getSize() << endl;
                        break;
                        
                        //if the character is P
                        case 'P':
                        
                            //if the list is empty
                            if (list->getSize() < 1){
                                
                                //output failure to the console
                                cout << "LIST EMPTY" << endl;
                                
                            } else {
                                
                                //output the contents of every node in the list, from head to tail
                                cout << *list << endl;
                            }
                        break;
                    }
                }
            }
        }
        
        //close the file input stream
        fin.close();
        
    } else {
        
        //output failure to open the file to the console
        cout << "UNABLE TO OPEN FILE" << endl;
    }
}