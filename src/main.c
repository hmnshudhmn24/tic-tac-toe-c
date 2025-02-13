#include <stdio.h>
#include "game_logic.h"

int main() {
    char board[3][3];
    initializeBoard(board);
    playGame(board);
    return 0;
}
