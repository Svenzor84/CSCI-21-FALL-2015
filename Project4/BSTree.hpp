/*
 * Programming Project 4 BSTree Header Only Template Class
 *
 * Steve Ross-Byers
 * Date created: 12/3/2015
 * Last date modified: 12/3/2015
 */
 
 #pragma once
 
 #include <iostream>
 
 #include "BSTNode.hpp"
 
 using namespace std;
 
 template <class T>
 
 class BSTree {
     
     private:
        
        /*
         * @member root points to the root of the binary search tree
         */
        BSTNode<T>* root;
        
        /*
         * @member size tracks the size of the binary search tree
         */
        unsigned int size;
        
        /*
         * Insert adds a node to the tree in order
         * @param contents a T containting the value to be assigned as the node contents
         * @param node a reference to a pointer to the node being tested in the current recursion cycle
         * @return true on successful insertion, or false if the value was already present
         */
        bool insert (T contents, BSTNode<T>*& node) {
        	if (node == NULL) {
         		node = new BSTNode<T>(contents);
        		size++;
         		return true;
     		}
     		if (node->getData() == contents) {
         		return false;
     		}
     		if (node->getData() > contents) {
         		return insert(contents, node->getLeftChild());
     		} else {
         		return insert(contents, node->getRightChild());
     		}
        }
	        
	    /*
	     * Find locates a node with specific data contents
	     * @param contents the value to look for in the list
	     * @param node a reference to a pointer to the root node for the current recursion cycle
	     * @return true if the value is found, false otherwise
	     */
	    bool find (T contents, BSTNode<T>*& node) {
	    	if (node == NULL) {
	    		return false;
	    	}
	    	if (node->getData() == contents) {
	    		return true;
	    	}
	    	if (node->getData() < contents) {
	    		return find(contents, node->getRightChild());
	    	} else {
	    		return find(contents, node->getLeftChild());
	    	}
	    }        
	    
	    /*
         * Remove deletes a node from the tree
         * @param contents a T containting the value to be removed from the tree
         * @param node a reference to a pointer to the node being tested in the current recursion cycle
         * @return true on successful removal, or false if the value was not present
         */ 
	    bool remove (T contents, BSTNode<T>*& node) {
	    	if (node == NULL) {
	        		return false;
	    		}
	    		if (node->getData() == contents) {
	    			if (node->getLeftChild() == NULL) {
	            		BSTNode<T>* toRemove = node;
	            		node = node->getRightChild();
	            		delete toRemove;
	        		} else {
	            		removeMax(node->getData(), node->getLeftChild());
	        		}
	        		size--;
	        		return true;
	    		}
	    		if (node->getData() < contents) {
	        		return remove(contents, node->getRightChild());
	    		} else {
	        		return remove(contents, node->getLeftChild());
	    		}
	    }
	             
	    /*
	     * removeMax is a helper function for the private remove function
	     */
	    void removeMax(T& contents, BSTNode<T>*& node) {
	    	if (node->getRightChild() == NULL) {
	        		BSTNode<T>* tempNode = node;
	        		contents = node->getData();
	        		node = node->getLeftChild();
	        		delete tempNode;
	    		} else {
	        		removeMax(contents, node->getRightChild());
	    		}
	    }
	             
	    /*
	     * Get returns a pointer to the contents of a requested node
	     * @param contents the requested node contents
	     * @param node a pointer to the temporary root for the current recursion cycle
	     * @return a pointer to the requested node's contents on success, NULL on failure
	     */
	    T* get (T contents, BSTNode<T>*& node) {
	    	if (node == NULL) {
	    		return NULL;
	    	}
	    	if (node->getData() == contents) {
	    		T* requestedData = &node->getData();
	    		return requestedData;
	    	}
	    	if (node->getData() < contents) {
	    		return get(contents, node->getRightChild());
	    	} else {
	    		return get(contents, node->getLeftChild());
	    	}
	    }
	             
	    /*
         * Clear removes nodes from the tree
         * @param tempRoot a reference to a pointer to the node to be removed
         */  
	    void clear (BSTNode<T>*& tempRoot) {
	    	if (tempRoot == NULL) {}
     		else {
         		clear(tempRoot->getLeftChild());
         		clear(tempRoot->getRightChild());
         		delete tempRoot;
         		tempRoot = NULL;
         		size--;
     		}
	    }
	
	    /*
         * InOrder pass the contents of each node in the tree (in ascending order) to standard output
         * @param node a pointer to the node containing the contents being added to the standard output
         */  
	    void inOrder (BSTNode<T>* node) {
	    	if (node == NULL) {}
     		else {
         		inOrder(node->getLeftChild());
         		cout << node->getData() << endl;
         		inOrder(node->getRightChild());
     		}
	    }
	    
	    /*
	     * ReverseOrder pass the contents of each node in the tree (in descending order) to standard output
	     * @param node a pointer to the node containing the contents being added to the standard output
	     */
	    void reverseOrder (BSTNode<T>* node) {
	    	if (node == NULL) {}
     		else {
         		reverseOrder(node->getRightChild());
         		cout << node->getData() << endl;
         		reverseOrder(node->getLeftChild());
     		}
	    }
	    
     public:
     
        /*
         * BSTree default Constructor
         */
        BSTree()
        : root(NULL), size(0)
        {}
	
	    /*
         * BSTree Destructor (calls the clear function)
         */
	    ~BSTree() {
	    	clear();
	    }
	
	    /*
         * Insert calls the private function insert on the root node
         * @param contents a T containting the value to be assigned as the node contents
         * @return true on successful insertion, or false if the value was already present
         */
	    bool insert(T contents) {
     		return insert(contents, root);
 		}
	    
	    /*
	     * Find calls the private function find on the root node
	     * @param contents a T containing the value to search for
	     * @return true if T is in the list, or false otherwise
	     */
	    bool find(T contents) {
	    	return find(contents, root);
	    }
	
	    /*
         * Remove calls the private function remove on the root node
         * @param contents a T containting the value to be removed from the tree
         * @return the returned result from the private function
         */
	    bool remove(T contents) {
	    	return remove(contents, root);
	    }
	
		/*
		 * Get calls the private function get on the root node
		 * @param contents the requested contents
		 * @return a pointer to the  requested contents on success, NULL on failure
		 */
		T* get (T contents) {
			return get(contents, root);
		}
	
	    /*
         * Clear calls the private function clear on the root node
         */  
	    void clear() {
	    	clear(root);
	    }
	
	    /*
         * Size Getter
         * @return an unsigned int containing the number of nodes in the binary search tree
         */
	    unsigned int getSize() const {
	    	return size;
	    }
	
	    /*
         * InOrder calls the private function inOrder on the root node
         */  
	    void inOrder() {
	    	inOrder(root);
	    }
	    
	    /*
	     * ReverseOrder calls the private function reverseOrder on the root node
	     */
	    void reverseOrder () {
	    	reverseOrder(root);
	    }
     
 };