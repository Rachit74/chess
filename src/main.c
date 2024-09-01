# include <stdio.h>

#include "main.h" // Including the main src header file

int main() {
    // Initialization of the chess board
    int board[8][8] = {
        {2, 2, 2, 2, 2, 2, 2, 2},
        {2, 2, 2, 2, 2, 2, 2, 2},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1}
    };

    // Declare move and position variables
    int move1, move2, pos1, pos2;

    // Print the initial unchanged state of the board
    printBoard(board);

    printf("Which piece you want to move: ");
    scanf("%d %d", &move1, &move2);

    printf("Where to move: ");
    scanf("%d %d", &pos1, &pos2);

    // Move the chess piece to the desired position
    swap(&board[move1][move2], &board[pos1][pos2]);

    // Print the board again with updated chess positions
    printBoard(board);

    return 0;
}

// Function implementations
int swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printBoard(int board[8][8]) {
    printf("Board\n");
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("  %d  ", board[i][j]);
        }
        printf("\n");
    }
}