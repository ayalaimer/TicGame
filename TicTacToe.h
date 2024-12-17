#pragma once
#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>
#include <vector>
#include <stdexcept>

class TicTacToe {
private:
    int size;
    int winLength;
    std::vector<std::vector<char>> board;
    char currentPlayer;
    int movesMade;

    bool isValidMove(int row, int col);
    bool checkWinDirection(int row, int col, int dRow, int dCol);
    bool checkWin(int row, int col);

public:
    TicTacToe(int n, int m);
    void printBoard();
    void playTurn(int move);
};

#endif  
