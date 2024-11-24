#include <stdio.h>
#include <iostream>
using namespace std;

void drawBoard(char board[3][3]) {
    cout << "-------------\n";
    for (int i = 0; i < 3; ++i) {
        cout << "| ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}



int main() {
    char board[3][3] = { { ' ', ' ', ' ' },
                         { ' ', ' ', ' ' },
                         { ' ', ' ', ' ' } };

    int row, col;
    char player = 'X';

    for (int turn = 0; turn < 9; ++turn) {
        drawBoard(board);

        while (true) {
            cout << "Player " << player << "'s turn, please enter row and column (0-2): ";
            cin >> row >> col;

            if (board[row][col] != ' ' || row < 0 || row > 2 || col < 0 || col > 2) 
                cout << "Invalid dimensions, please try again.\n";
            else 
                break;
        }

        board[row][col] = player;



        player = (player == 'X') ? 'O' : 'X'; 
            
    }
    return 0;
}