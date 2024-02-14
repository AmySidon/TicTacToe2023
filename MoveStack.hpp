

#ifndef MOVESTACK_H
#define MOVESTACK_H

struct Move{
    int x;
    int y;
    Move* next;
    Move(){ x=0; y=0; }
    Move(int a, int b) {x=a; y=b;}
};


class MoveStack{  // "All members of a class are private by default unless stated otherwise"
private:
    struct Node{
        // define variables used to create stack
        Move move;
        Node *next;
    };
    Node *head;
    
public:
    MoveStack(); //initialize
    ~MoveStack();
    int getSize(); //returns size of stack   "get is used to access private member variables"
    Move top();
    void push(Move move);
    void pop();
};

#endif //MOVESTACK_H
