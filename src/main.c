# include <stdio.h>
# include <string.h>

#include "main.h" // Including the main src header file

/*
Currently the initializeBoard function initilizez the board and sets each piece object to None and that is printed out
When moving the piece the board will not change because each piece is same currently
Futher explained in the comment above initializeBoard function
*/

int main() {
    // Initialization of the chess board
    Piece board[8][8];

    initializeBoard(board);

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
Piece swap(Piece *a, Piece *b) {
    Piece temp = *a;
    *a = *b;
    *b = temp;
}


/*
The printBoard function will not be able to work now becauase we are trying to print a piece type object
*/
void printBoard(Piece board[8][8]) {
    printf("Board\n");
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("  %4d  ", board[i][j].type);
        }
        printf("\n");
    }
}


/*
initializeBoard function is used to set a type, color and identification to each Piece Object on the board
currently it sets it to type NONE, color EMPTY, identification Empty
for the pieces that we want on the board we will need to manually set their Piece object values like

board[0][0].type = ROOK, board[0][0].color = BLACK, board[0][0].identification = "blackRook1"
*/
void initializeBoard(Piece board[8][8]) {

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j].type = NONE;
            board[i][j].color = EMPTY;
            strcpy(board[i][j].identification, "Empty");
        }
    } 

    // board[0][0] = (Piece){ROOK, BLACK, "blackRook1"};
    // will have to set other pieces manually
}