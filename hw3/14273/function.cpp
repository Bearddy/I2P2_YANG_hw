#include <iostream>
#include <string>
#include "function.h"
#define to_int(c) (c - '0')

using namespace std;

/* TODO: Get the size of the board */
int Board::getSize(){
    return this->size;
}

/* TODO: Set the value of board[i][j] to x */
void Board::set(int i, int j, int x){
    this->board[i][j] = x;
}

/* TODO: Get the value of board[i][j] */
int Board::get(int i, int j){
    return this->board[i][j];
}


bool GomokuGame::place(int player, string location){
    if(player == this->turn){
        this->gomokuBoard->set(to_int(location[0]), to_int(location[1]), player);
        //cout << location[0] - '0' << " " << location[1] - '0' << endl;
        return true;
    }
    return false;
}

bool GomokuGame::remove(int player, string location){
    if(player == this->turn){
        this->gomokuBoard->set(to_int(location[0]), to_int(location[1]), 0);
        //cout << location[0] - '0' << " " << location[1] - '0' << endl;
        return true;
    }
    return false;
}

/* TODO: Return 1 if Doraemon wins, 2 if DebugCatCapoo wins,
         or 0 if the game has not yet ended */
int GomokuGame::getWinner(){
    int size = this->gomokuBoard->getSize();
    int board[size][size];
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            board[i][j] = this->gomokuBoard->get(i, j);
        }
    }
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++) {
            if (board[i][j] == 1) {
                if (i + 4 < size && board[i + 1][j] == 1 && board[i + 2][j] == 1 && board[i + 3][j] == 1 && board[i + 4][j] == 1) return 1;
                if (j + 4 < size && board[i][j + 1] == 1 && board[i][j + 2] == 1 && board[i][j + 3] == 1 && board[i][j + 4] == 1) return 1;
            }
            if (board[i][j] == 2) {
                if (i + 4 < size && board[i + 1][j] == 2 && board[i + 2][j] == 2 && board[i + 3][j] == 2 && board[i + 4][j] == 2) return 2;
                if (j + 4 < size && board[i][j + 1] == 2 && board[i][j + 2] == 2 && board[i][j + 3] == 2 && board[i][j + 4] == 2) return 2;
            }
        }
    }
    return 0;


}