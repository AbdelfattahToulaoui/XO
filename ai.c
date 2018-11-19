#include <stdlib.h>
#include <time.h>
#include "game.h"
#include "ai.h"
#include "arraylist.h"

// choose the best action
int choose(int board[], int turn)
{
    double g[9];
    for (int i = 0; i < 9; i++) {
	if (board[i] == 0) {
	    // cloning the board array so that the original is kept unchanged
	    int board1[9];
	    for (int i = 0; i < 9; i++)
		    board1[i] = board[i];
	    board1[i] = turn + 1;
	    g[i] = calculate(board1, !turn, turn);
	}
    }
    // setting max to the theoretical minimum of the function
    // which is: all cells are empty and all lose instantly
    double max = -9;
    // creating a list of cells with the highest winnig probability
    arraylist *a = newarraylist();

    for (int i = 0; i < 9; i++) {
	if (board[i] != 0)
	    continue;

	if (g[i] > max) {
	    max = g[i];
	    clear(a);		// disposing of the previous cells
	}
	if (g[i] == max)
	    append(a, i);	// add the cell to the list
    }
    // pick a random cell out of the list
    // they are all equal so it doesn't matter which
    srand(time(NULL));
    int s = a->inti[rand() % a->size];
    // avoid memory leaks
    clear(a);
    free(a);
    return s;
}

/*
    A recursive function that finds the optimal path to victory
    by calculating the number of winnig and losing scenarios
    each empty cell provides (and taking into account the number of moves
    it takes).
*/
double calculate(int board[], int turn, int mustwin)
{
    {
	// if the game is over we give this path a value based on
	// the winnig player
	int win = isover(board);
	if (win == (mustwin + 1)) {
	    return 1;
	} else if (win == (!mustwin + 1)) {
	    return -1;
	} else if (win == 3) {
	    return 0;
	}
    }
    // this variable will store the number representing
    // the winnig probability of the current cell
    double winfunc = 0;
    for (int i = 0; i < 9; i++) {
	if (board[i] == 0) {
	    // cloning the board array so that the original is kept unchanged
	    int board1[9];
	    for (int i = 0; i < 9; i++)
		    board1[i] = board[i];
	    board1[i] = turn + 1;
	    // give each layer a lower importance thant the one before (divide by 9)
	    // this way we get the shortest path to victory
	    winfunc += calculate(board1, !turn, mustwin) / 9;
	}
    }
    return winfunc;
}
