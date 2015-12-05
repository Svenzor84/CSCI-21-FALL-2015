/*
 * Programming Project 4 Driver
 *
 * Steve Ross-Byers
 * Date created: 12/3/2015
 * Last date modified: 12/4/2015
 */
  
 #include "BSTree.hpp"
 #include "Word.h"
 #include <fstream>
 #include <sstream>
 
/*
 * Helper function that opens the input file, processes the file contents, 
 * executes commands based on the contents of the input file, and displays 
 * output messages to the console.
 * @param filename the name of the input file (passed in from argv[1])
 */
void processFile(char* filename);

/*
 * Main function/entry point
 */
int main(int argc, char** argv) {
    
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
     
        //create a Binary Search Tree pointer of type Word (set to NULL)
        BSTree<Word>* Tree = NULL;
        
        //set up the stringstream, nextLine and inputString strings
        string nextLine;
        string inputString;
        stringstream ss;
        
        //while loop that continues until the end of the file is reached
        while (!fin.eof()){
            
            //get the next line from the file
            getline(fin, nextLine);
            
            //pull the first character from nextLine and make sure it is uppercase
            char firstCharacter = toupper(nextLine[0]);
            
            //if the character is C
            if (firstCharacter == 'C') {
                
                //if there is already a tree, delete it first
                if (Tree != NULL) {
                    delete Tree;
                    Tree = NULL;
                }
                
                //create a new Tree instance
                Tree = new BSTree<Word>;
                
                //output success to the console
                cout << "TREE CREATED" << endl;
                
            //if the character is #
            } else if (firstCharacter == '#') {
                
                //do nothing
                
            //otherwise...
            } else {
                
                //check to make sure there is a Tree instance for any other operation
                if (Tree == NULL) {
                    
                    //output failure if Tree is NULL
                    cout << "MUST CREATE TREE INSTANCE" << endl;
                    
                //if Tree is not NULL we can perform operations
                } else {
                    
                    //switch on the first character of the current line from the input file
                    switch(firstCharacter) {
                        
                        //if the character is X
                        case 'X':
                            
                            //clear the list and report success
                            Tree->clear();
                            cout << "TREE CLEARED" << endl;
                        break;
                        
                        //if the character is D
                        case 'D':
                        
                            //delete the Tree, set the pointer to NULL, and report success
                            delete Tree;
                            Tree = NULL;
                            cout << "TREE DELETED" << endl;
                        break;
                        
                        //if the character is I
                        case 'I':
                        
                            //get the string that follows the character and store it
                            ss.str(nextLine.substr(2));
                            ss >> inputString;
                            
                            //if there is already a word object that contains the input string
                            if(Tree->find(inputString)) {
                                
                                //get a pointer to the word object and increment its count
                                Tree->get(inputString)->incrementCount();
                                
                                //report success
                                cout << "WORD " << Tree->get(inputString)->getWord() << " INCREMENTED" << endl;
                                
                            //if the inputString was not found in the Tree
                            } else {
                                
                                //insert the word object into the Tree and report success
                                Tree->insert(Word(inputString));
                                cout << "WORD " << Tree->get(inputString)->getWord() << " INSERTED" << endl;
                            }
                            
                            //clear the stringstream
                            ss.clear();
                        break;
                        
                        //if the character is F
                        case 'F':
                        
                            //get the string that follows the character and store it
                            ss.str(nextLine.substr(2));
                            ss >> inputString;
                        
                            //if the Tree is empty
                            if (Tree->getSize() < 1) {
                                
                                //report failure
                                cout << "TREE EMPTY" << endl;
                                
                            //otherwise, if the inputString is not found in the Tree
                            } else if (!Tree->find(inputString)) {
                                
                                //report failure
                                cout << inputString << " NOT FOUND" << endl;
                                
                            //otherwise the inputString was found, so...
                            } else {
                                
                                //report success
                                cout << "FOUND " << Tree->get(inputString)->getWord() << endl;
                            }
                            
                            //clear the stringstream
                            ss.clear();
                        break;
                        
                        //if the character is R
                        case 'R':
                        
                            //get the string that follows the character and store it
                            ss.str(nextLine.substr(2));
                            ss >> inputString;
                        
                            //if the Tree is empty
                            if (Tree->getSize() < 1) {
                                
                                //report failure
                                cout << "TREE EMPTY" << endl;
                                
                            //otherwise, if the inputString is not found in the Tree
                            } else if (!Tree->find(inputString)) {
                                
                                //report failure
                                cout << inputString << " NOT FOUND" << endl;
                                
                            //otherwise the inputString was found, so...
                            } else {
                                
                                //remove the word and report success
                                cout << "REMOVED " << Tree->get(inputString)->getWord() << endl;
                                Tree->remove(inputString);
                            }
                            
                            //clear the stringstream
                            ss.clear();
                        break;
                        
                        //if the character is G
                        case 'G':
                        
                            //get the string that follows the character and store it
                            ss.str(nextLine.substr(2));
                            ss >> inputString;
                        
                            //if the Tree is empty
                            if (Tree->getSize() < 1) {
                                
                                //report failure
                                cout << "TREE EMPTY" << endl;
                                
                            //otherwise, if the inputString is not found in the Tree
                            } else if (!Tree->find(inputString)) {
                                
                                //report failure
                                cout << inputString << " NOT FOUND" << endl;
                                
                            //otherwise the inputString was found, so...
                            } else {
                                
                                //remove the word and report success
                                cout << "GOT " << *Tree->get(inputString) << endl;
                            }
                            
                            //clear the stringstream
                            ss.clear();
                        break;
                        
                        //if the character is N
                        case 'N':
                        
                            //output the number of nodes in the Tree
                            cout << "TREE SIZE IS " << Tree->getSize() << endl;;
                        break;
                        
                        //if the character is O
                        case 'O':
                        
                            //check to make sure the Tree is not empty
                            if (Tree->getSize() < 1) {
                                
                                //output failure
                                cout << "TREE EMPTY" << endl;
                                
                            //otherwise...
                            } else {
                                
                                //output the entire Tree in ascending alphabetical order
                                Tree->inOrder();
                            }
                        break;
                        
                        //if the character is E
                        case 'E':
                        
                            //check to make sure the Tree is not empty
                            if (Tree->getSize() < 1) {
                                
                                //output failure
                                cout << "TREE EMPTY" << endl;
                                
                            //otherwise...
                            } else {
                                
                                //output the entire Tree in descending alphabetical order
                                Tree->reverseOrder();
                            }
                        break;
                    }
                }
            }
        }
        
    } else {
     
        //output failure to open the file to the console
        cout << "UNABLE TO OPEN FILE" << endl;
    }
}
 
 /*
 BSTree<int> tree1;
    tree1.insert(50);
    tree1.inOrder();
    cout << endl;
    
    tree1.insert(25);
    tree1.insert(75);
    cout << "size: " << tree1.getSize() << endl;
    tree1.inOrder();
    cout << endl;
    tree1.reverseOrder();
    cout << endl;
    
    tree1.insert(100);
    tree1.insert(0);
    cout << "size: "<< tree1.getSize() << endl;
    tree1.inOrder();
    cout << endl;
    tree1.reverseOrder();
    cout << endl;
    
    tree1.insert(10);
    tree1.insert(20);
    tree1.insert(30);
    tree1.insert(40);
    tree1.insert(50);
    tree1.insert(60);
    tree1.insert(70);
    tree1.insert(80);
    tree1.insert(90);
    tree1.insert(100);
    cout << "size: " << tree1.getSize() << endl;
    tree1.inOrder();
    cout << endl;
    tree1.reverseOrder();
    cout << endl;
    
    tree1.remove(50);
    cout << "size: " << tree1.getSize() << endl;
    tree1.inOrder();
    cout << endl;
    tree1.reverseOrder();
    cout << endl;
    
    tree1.remove(10);
    tree1.remove(30);
    tree1.remove(70);
    tree1.remove(90);
    tree1.remove(0);
    cout << "size: " << tree1.getSize() << endl;
    tree1.inOrder();
    cout << endl;
    tree1.reverseOrder();
    cout << endl;
 */