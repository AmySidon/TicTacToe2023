// File Name: GameState.cpp
//
// Author: Amy Sidon
// Date: November 29, 2023
// Assignment Number: 4
// CS 2308 
// Instructor: Xiaomin Li
//
// GameState represents the current state of a tic tac toe game that allows
// players to undo the most recent of their opponents moves.
// It maintains the current game board and a stack of the currently active
// moves in the game.  It can record a move, and undo a move, and it
// can return the number current player (0 or 1), and also determine
// if the player who made the most recent move has won the game.
#include <iostream>
#include "GameState.hpp"
using namespace std;
//***********************************************************
// checkLastPlayerWin: determines if the player with the most
// recent move has won the tic tac toe game
// returns true if the last move has won the game, otherwise false.
//***********************************************************

bool GameState::checkLastPlayerWin() {
    char targetSymbol = getCurrentPlayer() ? 'x' : 'o';
    int sumHorizontal, sumVertical;
    for (int i = 0; i < 3; ++i){
        sumHorizontal = 0;
        sumVertical = 0;
        for (int j = 0; j < 3; ++j){
            sumHorizontal += boardState[i][j] == targetSymbol;
            sumVertical += boardState[j][i] == targetSymbol;
        }
        if (sumHorizontal == 3 || sumVertical == 3)
            return true;
    }
    int sumDiagonal1 = 0, sumDiagonal2 = 0;
    for (int i = 0; i < 3; ++i){
        sumDiagonal1 += boardState[i][i] == targetSymbol;
        sumDiagonal2 += boardState[i][2 - i] == targetSymbol;
    }
    if (sumDiagonal1 == 3 || sumDiagonal2 == 3)
        return true;

    return false;
}

//***********************************************************
// constructor: initializes game board to all '_' underscores.
//***********************************************************
GameState::GameState() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            boardState[i][j] = '_';
        }
    }
}

//***********************************************************
// getCurrentPlayer returns the player that has to make the next turn.
// returns 0 for player 0 and 1 for player 1
//***********************************************************
int GameState::getCurrentPlayer() {
   if (moveStack.getSize() % 2 == 0) {
       return 0; // Player 0
   }
   else {
       return 1; // Player 1
   }
}

//***********************************************************
// addMove: given the move of the current player, it updates
// the state of the board and stack of the past moves.
// returns -1 if the turn is invalid (the target position is not empty)
// returns 0 if the move was successful and all positions are filled
// returns 1 if the move was successful and there are moves available,
//***********************************************************
int GameState::addMove(Move move) {
    // check if the target position is not empty
    if (boardState[move.x][move.y] != '_') {
        return -1; // Invalid 
    }

    char symbol;
    if (getCurrentPlayer() == 0) {
        symbol = 'x';
    } else {
        symbol = 'o';
    }
    boardState[move.x][move.y] = symbol;

    // Add the move to the move stack
    moveStack.push(move);
    if (checkLastPlayerWin()) {
        return 2; // Win
    }
    
    if (moveStack.getSize() == 9) {
        return 0; // Draw
    }

    return 1; // No more moves available and move was successful
}

//***********************************************************
// undoLast: Undoes the last turn by changing the board state to the
//   previous one and removing the last move from the stack.
// returns true if the move was removed, false if there are
//   no moves to undo.
//***********************************************************
bool GameState::undoLast() {
    // Check if there are moves to undo
    if (moveStack.getSize() == 0) {
        return false; // There are no moves to undo
    }

    // Remove the last move from the move stack
    Move lastMove = moveStack.top();
    moveStack.pop();
    
    boardState[lastMove.x][lastMove.y] = '_';
    return true; // Successful undo
}

//***********************************************************
// displayBoardState: Prints the board state to the "out" stream.
//***********************************************************
void GameState::displayBoardState(std::ostream& out) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            out << boardState[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}



