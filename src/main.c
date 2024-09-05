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
    
    /*
    Will define a move function for each piece type ?
    */

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
            // print piece type and color
            printf("  %4d[%d]  ", board[i][j].type, board[i][j].color);
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

    // Black Pieces
    board[0][0] = (Piece){ROOK, BLACK, "blackRook1"};
    board[0][1] = (Piece){KNIGHT, BLACK, "blackKnight1"};
    board[0][2] = (Piece){BISHOP, BLACK, "blackBishop1"};
    board[0][3] = (Piece){QUEEN, BLACK, "blackQueen"};
    board[0][4] = (Piece){KING, BLACK, "blackKing"};
    board[0][5] = (Piece){BISHOP, BLACK, "blackBishop2"};
    board[0][6] = (Piece){KNIGHT, BLACK, "blackKnight2"};
    board[0][7] = (Piece){ROOK, BLACK, "blackRook2"};
    // Pawns
    board[1][0] = (Piece){PAWN, BLACK, "blackPawn1"};
    board[1][1] = (Piece){PAWN, BLACK, "blackPawn2"};
    board[1][2] = (Piece){PAWN, BLACK, "blackPawn3"};
    board[1][3] = (Piece){PAWN, BLACK, "blackPawn4"};
    board[1][4] = (Piece){PAWN, BLACK, "blackPawn5"};
    board[1][5] = (Piece){PAWN, BLACK, "blackPawn6"};
    board[1][6] = (Piece){PAWN, BLACK, "blackPawn7"};
    board[1][7] = (Piece){PAWN, BLACK, "blackPawn8"};

    // White Pieces
    board[7][0] = (Piece){ROOK, WHITE, "whiteRook1"};
    board[7][1] = (Piece){KNIGHT, WHITE, "whiteKnight1"};
    board[7][2] = (Piece){BISHOP, WHITE, "whiteBishop1"};
    board[7][3] = (Piece){QUEEN, WHITE, "whiteQueen"};
    board[7][4] = (Piece){KING, WHITE, "whiteKing"};
    board[7][5] = (Piece){BISHOP, WHITE, "whiteBishop2"};
    board[7][6] = (Piece){KNIGHT, WHITE, "whiteKnight2"};
    board[7][7] = (Piece){ROOK, WHITE, "whiteRook2"};
    // Pawns
    board[6][0] = (Piece){PAWN, WHITE, "whitePawn1"};
    board[6][1] = (Piece){PAWN, WHITE, "whtiePawn2"};
    board[6][2] = (Piece){PAWN, WHITE, "whitePawn3"};
    board[6][3] = (Piece){PAWN, WHITE, "whitePawn4"};
    board[6][4] = (Piece){PAWN, WHITE, "whitePawn5"};
    board[6][5] = (Piece){PAWN, WHITE, "whitePawn6"};
    board[6][6] = (Piece){PAWN, WHITE, "whitePawn7"};
    board[6][7] = (Piece){PAWN, WHITE, "whitePawn8"};



    // will have to set other pieces manually
}