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

    drawBoard(board);
}