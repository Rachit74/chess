# include <stdio.h>


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
} Piece;

int main() {
	char board[8][8] = {
		{2,2,2,2,2,2,2,2},
		{2,2,2,2,2,2,2,2},
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0},
		{1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1},
	};
	for (int i=0; i<8;i++){
		for (int j=0; j<8; j++) {
			printf("  %d  ", board[i][j]);
		}
		printf("\n");
	};
};