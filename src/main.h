// main.h file for function and types declarations which can be used in both source files and tests files.

#ifndef MAIN_H // checks if main.h is not defined
#define MAIN_H // defines main.h if it is not defined

#include <stdio.h>

// enum for piece type
typedef enum {
	NONE, ROOK, BISHOP, PAWN, KNIGHT, QUEEN, KING
} PieceType;

// enum for piece color
typedef enum {
	EMPTY, // For no piece on the square
	WHITE, // For white piece
	BLACK, // For black piece
} PieceColor;


// piece struct which represents a piece with piece type, piece color and piece identifier.
typedef struct {
	PieceType type;
	PieceColor color;
	/*
	char identification for unique piece identification like
	blackRook1, blackRook2
	whiteKnight1, whiteKnight2
	*/
	char identification[20];
	char face[2];
} Piece;

// Declaring swap function
Piece swap(Piece *a,Piece *b);

// Declaring the printBoard function
void printBoard(Piece board[8][8]);

// initialize board function
// This function is explained in main.c file
void initializeBoard(Piece board[8][8]);

// Move piece function
void movePiece(Piece board[8][8]);

// Piece Move functions below this comment

// Knight Move function
void knightMove(Piece board[8][8], int *init_x, int *init_y, int *end_x, int *end_y);

#endif