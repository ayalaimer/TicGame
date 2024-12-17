#include "TicTacToe.h"

int main() {
    try {
        TicTacToe game(4, 4);
        game.printBoard();

        game.playTurn(1);
        game.playTurn(2);
        game.playTurn(5);
        game.playTurn(6);
        game.playTurn(9);
        game.playTurn(10);
        game.playTurn(13);
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
        return 1;
    }
    return 0;
}
