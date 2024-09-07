#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "main.h" // Including the main src header file

/*
Each block on the board has been initalized with a piece type and pieces with colors
main function runs the game loop
currently only knight move function is written in move.c
*/

int main() {


    // Initialization of the chess board
    Piece board[8][8];

    initializeBoard(board);

    int gameEnded = false;

    // print the initial unchanged state of the board
    printBoard(board);

    // Game Loop
    while (!gameEnded)
    {
        movePiece(board);

        // Print the board again with updated chess positions
        printBoard(board);
    }
    

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
            printf("  %c%c[%d](%d,%d)  ", board[i][j].face[0], board[i][j].face[1], board[i][j].color, i,j);
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
            strcpy(board[i][j].face, "  ");
        }
    }

    // Black Pieces
    board[0][0] = (Piece){ROOK, BLACK, "blackRook1", "RB"};
    board[0][1] = (Piece){KNIGHT, BLACK, "blackKnight1", "NB"};
    board[0][2] = (Piece){BISHOP, BLACK, "blackBishop1", "BB"};
    board[0][3] = (Piece){QUEEN, BLACK, "blackQueen", "BQ"};
    board[0][4] = (Piece){KING, BLACK, "blackKing", "BK"};
    board[0][5] = (Piece){BISHOP, BLACK, "blackBishop2", "BB"};
    board[0][6] = (Piece){KNIGHT, BLACK, "blackKnight2", "NB"};
    board[0][7] = (Piece){ROOK, BLACK, "blackRook2", "RB"};

    // Pawns
    board[1][0] = (Piece){PAWN, BLACK, "blackPawn1", "PB"};
    board[1][1] = (Piece){PAWN, BLACK, "blackPawn2", "PB"};
    board[1][2] = (Piece){PAWN, BLACK, "blackPawn3", "PB"};
    board[1][3] = (Piece){PAWN, BLACK, "blackPawn4", "PB"};
    board[1][4] = (Piece){PAWN, BLACK, "blackPawn5", "PB"};
    board[1][5] = (Piece){PAWN, BLACK, "blackPawn6", "PB"};
    board[1][6] = (Piece){PAWN, BLACK, "blackPawn7", "PB"};
    board[1][7] = (Piece){PAWN, BLACK, "blackPawn8", "PB"};

    // White Pieces
    board[7][0] = (Piece){ROOK, WHITE, "whiteRook1", "RW"};
    board[7][1] = (Piece){KNIGHT, WHITE, "whiteKnight1", "NW"};
    board[7][2] = (Piece){BISHOP, WHITE, "whiteBishop1", "BW"};
    board[7][3] = (Piece){QUEEN, WHITE, "whiteQueen", "QW"};
    board[7][4] = (Piece){KING, WHITE, "whiteKing", "KW"};
    board[7][5] = (Piece){BISHOP, WHITE, "whiteBishop2", "BW"};
    board[7][6] = (Piece){KNIGHT, WHITE, "whiteKnight2", "NW"};
    board[7][7] = (Piece){ROOK, WHITE, "whiteRook2", "RW"};

    // Pawns
    board[6][0] = (Piece){PAWN, WHITE, "whitePawn1", "PW"};
    board[6][1] = (Piece){PAWN, WHITE, "whitePawn2", "PW"};
    board[6][2] = (Piece){PAWN, WHITE, "whitePawn3", "PW"};
    board[6][3] = (Piece){PAWN, WHITE, "whitePawn4", "PW"};
    board[6][4] = (Piece){PAWN, WHITE, "whitePawn5", "PW"};
    board[6][5] = (Piece){PAWN, WHITE, "whitePawn6", "PW"};
    board[6][6] = (Piece){PAWN, WHITE, "whitePawn7", "PW"};
    board[6][7] = (Piece){PAWN, WHITE, "whitePawn8", "PW"};


    // will have to set other pieces manually
}