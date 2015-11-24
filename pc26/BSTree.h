/*
 * Programming Challenge 26 BSTree Header
 *
 * Steve Ross-Byers
 * Date created: 11/22/2015
 * Last date modified: 11/24/2015
 */
 
 #pragma once
 
 #include <iostream>
 
 #include "BSTNode.h"
 
 using namespace std;
 
 class BSTree {
     
     private:
        
        /*
         * @member root points to the root of the binary search tree
         */
        BSTNode* root;
        
        /*
         * @member size tracks the size of the binary search tree
         */
        unsigned int size;
        
        /*
         * Insert adds a node to the tree in order
         * @param contents an int containting the value to be assigned as the node contents
         * @param node a reference to a pointer to the node being tested in the current recursion cycle
         * @return true on successful insertion, or false if the value was already present
         */
        bool insert (int contents, BSTNode*& node);
	            
	    /*
         * Remove deletes a node from the tree
         * @param contents an int containting the value to be removed from the tree
         * @param node a reference to a pointer to the node being tested in the current recursion cycle
         * @return true on successful removal, or false if the value was not present
         */ 
	    bool remove (int contents, BSTNode*& node);
	             
	    /*
	     * removeMax is a helper function for the private remove function
	     */
	    void removeMax(int& contents, BSTNode*& node);
	             
	    /*
         * Clear removes nodes from the tree
         * @param node a reference to a pointer to the node to be removed
         */  
	    void clear (BSTNode*& node);
	
	    /*
         * InOrder insert the contents of nodes in the tree to an output stream (ascending order)
         * @param node a pointer to the node being added to the output stream
         * @param os a reference to the output stream accepting the node contents
         */  
	    void inOrder (BSTNode* node, ostream& os);
	    
     public:
     
        /*
         * BSTree default Constructor
         */
        BSTree();
	
	    /*
         * BSTree Destructor (calls the clear function)
         */
	    ~BSTree();
	
	    /*
         * Insert calls the private function insert on the root node
         * @param contents an int containting the value to be assigned as the node contents
         * @return true on successful insertion, or false if the value was already present
         */
	    bool insert(int contents);
	
	    /*
         * Remove calls the private function remove on the root node
         * @param contents an int containting the value to be removed from the tree
         * @return the returned result from the private function
         */
	    bool remove(int contents);
	
	    /*
         * Clear calls the private function clear on the root node
         */  
	    void clear();
	
	    /*
         * Size Getter
         * @return an int containing the number of nodes in the binary search tree
         */
	    unsigned int getSize() const;
	
	    /*
         * InOrder calls the private function inOrder on the root node
         * @param os a reference to the output stream accepting the node contents
         */  
	    void inOrder(ostream& os);
     
 };