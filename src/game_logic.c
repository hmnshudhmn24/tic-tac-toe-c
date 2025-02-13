#include <stdio.h>
#include "game_logic.h"

void initializeBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard(char board[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

int checkWinner(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return board[i][0];
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return board[0][i];
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return board[0][2];

    return 0;
}

void playGame(char board[3][3]) {
    int turn = 0, row, col;
    char player;
    while (turn < 9) {
        player = (turn % 2 == 0) ? 'X' : 'O';
        printBoard(board);
        printf("Player %c, enter row and column (0-2): ", player);
        scanf("%d %d", &row, &col);
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = player;
            if (checkWinner(board)) {
                printBoard(board);
                printf("Player %c wins!\n", player);
                return;
            }
            turn++;
        } else {
            printf("Invalid move, try again.\n");
        }
    }
    printBoard(board);
    printf("It's a draw!\n");
}
