#include "function.h"
#include <iostream>
/* === TODO_01 === */
// Constructor that initializes the board with specified rows and columns.
Board::Board(int r, int c) : rows(r), cols(c), gameTurn(0){
    board = new char*[rows];
    for (int i = 0; i < rows; i++) {
        board[i] = new char[cols];
        for (int j = 0; j < cols; j++) {
            board[i][j] = '.';
        }
    }

}

/* === TODO_02 === */
// Copy constructor to create a deep copy of an existing board.
Board::Board(const Board& b) : rows(b.rows), cols(b.cols), gameTurn(b.gameTurn){
    board = new char*[rows];
    for (int i = 0; i < rows; i++) {
        board[i] = new char[cols];
        for (int j = 0; j < cols; j++) {
            board[i][j] = b.board[i][j];
        }
    }
}

/* === TODO_03 === */
// Subscript operator to access a row of the board directly,
// gives access to the character at the specified index.
char* Board::operator[](int idx){
    return board[idx];
}

/* === TODO_04 === */
// Destructor to clean up dynamically allocated memory for the board.
Board::~Board(){

    
    for (int i = 0; i < rows; i++) {
        delete[] board[i];
    }
    delete[] board;


}

/* === TODO_05 === */
// Provide ostream support for printing the board.
ostream& operator<<(ostream& output, const Board& b){
    for (int i = 0; i < b.rows; i++) {
        for (int j = 0; j < b.cols; j++) {
            output << b.board[i][j];
        }
        if(i < b.rows - 1) output << endl;
    }
    return output;
}

 /* === TODO_06 === */
// Constructor to initialize a TicTacToeBoard with the board size of 3x3.
TicTacToeBoard::TicTacToeBoard(): Board(TIC_TAC_TOW_ROWS, TIC_TAC_TOW_COLS){ 
}

/* === TODO_07 === */
// Applies a move to the board, 
// alternating between players ( gameTurn = nextPlayer(); ).
TicTacToeBoard& TicTacToeBoard::operator+=(const Move& m){
    TicTacToeBoard& b = *this;
    b[m.move[0] - '0'][m.move[2] - '0'] = (gameTurn == 0) ? 'O' : 'X';;
    gameTurn = nextPlayer();
    return *this;

}

/* === TODO_08 === */
// Checks rows, columns, and diagonals 
// to determine if the TicTacToe game is won.
bool TicTacToeBoard::isGameWon() {
    TicTacToeBoard& b = *this;
    for (int i = 0; i < 3; i++) {
        if (b[i][0] == b[i][1] && b[i][1] == b[i][2] && b[i][0] != '.') return true;
    }
    for (int i = 0; i < 3; i++) {
        if (b[0][i] == b[1][i] && b[1][i] == b[2][i] && b[0][i] != '.') return true;
    }
    if (b[0][0] == b[1][1] && b[1][1] == b[2][2] && b[0][0] != '.') return true;
    if (b[0][2] == b[1][1] && b[1][1] == b[2][0] && b[0][2] != '.') return true;
    return false;
}

/* === TODO_09 === */
// Constructor to initialize a ConnectFourBoard with the board size of 6x7.
ConnectFourBoard::ConnectFourBoard() : Board(CONNECT_FOUR_ROWS, CONNECT_FOUR_COLS){ }

/* === TODO_10 === */
// Applies a move to the board, 
// alternating between players ( gameTurn = nextPlayer(); ).
ConnectFourBoard& ConnectFourBoard::operator+=(const Move& m) {
    ConnectFourBoard& b = *this;
    for (int i = 6 - 1; i >= 0; i--) {
        if (b[i][m.move[1] - '0'] == '.') {
            b[i][m.move[1] - '0'] = (gameTurn == 0) ? 'W' : 'B';;
            break;
        }
    }
    gameTurn = nextPlayer();
    return *this;

}

/* === TODO_11 === */
// Checks for four consecutive pieces horizontally, vertically, and diagonally
// to determine if the ConnectFour game is won.
bool ConnectFourBoard::isGameWon() {

    ConnectFourBoard& b = *this;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            if (b[i][j] == '.') continue;
            if (j + 3 < 7 && b[i][j] == b[i][j+1] && b[i][j+1] == b[i][j+2] && b[i][j+2] == b[i][j+3]) return true;
            if (i + 3 < 6 && b[i][j] == b[i+1][j] && b[i+1][j] == b[i+2][j] && b[i+2][j] == b[i+3][j]) return true;
            if (i + 3 < 6 && j + 3 < 7 && b[i][j] == b[i+1][j+1] && b[i+1][j+1] == b[i+2][j+2] && b[i+2][j+2] == b[i+3][j+3]) return true;
            if (i + 3 < 6 && j - 3 >= 0 && b[i][j] == b[i+1][j-1] && b[i+1][j-1] == b[i+2][j-2] && b[i+2][j-2] == b[i+3][j-3]) return true;
        }
    }
    return false;
}