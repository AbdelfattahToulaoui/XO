#include <stdio.h>
#include "game.h"
#include "ai.h"

void playgame(int players[])
{
    int turn = 0;
    // this is the game board
    // 0: empty; 1: player 1; 2: player 2
    int gameboard[] = {
	0, 0, 0,
	0, 0, 0,
	0, 0, 0
    };
    int win;
    while (!(win = isover(gameboard))) {
	if (players[turn] == 0) {	// the human player
	    int play;
	    showboard(gameboard);
	    // get the player to choose an empty cell
	    do {
		printf("Player %d Your choice: ", turn + 1);
		scanf("%d", &play);
	    }
	    while (play >= 1 && play <= 9 && gameboard[play - 1] != 0);
	    gameboard[play - 1] = turn + 1;
	} else if (players[turn] == 1) {	// the cpu player
	    int c = choose(gameboard, turn);
	    gameboard[c] = turn + 1;
	}
	turn = !turn;
    }
    // print the result of the game
    if (win == 1) {
	printf("Player 1 wins!!\n");
    } else if (win == 2) {
	printf("Player 2 wins!!\n");
    } else if (win == 3) {
	printf("It's a draw!!\n");
    }

    showboard(gameboard);
}

void showboard(int board[])
{
    printf("\n");
    for (int i = 0; i < 9; i++) {
	if (i != 0 && i % 3 == 0) {
	    printf("\n======\n");
	}

	if (board[i] == 0) {
	    printf("%d", i + 1);
	} else if (board[i] == 1) {
	    printf("X");
	} else if (board[i] == 2) {
	    printf("O");
	}

	if (i % 3 != 2) {
	    printf("|");
	}
    }
    printf("\n");
}

int isover(int board[])
{
    // check the diagonals
    if ((board[0] == 1 && board[4] == 1 && board[8] == 1) ||
	(board[2] == 1 && board[4] == 1 && board[6] == 1))
	return 1;
    else if ((board[0] == 2 && board[4] == 2 && board[8] == 2) ||
	     (board[2] == 2 && board[4] == 2 && board[6] == 2))
	return 2;
    // check the line and columns
    for (int i = 0; i < 3; i++) {
	if ((board[i] == 1 && board[3 + i] == 1 && board[6 + i] == 1) ||
	    (board[3 * i] == 1 && board[3 * i + 1] == 1
	     && board[3 * i + 2] == 1)) {
	    return 1;
	} else
	    if ((board[i] == 2 && board[3 + i] == 2 && board[6 + i] == 2)
		|| (board[3 * i] == 2 && board[3 * i + 1] == 2
		    && board[3 * i + 2] == 2)) {
	    return 2;
	}
    }
    // check id the board is full (draw)
    if (isfull(board)) {
	return 3;
    }

    return 0;
}

int isfull(int board[])
{
    for (int i = 0; i < 9; i++)
	if (board[i] == 0)
	    return 0;
    return 1;
}
