/*
 * Programming Challenge 18 SList Implementation
 *
 * Steve Ross-Byers
 * Date created: 10/25/2015
 * Last date modified: 10/25/2015
 */

#include "SList.h"
#include <sstream>

SList::SList()
: head(NULL), size(0)
{}

SList::~SList(){
    clear();
}

void SList::insertHead(int nodeContents) {
    if (head == NULL){
        head = new SLNode(nodeContents);
    } else {
        SLNode* oldHead = head;
        head = new SLNode(nodeContents);
        head->setNextNode(oldHead);
        oldHead = NULL;
    }
    size++;
}

void SList::removeHead(){
    if (head != NULL){
        if (head->getNextNode() == NULL) {
            delete head;
            head = NULL;
            size--;
        } else {
            SLNode* oldHead = head;
            head = head->getNextNode();
            delete oldHead;
            oldHead = NULL;
            size--;
        }
    }
}

void SList::clear(){
    for (unsigned int i = 0; i < size;){
        removeHead();
    }
}

unsigned int SList::getSize() const{
    return size;
}

string SList::toString() const {
    string listContents;
    stringstream ss;
    if (head != NULL){
        ss << head->getContents();
        if (head->getNextNode() != NULL){
            SLNode* currentNode = head->getNextNode();
            for (unsigned int i = 1; i < size; i++){
                ss << ",";
                ss << currentNode->getContents();
                if (currentNode->getNextNode() != NULL){
                    currentNode = currentNode->getNextNode();
                }
            }
        }
    }
    ss >> listContents;
    return listContents;
}