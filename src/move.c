#include <stdio.h>
#include <stdlib.h>

#include "main.h"

void movePiece(Piece board[8][8]) {
    int initial_pos_x, initial_pos_y, final_pos_x, final_pos_y;

    printf("Enter Cords for the piece to move (x,y):");
    scanf("%d %d", &initial_pos_x, &initial_pos_y);

    printf("Enter the cords you want to move to: ");
    scanf("%d %d", &final_pos_x, &final_pos_y);

    // The current piece that is being moved
    Piece moving_piece = board[initial_pos_x][initial_pos_y];

    // Piece that will be attacked
    Piece replacing_piece = board[final_pos_x][final_pos_y];

    if (replacing_piece.type != 0) {
        // manage the logic if a piece if being attacked
        // BHAI LANG
        /*
        bhai agar ek piece ko X,Y se A,B pe move kr rahe hai, aur A,B pe
        koi aur piece hai toh uska logic
        if replacing piece is not equals to EMPTY that is 0 in enum
        */
    } else {
        // checks the piece type (to be replaced by swtich statement)
        if (moving_piece.type == 4) {
            knightMove(board, &initial_pos_x, &initial_pos_y, &final_pos_x, &final_pos_y);
        };
        // Else simply replaces the piece
        // swap(&board[initial_pos_x][initial_pos_y], &board[final_pos_x][final_pos_y]);
    }



}

/*
knightMove function handles the movement of knight
args: intial x and y pos, final x and y pos.
*/
void knightMove(Piece board[8][8], int *init_x, int *init_y, int *end_x, int *end_y){   
    // abs function returns the absolute value that the piece would have moved, like measuring distance on a number line neglecting the direction
    int dx = abs(*init_x-*end_x);
    int dy = abs(*init_y-*end_y);

    // Knight moves in L shape (2 units in one direction and 1 unit in the perpendicular direction)
    if ((dx == 2 && dy ==1) || (dy == 2 && dx == 1)) {
        printf("Valid Knight Move\n");
        // Swaps the pieces if the move is valid
        swap(&board[*init_x][*init_y], &board[*end_x][*end_y]);
    } else{
        printf("Invalid Knight Move\n");
        // continue the game loop (will implement soon)
    }
    
}