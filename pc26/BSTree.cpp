/*
 * Programming Challenge 26 BSTree Implementation
 *
 * Steve Ross-Byers
 * Date created: 11/22/2015
 * Last date modified: 11/24/2015
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
	
 void BSTree::inOrder(ostream& os) {
     inOrder(root, os);
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
	        BSTNode* toRemove = node;
	        if (node->getLeftChild() == NULL) {
	            node = node->getRightChild();
	            if (root == toRemove) {
	                root = node;
	            }
	        } else if (node->getRightChild() == NULL) {
	            node = node->getLeftChild();
	            if (root == toRemove) {
	                root = node;
	            }
	        } else {
	            toRemove = node->getLeftChild();
	            if (toRemove->getRightChild() == NULL) {
	                node->setContents(toRemove->getContents());
	                node->setLeftChild(toRemove->getLeftChild());
	            } else {
	                BSTNode* parent = NULL;
	                do {
	                    parent = toRemove;
	                    toRemove = toRemove->getRightChild();
	                } while (toRemove->getRightChild() != NULL);
	                node->setContents(toRemove->getContents());
	                parent->setRightChild(toRemove->getLeftChild());
	            }
	        }
	        delete toRemove;
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
	
 void BSTree::inOrder(BSTNode* node, ostream& os) {
     if (node == NULL) {}
     else {
         inOrder(node->getLeftChild(), os);
         os << node->getContents() << " ";
         inOrder(node->getRightChild(), os);
     }
 }