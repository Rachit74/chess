#include <stdio.h>

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

    if (!replacing_piece.type == 0) {
        // manage the logic if a piece if being attacked
        // BHAI LANG
        /*
        bhai agar ek piece ko X,Y se A,B pe move kr rahe hai, aur A,B pe
        koi aur piece hai toh uska logic
        if replacing piece is not equals to EMPTY that is 0 in enum
        */
    } else {
        // Else simply replaces the piece
        swap(&board[initial_pos_x][initial_pos_y], &board[final_pos_x][final_pos_y]);
    }



}

void knightMove(int init_x, int init_y, int end_x, int end_y)
{
    // 
}