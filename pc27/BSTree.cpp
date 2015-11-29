/*
 * Programming Challenge 27 BSTree Implementation
 *
 * Steve Ross-Byers
 * Date created: 11/29/2015
 * Last date modified: 11/29/2015
 */
 
 #include "BSTree.h"
 
 //public functions
 
 BSTree::BSTree()
 : root(NULL), size(0)
 {}
	
 BSTree::~BSTree() {
     clear();
 }
	
 bool BSTree::insert(int contents) {
     return insert(contents, root);
 }
	
	bool BSTree::remove(int contents) {
	    return remove(contents, root);
	}
	
 void BSTree::clear() {
     clear(root);
 }
	
 unsigned int BSTree::getSize() const {
     return size;
 }
	
 void BSTree::inOrder(void (*func)(int)) {
     inOrder(root, func);
 }
 
 void BSTree::reverseOrder (void (*func)(int)) {
     reverseOrder(root, func);
 }
 
 //private functions
 
 bool BSTree::insert(int contents, BSTNode*& node) {
     if (node == NULL) {
         node = new BSTNode(contents);
         size++;
         return true;
     }
     if (node->getContents() == contents) {
         return false;
     }
     if (node->getContents() > contents) {
         return insert(contents, node->getLeftChild());
     } else {
         return insert(contents, node->getRightChild());
     }
 }
	      
	bool BSTree::remove (int contents, BSTNode*& node) {
	    if (node == NULL) {
	        return false;
	    }
	    if (node->getContents() == contents) {
	        if (node->getLeftChild() == NULL) {
	            BSTNode* toRemove = node;
	            node = node->getRightChild();
	            delete toRemove;
	        } else {
	            removeMax(node->getContents(), node->getLeftChild());
	        }
	        size--;
	        return true;
	    }
	    if (node->getContents() < contents) {
	        return remove(contents, node->getRightChild());
	    } else {
	        return remove(contents, node->getLeftChild());
	    }
	}
	            
	void BSTree::removeMax(int& contents, BSTNode*& node) {
	    if (node->getRightChild() == NULL) {
	        BSTNode* tempNode = node;
	        contents = node->getContents();
	        node = node->getLeftChild();
	        delete tempNode;
	    } else {
	        removeMax(contents, node->getRightChild());
	    }
	}
	               
 void BSTree::clear(BSTNode*& node) {
     if (node == NULL) {}
     else {
         clear(node->getLeftChild());
         clear(node->getRightChild());
         delete node;
         node = NULL;
         size--;
     }
 }
	
 void BSTree::inOrder(BSTNode* node, void (*func)(int)) {
     if (node == NULL) {}
     else {
         inOrder(node->getLeftChild(), func);
         func(node->getContents());
         inOrder(node->getRightChild(), func);
     }
 }
 
 void BSTree::reverseOrder (BSTNode* node, void (*func)(int)) {
     if (node == NULL) {}
     else {
         reverseOrder(node->getRightChild(), func);
         func(node->getContents());
         reverseOrder(node->getLeftChild(), func);
     }
 }