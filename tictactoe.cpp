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

bool hasWon(char board[3][3], int player) {
    // checks row n column
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true; 
    }

    // checks diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;  
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;  

    return false;
}

int main() {
    char board[3][3] = { { ' ', ' ', ' ' },
                         { ' ', ' ', ' ' },
                         { ' ', ' ', ' ' } };

    int row, col;
    int turn = 0;
    char player = 'X';

    for (; turn < 9; ++turn) {
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

        if (hasWon(board, player)) {
            drawBoard(board);
            cout << "Player " << player << " has won!\n";
            break;
        }

        player = (player == 'X') ? 'O' : 'X'; 
    }

    drawBoard(board);

    if (turn == 9 && !hasWon(board, 'X') && !hasWon(board, 'O'))
        cout << "DRAW\n";

    return 0;
}