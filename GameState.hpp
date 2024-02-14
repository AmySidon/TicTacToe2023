

#ifndef GAMESTATE_H
#define GAMESTATE_H
#include <iostream>
#include "MoveStack.hpp"

class GameState {
private:
    char boardState[3][3];
    MoveStack moveStack;
public:
    GameState();
    int getCurrentPlayer();
    int addMove(Move move);
    bool undoLast();
    void displayBoardState(std::ostream& out); // Prints the board state to the "out" stream.
    bool checkLastPlayerWin();
};


#endif //GAMESTATE_H
