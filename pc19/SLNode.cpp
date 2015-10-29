/*
 * Programming Challenge 19 SLNode Implementation
 *
 * Steve Ross-Byers
 * Date created: 10/25/2015
 * Last date modified: 10/25/2015
 */

 #include "SLNode.h"
 
 SLNode::SLNode() : nextNode(NULL), contents(0) {
 }
 
 SLNode::SLNode(int customContents) : nextNode(NULL), contents(customContents){
 }
 
 SLNode::~SLNode(){
     nextNode = NULL;
 }
 
 void SLNode::setContents(int newContents){
     contents = newContents;
 }
 
 int SLNode::getContents() const{
     return contents;
 }
 
 void SLNode::setNextNode(SLNode* nextSLNode){
     nextNode = nextSLNode;
 }
 
 SLNode* SLNode::getNextNode () const{
     return nextNode;
 }