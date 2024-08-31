#include<stdio.h>

// making fuctions which are going to be used in this code

    void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){



// Initialization of the chess board

        int board [8][8] = {
            {2, 2, 2, 2, 2, 2, 2, 2},
            {2, 2, 2, 2, 2, 2, 2, 2},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {1, 1, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1, 1, 1, 1}
        };


// Taking moves from the user

        int move1, move2, pos1, pos2;


        printf("Which piece you want to move: ");
        scanf("%d %d", &move1, &move2);

        printf("Where to move: ");
        scanf("%d %d", &pos1, &pos2);

// moving the chess piece at the desired position        

        switch (board[pos1][pos2])
        {
        case 1:
            swap(&board[move1][move2], &board[pos1][pos2]);
            board[move1][move2] = 0;
            break;
        
        default:
            swap(&board[move1][move2], &board[pos1][pos2]);
            break;
        }
        

// printing the boards again with updated chess positions

        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                printf("    %d    ", board[i][j]);
            }
            printf("\n");
        }
        
    return 0;
}
