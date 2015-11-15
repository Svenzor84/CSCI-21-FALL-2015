/*
 * Programming Challenge 24 BSTNode Header
 *
 * Steve Ross-Byers
 * Date created: 11/15/2015
 * Last date modified: 11/15/2015
 */
 
 #pragma once
 
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
         * @member contents the value contained by this node
         */
        int contents;
        
     public:
     
        /*
         * BSTNode default Constructor
         */
        BSTNode();
        
        /*
         * BSTNode Overloaded Constructor
         * @param newContents assigns this value as the contents of the new Node
         */
        BSTNode(int newContents);
        
        /*
         * BSTNode Destructor sets left and right children to NULL
         */
        ~BSTNode();
        
        /*
         * Contents Setter
         * @param newContents assigns this value to member contents
         */
        void setContents (int newConents);
        
        /*
         * Contents Getter
         * @return an int containing the value of the contents of this Node
         */
	    int getContents () const;
	    
	    /*
         * Contents Getter
         * @return a reference to the contents of this Node
         */
	    int& getContents ();
	    
	    /*
         * Left Child Setter
         * @param newLeftChild new target for the left child pointer
         */
	    void setLeftChild (BSTNode* newLeftChild);
	    
	    /*
         * Right Child Setter
         * @param newRightChild new target for the right child pointer
         */
    	void setRightChild (BSTNode* newRightChild);
    	
    	/*
         * Left Child Getter
         * @return a pointer to the left child node
         */
	    BSTNode* getLeftChild () const;
	    
	    /*
         * Left Child Getter
         * @return a reference to the left child pointer
         */
	    BSTNode*& getLeftChild ();
	
	    /*
         * Right Child Getter
         * @return a pointer to the right child node
         */
	    BSTNode* getRightChild () const;
	
	    /*
         * Right Child Getter
         * @return a reference to the right child pointer
         */
	    BSTNode*& getRightChild ();
 };