/*
 * Programming Challenge 25 BSTNode Implementation
 *
 * Steve Ross-Byers
 * Date created: 11/17/2015
 * Last date modified: 11/17/2015
 */
 
 #include "BSTNode.h"
 #include <cstdlib>
 
 BSTNode::BSTNode()
 : leftChild(NULL), rightChild(NULL), contents(0)
 {}
 
 BSTNode::BSTNode(int newContents)
 : leftChild(NULL), rightChild(NULL), contents(newContents)
 {}
 
 BSTNode::~BSTNode() {
    leftChild = NULL;
    rightChild = NULL;
 }
 
 void BSTNode::setContents (int newContents) {
    contents = newContents;
 }
 
 int BSTNode::getContents () const {
    return contents;
 }
 
 int& BSTNode::getContents () {
    return contents;
 }
 
 void BSTNode::setLeftChild (BSTNode* newLeftChild) {
    leftChild = newLeftChild;
 }
 
 void BSTNode::setRightChild (BSTNode* newRightChild) {
    rightChild = newRightChild;
 }
 
 BSTNode* BSTNode::getLeftChild () const {
    return leftChild;
 }
 
 BSTNode*& BSTNode::getLeftChild () {
    return leftChild;
 }
 
 BSTNode* BSTNode::getRightChild () const {
    return rightChild;
 }
 
 BSTNode*& BSTNode::getRightChild () {
    return rightChild;
 }