/*
 * Programming Challenge 19 SList Implementation
 *
 * Steve Ross-Byers
 * Date created: 10/25/2015
 * Last date modified: 10/25/2015
 */

#include "SList.h"
#include <sstream>

//for debugging
#include <iostream>

SList::SList()
: head(NULL), size(0)
{}

SList::~SList() {
    clear();
}

void SList::insertHead(int nodeContents) {
    SLNode* oldHead = head;
    head = new SLNode(nodeContents);
    head->setNextNode(oldHead);
    size++;
}

void SList::insertTail(int nodeContents) {
    if (head == NULL) {
        insertHead(nodeContents);
    } else {
        SLNode* newTail = new SLNode(nodeContents);
        if (head->getNextNode() == NULL) {
            head->setNextNode(newTail);
        } else {
            SLNode* oldTail = head->getNextNode();
            for (unsigned int i = 1; i < size; i++){
                if (oldTail-> getNextNode() != NULL){
                    oldTail = oldTail->getNextNode();
                }
            }
            oldTail->setNextNode(newTail);
            oldTail = NULL;
        }
        newTail = NULL;
        size++;
    }
}

void SList::removeHead() {
    if (head != NULL){
        if (head->getNextNode() == NULL) {
            if (head != NULL) {
                delete head;
                head = NULL;
            }
        } else {
            SLNode* oldHead = head;
            head = head->getNextNode();
            if (oldHead != NULL) {
                delete oldHead;
                oldHead = NULL;
            }
        }
        size--;
    }
}

void SList::removeTail() {
    if (head != NULL){
        if (head->getNextNode() == NULL) {
            removeHead();
        } else {
            SLNode* i = head;
            SLNode* j = NULL;
            while (i->getNextNode() != NULL) {
                j = i;
                i = i->getNextNode();
            }
            if (i != NULL) {
                delete i;
                j->setNextNode(NULL);
            }
            size--;
        }
    }
}

void SList::clear() {
    for (unsigned int i = 0; i < size;){
        removeTail();
    }
}

unsigned int SList::getSize() const {
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