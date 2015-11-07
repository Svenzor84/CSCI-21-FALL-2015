/*
 * Programming Project 3 DLList Implementation
 *
 * Steve Ross-Byers
 * Date created: 11/4/2015
 * Last date modified: 11/6/2015
 */

#include "DLList.h"
#include <sstream>

DLList::DLList()
: head(NULL), tail(NULL), count(0)
{}

DLList::~DLList() {
    clear();
}

void DLList::pushFront(int newContents) {
    DLNode* oldHead = head;
    head = new DLNode(newContents);
    head->setNext(oldHead);
    count++;
    if (head->getNext() == NULL) {
        tail = head;
    } else {
        head->getNext()->setPrevious(head);
    }
}

void DLList::pushBack(int newContents) {
    if (head == NULL) {
        pushFront(newContents);
    } else {
        DLNode* newTail = new DLNode(newContents);
        if (head->getNext() == NULL) {
            head->setNext(newTail);
            newTail->setPrevious(head);
        } else {
            DLNode* oldTail = head->getNext();
            for (unsigned int i = 1; i < count; i++){
                if (oldTail-> getNext() != NULL){
                    oldTail = oldTail->getNext();
                }
            }
            oldTail->setNext(newTail);
            newTail->setPrevious(oldTail);
            oldTail = NULL;
        }
        tail = newTail;
        newTail = NULL;
        count++;
    }
}

void DLList::popFront() {
    if (head != NULL){
        if (head->getNext() == NULL) {
            delete head;
            head = NULL;
            tail = NULL;
        } else {
            DLNode* oldHead = head;
            head = head->getNext();
            head->setPrevious(NULL);
            if (oldHead != NULL) {
                delete oldHead;
                oldHead = NULL;
            }
        }
        count--;
    }
}

void DLList::popBack() {
    if (head != NULL){
        if (head->getNext() == NULL) {
            popFront();
        } else {
            DLNode* i = head;
            DLNode* j = NULL;
            while (i->getNext() != NULL) {
                j = i;
                i = i->getNext();
            }
            if (i != NULL) {
                delete i;
                j->setNext(NULL);
                tail = j;
            }
            count--;
        }
    }
}

void DLList::insert(int newContents) {
    if (head == NULL) {
        pushFront(newContents);
    } else {
        count++;
        DLNode* newNode = new DLNode(newContents);
        if (head->getContents() > newContents){
            DLNode* oldHead = head;
            head = newNode;
            head->setNext(oldHead);
            oldHead->setPrevious(head);
            oldHead = NULL;
        } else {
            if (head->getNext() == NULL) {
                head->setNext(newNode);
                newNode->setPrevious(head);
                tail = newNode;
            } else {
                DLNode* nodeMark = head->getNext();
                DLNode* lagMark = NULL;
                for (unsigned int i = 1; i < count; i++) {
                    if (nodeMark->getContents() < newContents && nodeMark->getNext() != NULL) {
                        lagMark = nodeMark;
                        nodeMark = nodeMark->getNext();
                    }
                }
                if ((lagMark == NULL) && (nodeMark->getNext() != NULL || nodeMark->getContents() > newContents)) {
                    head->setNext(newNode);
                    newNode->setNext(nodeMark);
                    nodeMark->setPrevious(newNode);
                    newNode->setPrevious(head);
                    
                } else if (nodeMark->getNext() == NULL && newContents > nodeMark->getContents()) {
                    nodeMark->setNext(newNode);
                    newNode->setPrevious(nodeMark);
                    tail = newNode;
                } else {
                    lagMark->setNext(newNode);
                    newNode->setNext(nodeMark);
                    nodeMark->setPrevious(newNode);
                    newNode->setPrevious(lagMark);
                }
                nodeMark = NULL;
                lagMark = NULL;
            }
        }
        newNode = NULL;
    }
}

bool DLList::removeFirst(int target) {
    DLNode* toRemove = NULL;
    DLNode* nodeMark = head;
    DLNode* lagMark = NULL;
    for (unsigned int i = 0; i < count; i++){
        if (nodeMark->getContents() != target && nodeMark->getNext() != NULL){
            lagMark = nodeMark;
            nodeMark = nodeMark->getNext();
        } else if (nodeMark->getContents() == target){
            toRemove = nodeMark;
        }
    }
    if (toRemove == NULL) {
        return false;
    }
    if (lagMark == NULL){
        popFront();
    } else if (toRemove->getNext() == NULL) {
        popBack();
    } else {
        count--;
        nodeMark = nodeMark->getNext();
        lagMark->setNext(nodeMark);
        nodeMark->setPrevious(lagMark);
        delete toRemove;
    }
    toRemove = NULL;
    nodeMark = NULL;
    lagMark = NULL;
    return true;
}

bool DLList::removeAll (int target) {
    bool valueDeleted = false;
    for (unsigned int i = 0; i < count; i++) {
        if (removeFirst(target) == true) {
            valueDeleted = true;
        }
    }
    return valueDeleted;
}

void DLList::clear() {
    for (unsigned int i = 0; i < count;){
        popBack();
    }
}

unsigned int DLList::getSize() const {
    return count;
}

int DLList::getFront() const {
    if (head == NULL) {
        throw string("LIST EMPTY");
    } else {
        return head->getContents();
    }
}

int DLList::getBack() const {
    if (tail == NULL) {
        throw string("LIST EMPTY");
    } else {
        return tail->getContents();
    }
}

string DLList::toString() const {
    string listContents;
    stringstream ss;
    if (head != NULL){
        ss << head->getContents();
        if (head->getNext() != NULL){
            DLNode* currentNode = head->getNext();
            for (unsigned int i = 1; i < count; i++){
                ss << ",";
                ss << currentNode->getContents();
                if (currentNode->getNext() != NULL){
                    currentNode = currentNode->getNext();
                }
            }
        }
    }
    ss >> listContents;
    return listContents;
}

bool DLList::get(int target) const {
    DLNode* nodeMark = head;
    bool targetFound = false;
    for (unsigned int i = 0; i < count; i++) {
        if (nodeMark->getContents() == target){
            targetFound = true;
        }
        if (nodeMark->getNext() != NULL) {
            nodeMark = nodeMark->getNext();
        }
    }
    nodeMark = NULL;
    return targetFound;
}

ostream& operator<< (ostream& out, const DLList& src) {
    out << src.toString();
    return out;
}