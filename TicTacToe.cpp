#include "TicTacToe.h"

TicTacToe::TicTacToe(int n, int m)
    : size(n), winLength(m), board(n, std::vector<char>(n, ' ')), currentPlayer('X'), movesMade(0) {
    if (size < winLength)
        throw std::invalid_argument("Size must be greater than or equal to winLength");
}

void TicTacToe::printBoard() {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << (board[i][j] == ' ' ? std::to_string(i * size + j + 1) : std::string(1, board[i][j]));
            if (j < size - 1) std::cout << " | ";
        }
        std::cout << "\n";
        if (i < size - 1) {
            for (int k = 0; k < size; ++k) std::cout << "----";
            std::cout << "\n";
        }
    }
}

bool TicTacToe::isValidMove(int row, int col) {
    return row >= 0 && row < size && col >= 0 && col < size && board[row][col] == ' ';
}

bool TicTacToe::checkWinDirection(int row, int col, int dRow, int dCol) {
    char player = board[row][col];
    int count = 0;
    for (int i = 0; i < winLength; ++i) {
        int newRow = row + i * dRow;
        int newCol = col + i * dCol;
        if (newRow >= 0 && newRow < size && newCol >= 0 && newCol < size && board[newRow][newCol] == player)
            count++;
        else
            break;
    }
    return count == winLength;
}

bool TicTacToe::checkWin(int row, int col) {
    return checkWinDirection(row, col, 0, 1) ||
        checkWinDirection(row, col, 1, 0) ||
        checkWinDirection(row, col, 1, 1) ||
        checkWinDirection(row, col, 1, -1);
}

void TicTacToe::playTurn(int move) {
    int row = (move - 1) / size;
    int col = (move - 1) % size;

    if (!isValidMove(row, col))
        throw std::invalid_argument("Invalid move!");

    board[row][col] = currentPlayer;
    movesMade++;

    printBoard();

    if (checkWin(row, col)) {
        std::cout << "Player " << currentPlayer << " wins!\n";
        exit(0);
    }
    if (movesMade == size * size) {
        std::cout << "It's a draw!\n";
        exit(0);
    }

    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}
