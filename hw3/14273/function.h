#ifndef FUNCTION_H
#define FUNCTION_H
#include <iostream>
#include <string>
using namespace std;

class Board {
private:
    int** board;
    int size;

public:
    Board(int n) : size(n) {
        board = new int*[size];
        for(int i = 0; i < size; ++i) {
            board[i] = new int[size];
            for(int j = 0; j < size; ++j) {
                board[i][j] = 0;
            }
        }
    }

    ~Board() {
        for(int i = 0; i < size; ++i) {
            delete[] board[i];
        }
        delete[] board;
    }

    void showBoard() {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (!board[i][j]) cout << ".";
                else cout << (board[i][j] == 1 ? "O" : "X");
            }
            cout << "\n";
        }
        cout << "\n";
    }

    /* TODO: Get the size of the board */
    int getSize();

    /* TODO: Set the value of board[i][j] to x */
    void set(int i, int j, int x);

    /* TODO: Get the value of board[i][j] */
    int get(int i, int j);
};

class GomokuGame {
private:
    Board* gomokuBoard;
    int turn; // 1 -> Doraemon, 2 -> DebugCatCapoo

public:
    GomokuGame(int n) {
        gomokuBoard = new Board(n);
        turn = 1;
    }

    ~GomokuGame() {
        delete gomokuBoard;
    }

    void showBoard() {
        gomokuBoard->showBoard();
    }

    void nextRound() {
        turn = (turn == 1 ? 2 : 1);
    }

    /* TODO: Place or remove the piece at the specified location
             Return true if the operation completes successfully */
    bool place(int player, string location);
    bool remove(int player, string location);

    /* TODO: Return 1 if Doraemon wins, 2 if DebugCatCapoo wins,
             or 0 if the game has not yet ended */
    int getWinner();
};

#endif // FUNCTION_H