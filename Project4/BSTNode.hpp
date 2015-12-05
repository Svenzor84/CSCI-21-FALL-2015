/*
 * Programming Project 4 BSTNode Header Only Template Class
 *
 * Steve Ross-Byers
 * Date created: 12/3/2015
 * Last date modified: 12/3/2015
 */
 
 #pragma once
 
 #include <cstdlib>
 
 using namespace std;
 
 template <class T>
 
 class BSTNode {
     
     private:
     
        /*
         * @member leftChild points to the left child node of this node
         */
        BSTNode* leftChild;
        
        /*
         * @member rightChild points to the right child node of this node
         */
        BSTNode* rightChild;
        
        /*
         * @member data the value contained by this node
         */
        T data;
        
     public:
        
        /*
         * BSTNode Constructor
         * @param newData assigns this value as the data of the new Node
         */
        BSTNode(T newData)
        : leftChild(NULL), rightChild(NULL), data(newData)
        {}
        
        /*
         * BSTNode Destructor sets left and right children to NULL
         */
        ~BSTNode() {
            leftChild = NULL;
            rightChild = NULL;
        }
        
        /*
         * Data Setter
         * @param newData assigns this value to member data
         */
        void setData (T newData) {
            data = newData;
        }
        
        /*
         * Data Getter
         * @return a T containing the value of the data of this Node
         */
	       T getData () const {
	           return data;
	       }
	    
	       /*
         * Data Getter
         * @return a reference to the data of this Node
         */
	       T& getData () {
	           return data;
	       }
	    
	       /*
         * Left Child Setter
         * @param newLeftChild new target for the left child pointer
         */
	       void setLeftChild (BSTNode* newLeftChild) {
	           leftChild = newLeftChild;
	       }
	    
	       /*
         * Right Child Setter
         * @param newRightChild new target for the right child pointer
         */
    	   void setRightChild (BSTNode* newRightChild) {
    	       rightChild = newRightChild;
    	   }
    	
    	   /*
         * Left Child Getter
         * @return a pointer to the left child node
         */
	       BSTNode* getLeftChild () const {
	           return leftChild;
	       }
	    
	       /*
         * Left Child Getter
         * @return a reference to the left child pointer
         */
	       BSTNode*& getLeftChild () {
	           return leftChild;
	       }
	
	       /*
         * Right Child Getter
         * @return a pointer to the right child node
         */
	       BSTNode* getRightChild () const {
	           return rightChild;
	       }
	
	       /*
         * Right Child Getter
         * @return a reference to the right child pointer
         */
	       BSTNode*& getRightChild () {
	           return rightChild;
	       }
 };