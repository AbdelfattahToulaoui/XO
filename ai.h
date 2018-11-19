#ifndef AI_H
#define AI_H

int choose(int board[], int turn);
double calculate(int board[], int turn, int mustwin);
int isover(int board[]);
int isfull(int board[]);
void cparray(int* arr1, int *arr2);

#endif
