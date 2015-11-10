/*
 * Programming Challenge 22 SList Header Only Template Class
 *
 * Steve Ross-Byers
 * Date created: 11/8/2015
 * Last date modified: 11/8/2015
 */

#pragma once

#include <string>
#include <sstream>
#include "SLNode.hpp"

template <class T>

class SList {
    private:
    
        /*
         * @member head points to the first node in a singly-linked list
         */
        SLNode<T>* head;
        
        /*
         * @member size is a count of the number of nodes in the list
         */
        unsigned int size;
        
    public:
    
        /*
         * SList default Constructor
         */
        SList()
        : head(NULL), size(0)
        {}
        
        /*
         * SList Destructor calls the clear function to clear the list and free all memory
         */
        ~SList()
        {clear();}
        
        /*
         * Function to create an SLNode and attatch it to the beginning of the list
         * @param nodeContents assigns this value to the node that is created
         */
        void insertHead(T nodeContents)
        {
            SLNode<T>* oldHead = head;
            head = new SLNode<T>(nodeContents);
            head->setNextNode(oldHead);
            size++;
        }
        
        /*
         * Function to create an SLNode and attatch it to the end of the list
         * @param nodeContents assigns this value to the node that is created
         */
        void insertTail(T nodeContents)
        {
            if (head == NULL) {
                insertHead(nodeContents);
            } else {
                SLNode<T>* newTail = new SLNode<T>(nodeContents);
                if (head->getNextNode() == NULL) {
                    head->setNextNode(newTail);
                } else {
                    SLNode<T>* oldTail = head->getNextNode();
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
        
        /*
         * Function to remove the first (head) node of the list
         */
        void removeHead()
        {
            if (head != NULL){
                if (head->getNextNode() == NULL) {
                    if (head != NULL) {
                        delete head;
                        head = NULL;
                    }
                } else {
                    SLNode<T>* oldHead = head;
                    head = head->getNextNode();
                    if (oldHead != NULL) {
                        delete oldHead;
                        oldHead = NULL;
                    }
                }
                size--;
            }
        }
        
        /*
         * Function to remove the last (tail) node of the list
         */
        void removeTail()
        {
            if (head != NULL){
                if (head->getNextNode() == NULL) {
                    removeHead();
                } else {
                    SLNode<T>* i = head;
                    SLNode<T>* j = NULL;
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
        
        /*
         * Function that inserts a node with contents in ascending order
         * @param contents assigns this value to the contents of the inserted node
         */
        void insert(T contents)
        {
            if (head == NULL) {
                insertHead(contents);
            } else {
                size++;
                SLNode<T>* newNode = new SLNode<T>(contents);
                if (head->getContents() > contents){
                    SLNode<T>* oldHead = head;
                    head = newNode;
                    head->setNextNode(oldHead);
                    oldHead = NULL;
                } else {
                    if (head->getNextNode() == NULL) {
                        head->setNextNode(newNode);
                    } else {
                        SLNode<T>* nodeMark = head->getNextNode();
                        SLNode<T>* lagMark = NULL;
                        for (unsigned int i = 0; i < size; i++) {
                            if (nodeMark->getContents() < contents && nodeMark->getNextNode() != NULL) {
                                lagMark = nodeMark;
                                nodeMark = nodeMark->getNextNode();
                            }
                        }
                        if ((lagMark == NULL) && (nodeMark->getNextNode() != NULL || nodeMark->getContents() > contents)){
                            head->setNextNode(newNode);
                            newNode->setNextNode(nodeMark);
                        } else if (nodeMark->getNextNode() == NULL && contents > nodeMark->getContents()) {
                            nodeMark->setNextNode(newNode);
                        } else {
                            lagMark->setNextNode(newNode);
                            newNode->setNextNode(nodeMark);
                        }
                        nodeMark = NULL;
                        lagMark = NULL;
                    }
                }
                newNode = NULL;
            }
        }
                
        /*
         * Function that removes a node with specific contents from the list
         * @param contents the first node in the list with this value as contents is removed
         */
        bool removeFirst(T contents)
        {
            SLNode<T>* toRemove = NULL;
            SLNode<T>* nodeMark = head;
            SLNode<T>* lagMark = NULL;
            for (unsigned int i = 0; i < size; i++){
                if (nodeMark->getContents() != contents && nodeMark->getNextNode() != NULL){
                    lagMark = nodeMark;
                    nodeMark = nodeMark->getNextNode();
                } else if (nodeMark->getContents() == contents){
                    toRemove = nodeMark;
                }
            }
            if (toRemove == NULL) {
                return false;
            }
            if (lagMark == NULL){
                removeHead();
            } else if (toRemove->getNextNode() == NULL) {
                removeTail();
            } else {
                size--;
                nodeMark = nodeMark->getNextNode();
                lagMark->setNextNode(nodeMark);
                delete toRemove;
            }
            toRemove = NULL;
            nodeMark = NULL;
            lagMark = NULL;
            return true;
        }
        
        /*
         * Function that removes all nodes with specific contents from the list
         * @param contents all of the nodes in the list with this value as contents are removed
         */
        bool removeAll(T target)
        {
            bool valueDeleted = false;
            for (unsigned int i = 0; i < size; i++) {
                if (removeFirst(target) == true) {
                    valueDeleted = true;
                }
            }
            return valueDeleted;
        }
        
        
        /*
         * Function that clears the list of all nodes and frees up all associated memory
         */
        void clear()
        {
            for (unsigned int i = 0; i < size;){
                removeTail();
            }
        }
        
        /*
         * Size getter
         * @return a T containing the value of the length of the list
         */
        unsigned int getSize() const
        {
            return size;
        }
        
        /*
         * Function that concatenates the contents of the entire list into a string
         * @return a string containing the contents of the list separated by , and ending with ;
         */
        string toString() const
        {
            string listContents;
            stringstream ss;
            if (head != NULL){
                ss << head->getContents();
                if (head->getNextNode() != NULL){
                    SLNode<T>* currentNode = head->getNextNode();
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
};