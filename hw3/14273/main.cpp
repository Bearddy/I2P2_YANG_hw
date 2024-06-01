#include <iostream>
#include <string>
#include "function.h"
using namespace std;

int main() {
    int boardSize, round = 1;
    while (cin >> boardSize) {
        GomokuGame *game = new GomokuGame(boardSize);
        string player[101], action[101][2];
        int actionSize = 0;
        while (true) {
            cin >> player[actionSize];
            cin >> action[actionSize][0] >> action[actionSize][1];
            if (player[actionSize] == "-") break;
            actionSize++;
        }

        int result = 0;
        for (int i = 0; i < actionSize; ++i) {
            bool success = true;
            if (player[i] == "Doraemon") {
                success = game->place(1, action[i][0]);
                success = game->place(1, action[i][1]);
            } else if (player[i] == "DebugCatCapoo") {
                success = game->place(2, action[i][0]);
                success = game->remove(2, action[i][1]);
            }
            if (success) {
                // cout << player[i] << ": " << action[i][0] << "/" << action[i][1] << "\n";
                // game->showBoard();
                result = game->getWinner();
                if (result) break;
                game->nextRound();
            }
        }

        if (result) {
            cout << "Round #" << round++ << " winner: ";
            cout << (result == 1 ? "Doraemon" : "DebugCatCapoo") << "!\n";
        } else {
            cout << "Round #" << round++ << ": Tie.\n";
        }
        game->showBoard();

        delete game;
    }
}