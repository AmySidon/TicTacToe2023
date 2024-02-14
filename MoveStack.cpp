// Filename MoveStack.cpp
// Author: Amy Sidon
// Date: November 29, 2023
// Assignment Number: 4
// CS 2308 
// MoveStack A regular stack that stores instances of the Move structure.
// A Move records the coordinates of the 'x' or 'o' token placed on the game board.
// All past moves are stored here. The stack is required in order to be able to undo moves.


#include <cassert>

using namespace std;
#include "MoveStack.hpp"

MoveStack::MoveStack() {
    head = nullptr;
}

MoveStack::~MoveStack() {
    Node* current = head;
    while (current != nullptr){
        Node* temp = current->next; //current.next();
        delete current;
        current = temp;
    }
}

//****************************************************
// Member function getsize returns a count of the    *
// number of elements on the stack.                  *
//****************************************************
int MoveStack::getSize() {
        Node *temp = head;
        int count = 0;
        while(temp!= nullptr) {
            count++;
            temp = temp-> next;
        }
        return count;
 }

//****************************************************
// Member function top returns the value at the top  *
// of the stack (does not remove it).                *
//****************************************************
Move MoveStack::top() {
    assert(head != nullptr);
    return head->move;
}
//*************************************************
// Member function push pushes the argument onto  *
// the stack.                                     *
// move: the Move item to be pushed               *
//*************************************************
void MoveStack::push(Move move) {
    Node *temp = new Node;
    temp->move.x = move.x;
    temp->move.y = move.y;
    temp->next = nullptr; //(*temp).next
    
    if(head == nullptr) {
        head = temp;
    }
    else {
        temp->next = head;
        head = temp;
    }

};
//****************************************************
// Member function pop removes the value at the top  *
// of the stack, but returns nothing.                *
//****************************************************
void MoveStack::pop() {
    Node *temp;
    temp = head;
    head = head->next;
    delete temp;
}
