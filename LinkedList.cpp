#include "LinkedList.hpp"
#include <stdlib.h>
#include <iostream>

Node* LinkedList::get(int index)
{
    Node* currNode = head;
    for(int i = 0; i < index; i++)
    {
        currNode = currNode->getNextNode();
    } 
    return currNode;
}

void LinkedList::swap(int index1, int index2)
{
    int smaller = index1;
    int larger = index2; 

    if(larger < smaller)
    {
        smaller = index2; 
        larger = index1;
    }

    Node* smallerNode = this->get(smaller);
    Node* largerNode = this->get(larger);

    if(smaller != 0 && larger != this->count-1)
    {
        smallerNode->getPrevNode()->setNextNode(largerNode);
        smallerNode->setNextNode(largerNode->getNextNode());
        largerNode->setNextNode(smallerNode);
        smallerNode->getNextNode()->setPrevNode(smallerNode);
        largerNode->setPrevNode(smallerNode->getPrevNode());
        smallerNode->setPrevNode(largerNode);

    }
    else if(smaller == 0 || larger == this->count-1)
    {
        if(smaller == 0 && larger == this->count - 1)
        {
            this->head = largerNode;
            largerNode->setPrevNode(smallerNode->getPrevNode());
            smallerNode->setNextNode(largerNode->getNextNode());
            largerNode->setNextNode(smallerNode);
            smallerNode->setPrevNode(largerNode);
            this->tail = smallerNode;
        }
        if(smaller == 0)
        {
            this->head = largerNode;
            largerNode->setPrevNode(smallerNode->getPrevNode());
            smallerNode->setNextNode(largerNode->getNextNode());
            largerNode->setNextNode(smallerNode);
            smallerNode->setPrevNode(largerNode);
            smallerNode->getNextNode()->setPrevNode(smallerNode);
        }
        if(larger == this->count-1)
        {
            smallerNode->getPrevNode()->setNextNode(largerNode);
            largerNode->setPrevNode(smallerNode->getPrevNode());
            smallerNode->setNextNode(largerNode->getNextNode());
            largerNode->setNextNode(smallerNode);
            smallerNode->setPrevNode(largerNode);
            this->tail = smallerNode;
        }
    }
}
LinkedList::LinkedList()
{
    this->count = 0;
    this->head = NULL;
    this->tail = NULL;
}

void LinkedList::addEnd(Card* c)
{
    Node* n = new Node(c);
    if(count == 0)
    {
        this->head = n;
        this->tail = n;
    }
    else
    {
        n->setPrevNode(this->tail);
        this->tail->setNextNode(n);
        this->tail = n;
    }
    this->count++;
}

void LinkedList::display()
{
    Node* currNode = this->head;
    for(int i = 0; i < this->count; i++)
    {
        currNode->getPayload()->display();
        currNode = currNode->getNextNode();
    }
}

int LinkedList::getCount()
{
    return this->count;
}

void LinkedList::insertionSortOnDefense()
{
    int theFollower;
    for(int currStart = 1; currStart < this->count; currStart++)
    {
        theFollower = currStart;
        while(theFollower > 0 && this->get(theFollower)->getPayload()->getHealth() < this->get(theFollower - 1)->getPayload()->getHealth())
        {
            this->swap(theFollower, theFollower -1);
            theFollower--;
        }
    }
}