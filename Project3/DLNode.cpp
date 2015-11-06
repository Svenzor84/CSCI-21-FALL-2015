/*
 * Programming Project 3 DLNode Implementation
 *
 * Steve Ross-Byers
 * Date created: 11/4/2015
 * Last date modified: 11/4/2015
 */

 #include "DLNode.h"
 
 DLNode::DLNode() : next(NULL), previous(NULL), contents(0) {
 }
 
 DLNode::DLNode(int customContents) : next(NULL), previous(NULL), contents(customContents){
 }
 
 DLNode::~DLNode(){
     next = NULL;
 }
 
 void DLNode::setContents(int newContents){
     contents = newContents;
 }
 
 int DLNode::getContents() const{
     return contents;
 }
 
 void DLNode::setNext(DLNode* newNext){
     next = newNext;
 }
 
 DLNode* DLNode::getNext () const{
     return next;
 }
 
 void DLNode::setPrevious(DLNode* newPrevious){
     previous = newPrevious;
 }
 
 DLNode* DLNode::getPrevious () const{
     return previous;
 }