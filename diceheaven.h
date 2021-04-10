// #pragma once

#include <stdbool.h>

//Define the dice structure
struct s_dice
{
    int front;
    int right;
    int back;
    int left;
    int top;
    int down;
    int totalPoint;
};

//Optional function
void sortDice(struct s_dice dice[], int n, int from, int to, bool isAscending);
void rotateDice(struct s_dice *dice, char direction[]);
int calculate_totalPoints(struct s_dice dice);

//Main function would call this function.
void solve(struct s_dice dice[], int n, int a, int b);