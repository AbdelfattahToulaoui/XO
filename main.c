#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ai.h"
#include "game.h"

int isfull(int board[]);
void printhelp(char *name);
void playgame(int players[]);
void showboard(int board[]);
int isover(int board[]);
int isfull(int board[]);

int main(int argc, char *argv[])
{
    // this is the player types (0 for human and 1 for cpu)
    // default is human vs cpu
    int players[] = { 0, 1 };
    // parse the command line arguments
    for (int i = 1; i < argc; i++) {
	if (strcmp(argv[i], "--help") == 0 || strcmp(argv[i], "-h") == 0) {
	    printhelp(argv[0]);
	    return 0;
	} else if (strcmp(argv[i], "--cpu") == 0
		   || strcmp(argv[i], "-c") == 0) {
	    if (i + 1 < argc
		&& (strcmp(argv[i + 1], "1") == 0
		    || strcmp(argv[i + 1], "2") == 0)) {
		if (strcmp(argv[i + 1], "1") == 0) {
		    players[0] = 1;
		} else if (strcmp(argv[i + 1], "2") == 0) {
		    players[1] = 1;
		}
	    } else {
		printf("Invalid argument %s: Must either be '1' or '2'\n",
		       argv[i + 1]);
	    }
	    i++;
	} else if (strcmp(argv[i], "--player") == 0
		   || strcmp(argv[i], "-p") == 0) {
	    if (i + 1 < argc
		&& (strcmp(argv[i + 1], "1") == 0
		    || strcmp(argv[i + 1], "2") == 0)) {
		if (strcmp(argv[i + 1], "1")) {
		    players[0] = 0;
		} else if (strcmp(argv[i + 1], "2") == 0) {
		    players[1] = 0;
		}
	    } else {
		printf("Invalid argument %s: Must either be '1' or '2'\n",
		       argv[i + 1]);
	    }
	    i++;
	} else {
	    printf("Unknown option '%s'\n", argv[i]);
	    printhelp(argv[0]);
	    return 1;
	}
    }
    if (players[0] == 1 && players[1] == 1) {
	// we can't start a game with two cpu players
	printf("At least one player has to be human!\n");
    } else {
	playgame(players);
    }

}

// prints the help message
void printhelp(char *name)
{
    printf("Usage: %s [Option1] [Option2] ...\n", name);
    printf("-h, --help              prints this message\n");
    printf("-p, --player <player>   set <player> mode to human player\n");
    printf("-c, --cpu <player>      set <player> mode to cpu player\n");
    printf("                        the default is human(1) vs cpu(2)\n");
}
