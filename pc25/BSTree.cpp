/*
 * Programming Challenge 25 BSTree Implementation
 *
 * Steve Ross-Byers
 * Date created: 11/17/2015
 * Last date modified: 11/17/2015
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