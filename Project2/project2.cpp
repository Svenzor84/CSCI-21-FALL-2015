/*
 * Project 2 Unit Test and Driver with Interface
 *
 * Steve Ross-Byers
 * Date created: 10/12/2015
 * Last date modified: 10/11/2015
 *
 * Sources: CinReader by Boyd Trolinger
 */

#include "box.h"

#include <cstdlib>
#include <iostream>
#include <string>

#include "CinReader.h"

using namespace std;

//interactive test support functions
void enterToContinue();
void clearScreen();
void menu();

//set up CinReader
CinReader reader;

/* for unit testing -- do not alter */
template <typename X, typename A>
void btassert(A assertion);
void unittest ();

int main () {
    unittest();
	
	enterToContinue();
	
    // CODE HERE -- INTERACTIVE TEST
    menu();
    
    return 0;
}

//interactive test support functions
void enterToContinue() {
    string press_enter;
    cout << "<PRESS [ENTER] TO CONTINUE>\n" << endl;
    press_enter = reader.readString(true, 0);
}

void clearScreen() {
    cout << "\n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n"
         << "\n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n";
}

void menu() {
    
    //set up the default prize and box
    Prize prize1;
    Box box1;
    
    //set up the custom prize and box
    string pName;
    unsigned int pValue = 0;
    cout << "Please enter values for the Custom Prize\n"
         << "Name: ";
    pName = reader.readString(false);
    cout << "Value: ";
    pValue = reader.readInt(0);
    Prize prize2(pName, pValue);
    
    unsigned int bNum = 0, bPrizeCap = 0;
    string bColor;
    cout << "Please enter Stats for the Custom Box\n"
         << "Number: ";
    bNum = reader.readInt(0);
    cout << "Color: ";
    bColor = reader.readString(false);
    cout << "Prize Capacity: ";
    bPrizeCap = reader.readInt(0);
    Box box2(bNum, bColor, bPrizeCap);
    clearScreen();
    
    //variable to hold the user's choice from the menu
    char user_choice;
    
    //bool for looping the menu
    bool menu_loop = true;
    while (menu_loop == true){
        cout << "*** Which function would you like to test? ***\n"
             << "Create Custom Objects to Unlock More Functions\n"
             << "[A] Display the Stats of the Default Prize\n"
             << "[B] Display the Stats of the Custom Prize\n"
             << "[C] Change the Name of the Custom Prize\n"
             << "[D] Change the Value of the Custom Prize\n"
             << "[E] Display the Stats of the Default Box\n"
             << "[F] Display the Stats of the Custom Box\n"
             << "[G] Change the Number of the Custom Box\n"
             << "[H] Change the Color of the Custom Box\n"
             << "[I] Add the Default Prize to the Custom Box\n"
             << "[J] Add the Custom Prize to the Custom Box\n"
             << "[K] List all the Prizes in the Custom Box\n"
             << "[L] Remove a Specific Prize from the Custom Box\n"
             << "[M] Compare two Prizes from the Custom Box\n"
             << "        [Q] to Quit the Interactive Test\n"
             << " ";
        user_choice = reader.readChar("AaBbCcDdEeFfGgHhIiJjKkLlMmNnQq");
        switch (toupper(user_choice)){
            
            //Display Name and Value of prize1
            case 'A':
                clearScreen();
                cout << "Default Prize\n" 
                     << "-Name: " << prize1.getPrizeName() << "\n"
                     << "-Value: " << prize1.getPrizeValue() << endl;
                enterToContinue();
                clearScreen();
                break;
                
            //Display Name and Value of prize2
            case 'B':
                clearScreen();
                cout << "Custom Prize\n" 
                     << "-Name: " << prize2.getPrizeName() << "\n"
                     << "-Value: " << prize2.getPrizeValue() << endl;
                enterToContinue();
                clearScreen();
                break;
                
            //Change the name of prize2
            case 'C':
                clearScreen();
                cout << "Enter the New Name for the Custom Prize: "; 
                prize2.setPrizeName(reader.readString(false));
                clearScreen();
                cout << "Custom Prize\n" 
                     << "-Name: " << prize2.getPrizeName() << "\n"
                     << "-Value: " << prize2.getPrizeValue() << endl;
                enterToContinue();
                clearScreen();
                break;
                
            //Change the value of prize2
            case 'D':
                clearScreen();
                cout << "Enter a New Value for the Custom Prize: ";
                prize2.setPrizeValue(reader.readInt(0));
                clearScreen();
                cout << "Custom Prize\n" 
                     << "-Name: " << prize2.getPrizeName() << "\n"
                     << "-Value: " << prize2.getPrizeValue() << endl;
                enterToContinue();
                clearScreen();
                break;
                
            //Display the Number, Color, and Capacity of box1
            case 'E':
                clearScreen();
                cout << "Default Box\n" 
                     << "-Number: " << box1.getBoxNumber() << "\n"
                     << "-Color: " << box1.getBoxColor() << "\n"
                     << "-Prize Count: " << box1.getPrizeCount() << "\n"
                     << "-Prize Capacity: " << box1.getPrizeCapacity() << endl;
                enterToContinue();
                clearScreen();
                break;
                
            //Display the Number, Color, and Capacity of box2
            case 'F':
                clearScreen();
                cout << "Custom Box\n" 
                     << "-Number: " << box2.getBoxNumber() << "\n"
                     << "-Color: " << box2.getBoxColor() << "\n"
                     << "-Prize Count: " << box2.getPrizeCount() << "\n"
                     << "-Prize Capacity: " << box2.getPrizeCapacity() << endl;
                enterToContinue();
                clearScreen();
                break;
                
            //Change the number of of box2
            case 'G':
                clearScreen();
                cout << "Enter a New Number for the Custom Box: ";
                box2.setBoxNumber(reader.readInt(0));
                clearScreen();
                cout << "Custom Box\n" 
                     << "-Number: " << box2.getBoxNumber() << "\n"
                     << "-Color: " << box2.getBoxColor() << "\n"
                     << "-Prize Count: " << box2.getPrizeCount() << "\n"
                     << "-Prize Capacity: " << box2.getPrizeCapacity() << endl;
                enterToContinue();
                clearScreen();
                break;
                
            //Change the color of box2
            case 'H':
                clearScreen();
                cout << "Enter a New Color for the Custom Box: ";
                box2.setBoxColor(reader.readString(false));
                clearScreen();
                cout << "Custom Box\n" 
                     << "-Number: " << box2.getBoxNumber() << "\n"
                     << "-Color: " << box2.getBoxColor() << "\n"
                     << "-Prize Count: " << box2.getPrizeCount() << "\n"
                     << "-Prize Capacity: " << box2.getPrizeCapacity() << endl;
                enterToContinue();
                clearScreen();
                break;
                
            //Add prize1 to box2 if there is room
            case 'I':
                clearScreen();
                if (box2.getPrizeCount() < box2.getPrizeCapacity()){
                    box2.addPrize(prize1);
                    cout << "***The Default Prize has been Added to the Custom Box.\n"
                         << "Custom Box\n" 
                         << "-Number: " << box2.getBoxNumber() << "\n"
                         << "-Color: " << box2.getBoxColor() << "\n"
                         << "-Prize Count: " << box2.getPrizeCount() << "\n"
                         << "-Prize Capacity: " << box2.getPrizeCapacity() << endl;
                } else {
                    cout << "The Box is full, remove a Prize to Add a new Prize.\n";
                }
                enterToContinue();
                clearScreen();
                break;
                
            //Add prize2 to box2 if there is room
            case 'J':
                clearScreen();
                if (box2.getPrizeCount() < box2.getPrizeCapacity()){
                    box2.addPrize(prize2);
                    cout << "***The Custom Prize has been Added to the Custom Box.\n"
                         << "Custom Box\n" 
                         << "-Number: " << box2.getBoxNumber() << "\n"
                         << "-Color: " << box2.getBoxColor() << "\n"
                         << "-Prize Count: " << box2.getPrizeCount() << "\n"
                         << "-Prize Capacity: " << box2.getPrizeCapacity() << endl;
                } else {
                    cout << "The Box is full, remove a Prize to Add a new Prize.\n";
                }
                enterToContinue();
                clearScreen();
                break;
                
            //Display the name and value of each prize in box2
            case 'K':
                clearScreen();
                for (unsigned int i = 0; i < box2.getPrizeCount(); i++){
                    cout << "-Name: " << box2.getPrize(i).getPrizeName() << "\n"
                         << "-Value: " << box2.getPrize(i).getPrizeValue() << "\n" << endl;
                }
                enterToContinue();
                clearScreen();
                break;
                
            //Remove a specific prize from box2, if there are prizes to remove
            case 'L':
                clearScreen();
                if (box2.getPrizeCount() > 0){
                    cout << "Which Prize would you like to Remove?\n"
                         << "(1 for first prize, 2 for second prize, etc)" << endl;
                    box2.removePrize((reader.readInt(1, box2.getPrizeCount())) - 1);
                    clearScreen();
                    cout << "***The Prize has been Removed from the Custom Box.\n"
                         << "Custom Box\n" 
                         << "-Number: " << box2.getBoxNumber() << "\n"
                         << "-Color: " << box2.getBoxColor() << "\n"
                         << "-Prize Count: " << box2.getPrizeCount() << "\n"
                         << "-Prize Capacity: " << box2.getPrizeCapacity() << endl;
                } else {
                    cout << "There are no Prizes to Remove.  Add a Prize to Remove it.\n";
                }
                enterToContinue();
                clearScreen();
                break;
                
            //Compare two prizes from box2, if there are any prizes in box2
            case 'M':
                if (box2.getPrizeCount() > 0) {
                    int choice1 = 0, choice2 = 0;
                    clearScreen();
                    cout << "Select a Prize to Compare (from Custom Box)\n"
                         << "(1 for first prize, 2 for second prize, etc)" << endl;
                    choice1 = reader.readInt(1, box2.getPrizeCount());
                    cout << "Select another Prize to Compare (from Custom Box)\n"
                         << "(1 for first prize, 2 for second prize, etc)" << endl;
                    choice2 = reader.readInt(1, box2.getPrizeCount());
                    clearScreen();
                    if (box2.getPrize(choice1 - 1) == box2.getPrize(choice2 - 1)) {
                        cout << "These Prizes are the same!!!" << endl;
                        enterToContinue();
                        clearScreen();
                    } else {
                        cout << "These Prizes are not the same." << endl;
                        enterToContinue();
                        clearScreen();
                    }
                } else {
                    clearScreen();
                    cout << "There are not enough Prizes to Compare.\n"
                         << "Add more Prizes to the Custom Box to Compare." << endl;
                    enterToContinue();
                    clearScreen();
                }
                break;
                
            //Quit the interactive test
            case 'Q':
                clearScreen();
                cout << "Thank you for running this program!\n";
                menu_loop = false;
                break;
        }
    }
}

/*
 * Unit testing functionb1. Do not alter.
 */

void unittest () {

    unsigned short utCount = 35;
    unsigned short utPassed = 0;

    cout << "\nSTARTING UNIT TEST\n\n";
	
    Box b1;
    Box b2(42, "blue", 3);
	
    cout << "** TESTING DEFAULT BOX **\n\n";
	
    try {
        btassert<bool>(b1.getBoxNumber() == 0);
        cout << "Passed TEST 1: Box getBoxNumber()\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 1 Box getBoxNumber() #\n";
    }
	
    try {
        btassert<bool>(b1.getBoxColor() == "NO COLOR");
        cout << "Passed TEST 2: Box getBoxColor()\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 2 Box getBoxColor() #\n";
    }
    
    try {
        btassert<bool>(b1.getPrizeCapacity() == 5);
        cout << "Passed TEST 3: Box getPrizeCapacity()\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 3 Box getPrizeCapacity() #\n";
    }
	
    try {
        btassert<bool>(b1.getPrizeCount() == 0);
        cout << "Passed TEST 4: Box getPrizeCount()\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 4 Box getPrizeCount() #\n";
    }
	
    b1.setBoxNumber(99);
    try {
        btassert<bool>(b1.getBoxNumber() == 99);
        cout << "Passed TEST 5: Box setBoxNumber()/getBoxNumber()\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 5 Box setBoxNumber()/getBoxNumber() #\n";
    }
	
    b1.setBoxColor("red");
    try {
        btassert<bool>(b1.getBoxColor() == "red");
        cout << "Passed TEST 6: Box setBoxColor()/getBoxColor()\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 6 Box setBoxColor()/getBoxColor() #\n";
    }
    
    cout << "\n** TESTING CUSTOM BOX **\n\n";
	
    try {
        btassert<bool>(b2.getBoxNumber() == 42);
        cout << "Passed TEST 7: Box getBoxNumber()\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 7 Box getBoxNumber() #\n";
    }
	
    try {
        btassert<bool>(b2.getBoxColor() == "blue");
        cout << "Passed TEST 8: Box getBoxColor()\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 8 Box getBoxColor() #\n";
    }
    
    try {
        btassert<bool>(b2.getPrizeCapacity() == 3);
        cout << "Passed TEST 9: Box getPrizeCapacity()\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 9 Box getPrizeCapacity() #\n";
    }
	
    try {
        btassert<bool>(b2.getPrizeCount() == 0);
        cout << "Passed TEST 10: Box getPrizeCount()\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 10 Box getPrizeCount() #\n";
    }
	
    try {
        btassert<bool>(b2.getPrize(0) == Prize());
        cout << "Passed TEST 11: Box getPrize(0)\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 11 Box getPrize(0) #\n";
    }
	
    try {
        btassert<bool>(b2.removePrize(0) == Prize());
        cout << "Passed TEST 12: Box removePrize(0)\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 12 Box removePrize(0) #\n";
    }
    
    b2.addPrize(Prize("BRONZE PRIZE", 1));
    try {
        btassert<bool>(b2.getPrizeCount() == 1);
        cout << "Passed TEST 13: Box addPrize()/getPrizeCount()\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 13 Box addPrize()/getPrizeCount() #\n";
    }
    
    b2.addPrize(Prize("SILVER PRIZE", 100));
    try {
        btassert<bool>(b2.getPrizeCount() == 2);
        cout << "Passed TEST 14: Box addPrize()/getPrizeCount()\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 14 Box addPrize()/getPrizeCount() #\n";
    }
        
    b2.addPrize(Prize("GOLD PRIZE", 1000));
    try {
        btassert<bool>(b2.getPrizeCount() == 3);
        cout << "Passed TEST 15: Box addPrize()/getPrizeCount()\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 15 Box addPrize()/getPrizeCount() #\n";
    }
    
    try {
        btassert<bool>(b2.addPrize(Prize("DIAMOND PRIZE", 999)) == false);
        cout << "Passed TEST 16: Box addPrize(ARRAY FULL)\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 16 Box addPrize(ARRAY FULL) #\n";
    }
	
    try {
        btassert<bool>(b2.getPrize(1) == Prize("SILVER PRIZE", 100));
        cout << "Passed TEST 17: Box getPrize(1)\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 17 Box getPrize(1) #\n";
    }
	
    try {
        btassert<bool>(b2.removePrize(2) == Prize("GOLD PRIZE", 1000));
        cout << "Passed TEST 18: Box removePrize(2)\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 18 Box removePrize(2) #\n";
    }
    
    try {
        btassert<bool>(b2.getPrizeCount() == 2);
        cout << "Passed TEST 19: Box getPrizeCount()\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 19 Box getPrizeCount() #\n";
    }
	
    try {
        btassert<bool>(b2.removePrize(2) == Prize());
        cout << "Passed TEST 20: Box removeCargo(2)\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 20 Box removeCargo(2) #\n";
    }
	
    try {
        btassert<bool>(b2.getPrize(2) == Prize());
        cout << "Passed TEST 21: Box getPrize(2)\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 21 Box getPrize(2) #\n";
    }
	
    try {
        btassert<bool>(b2.addPrize(Prize("RUBY PRIZE", 9999)) == true);
        cout << "Passed TEST 22: Box addPrize(\"RUBY PRIZE\", 9999)\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 22 Box addPrize(\"RUBY PRIZE\", 9999) #\n";
    }
    
    try {
        btassert<bool>(b2.getPrizeCount() == 3);
        cout << "Passed TEST 23: Box getPrizeCount()\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 23 Box getPrizeCount() #\n";
    }
	
    try {
        btassert<bool>(b2.getPrizeCapacity() == 3);
        cout << "Passed TEST 24: Box getPrizeCapacity()\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 24 Box getPrizeCapacity() #\n";
    }
	
    cout << "\n** TESTING PRIZE **\n\n";
	
    Prize p1;
	
    try {
        btassert<bool>(p1.getPrizeName() == "NO NAME");
        cout << "Passed TEST 25: Prize getPrizeName()\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 25 Prize getPrizeName() #\n";
    }
	
    try {
        btassert<bool>(p1.getPrizeValue() == 0);
        cout << "Passed TEST 26: Prize getPrizeValue()\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 26 Prize getPrizeValue() #\n";
    }
	
    p1.setPrizeName("FOOD PRIZE");
    try {
        btassert<bool>(p1.getPrizeName() == "FOOD PRIZE");
        cout << "Passed TEST 27: Prize setPrizeName(\"FOOD PRIZE\")/getPrizeName()\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 27 Prize setPrizeName(\"FOOD PRIZE\")/getPrizeName() #\n";
    }
	
    p1.setPrizeValue(17);
    try {
        btassert<bool>(p1.getPrizeValue() == 17);
        cout << "Passed TEST 28: Prize setPrizeValue(17)/getPrizeValue()\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 28 Prize setPrizeValue(17)/getPrizeValue() #\n";
    }
	
    Prize p2("HAT PRIZE", 50);
	
    try {
        btassert<bool>(p2.getPrizeName() == "HAT PRIZE");
        cout << "Passed TEST 29: Prize getPrizeName()\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 29 Prize getPrizeName() #\n";
    }
	
    try {
        btassert<bool>(p2.getPrizeValue() == 50);
        cout << "Passed TEST 30: Prize getPrizeValue()\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 30 Prize getPrizeValue() #\n";
    }
    
    try {
        btassert<bool>(!(p1 == p2));
        cout << "Passed TEST 31: !(Prize == Prize)\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 31 !(Prize == Prize) #\n";
    }
    
    p2.setPrizeName("FOOD PRIZE");
    try {
        btassert<bool>(p2.getPrizeName() == "FOOD PRIZE");
        cout << "Passed TEST 32: Prize setPrizeName(\"FOOD PRIZE\")/getPrizeName()\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 32 Prize setPrizeName(\"FOOD PRIZE\")/getPrizeName() #\n";
    }
	
    p2.setPrizeValue(17);
    try {
        btassert<bool>(p2.getPrizeValue() == 17);
        cout << "Passed TEST 33: Prize setPrizeValue(17)/getPrizeValue()\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 33 Prize setPrizeValue(17)/getPrizeValue() #\n";
    }
    
    try {
        btassert<bool>(p1 == p2);
        cout << "Passed TEST 34: (Prize == Prize)\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 34 (Prize == Prize) #\n";
    }
    
    p2.setPrizeValue(1);
    try {
        btassert<bool>(!(p1 == p2));
        cout << "Passed TEST 35: !(Prize == Prize)\n";
        ++utPassed;
    } catch (bool b) {
        cout << "# FAILED TEST 35 !(Prize == Prize) #\n";
    }
	
    cout << "\nUNIT TEST COMPLETE\n\n";
    
    cout << "PASSED " << utPassed << " OF " << utCount << " UNIT TEST";
    if (utCount > 1) {
        cout << "S";
    }
    cout << "\n\n";
}

template <typename X, typename A>
void btassert (A assertion) {
    if (!assertion)
        throw X();
}
