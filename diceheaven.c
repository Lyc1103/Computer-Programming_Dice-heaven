//You can include the header file in need
#include <stdio.h>
#include "diceheaven.h"

//Optional function
void sortDice(struct s_dice dice[], int n, int from, int to, bool isAscending)
{
    struct s_dice tmp;
    if (isAscending == 1)
    {
        for (int i = from; i <= to; i++)
        {
            for (int j = i + 1; j <= to; j++)
            {
                if (dice[i].totalPoint > dice[j].totalPoint)
                {
                    tmp.front = dice[i].front;
                    tmp.right = dice[i].right;
                    tmp.back = dice[i].back;
                    tmp.left = dice[i].left;
                    tmp.top = dice[i].top;
                    tmp.down = dice[i].down;
                    tmp.totalPoint = dice[i].totalPoint;
                    dice[i].front = dice[j].front;
                    dice[i].right = dice[j].right;
                    dice[i].back = dice[j].back;
                    dice[i].left = dice[j].left;
                    dice[i].top = dice[j].top;
                    dice[i].down = dice[j].down;
                    dice[i].totalPoint = dice[j].totalPoint;
                    dice[j].front = tmp.front;
                    dice[j].right = tmp.right;
                    dice[j].back = tmp.back;
                    dice[j].left = tmp.left;
                    dice[j].top = tmp.top;
                    dice[j].down = tmp.down;
                    dice[j].totalPoint = tmp.totalPoint;
                }
            }
        }
    }
    else if (isAscending == 0)
    {
        for (int i = from; i <= to; i++)
        {
            for (int j = i + 1; j <= to; j++)
            {
                if (dice[i].totalPoint < dice[j].totalPoint)
                {
                    tmp.front = dice[i].front;
                    tmp.right = dice[i].right;
                    tmp.back = dice[i].back;
                    tmp.left = dice[i].left;
                    tmp.top = dice[i].top;
                    tmp.down = dice[i].down;
                    tmp.totalPoint = dice[i].totalPoint;
                    dice[i].front = dice[j].front;
                    dice[i].right = dice[j].right;
                    dice[i].back = dice[j].back;
                    dice[i].left = dice[j].left;
                    dice[i].top = dice[j].top;
                    dice[i].down = dice[j].down;
                    dice[i].totalPoint = dice[j].totalPoint;
                    dice[j].front = tmp.front;
                    dice[j].right = tmp.right;
                    dice[j].back = tmp.back;
                    dice[j].left = tmp.left;
                    dice[j].top = tmp.top;
                    dice[j].down = tmp.down;
                    dice[j].totalPoint = tmp.totalPoint;
                }
            }
        }
    }
}

//Optional function
void rotateDice(struct s_dice *dice, char direction[])
{
    int tmp;
    if (direction[0] == '1')
    {
        tmp = dice->front;
        dice->front = dice->top;
        dice->top = dice->back;
        dice->back = dice->down;
        dice->down = tmp;
    }
    else if (direction[0] == '2')
    {
        tmp = dice->top;
        dice->top = dice->left;
        dice->left = dice->down;
        dice->down = dice->right;
        dice->right = tmp;
    }
    return;
}

//Optional function
int calculate_totalPoints(struct s_dice dice)
{
    return dice.front * 100000 + dice.right * 10000 + dice.back * 1000 + dice.left * 100 + dice.top * 10 + dice.down;
}

//Main function would call this function.
void solve(struct s_dice dice[], int n, int a, int b)
{
    char direction[21] = {0};
    if (b == -1)
    {
        direction[0] = '1';
        rotateDice(&dice[a], direction);
        dice[a].totalPoint = calculate_totalPoints(dice[a]);
    }
    else if (b == -2)
    {
        direction[0] = '2';
        rotateDice(&dice[a], direction);
        dice[a].totalPoint = calculate_totalPoints(dice[a]);
    }
    else if (b == -3)
    {
        sortDice(dice, n, a, n - 1, 1);
    }
    else if (b == -4)
    {
        sortDice(dice, n, 0, a, 0);
    }
    else
    {
        // printf("here\n");
        // printf("dice[%d] = %d\n", a, dice[a].totalPoint);
        // printf("dice[%d] = %d\n", b, dice[b].totalPoint);
        struct s_dice tmp;
        tmp.front = dice[a].front;
        tmp.right = dice[a].right;
        tmp.back = dice[a].back;
        tmp.left = dice[a].left;
        tmp.top = dice[a].top;
        tmp.down = dice[a].down;
        tmp.totalPoint = dice[a].totalPoint;
        // printf("dice[%d] = %d\n", b, dice[b].totalPoint);
        dice[a].front = dice[b].front;
        dice[a].right = dice[b].right;
        dice[a].back = dice[b].back;
        dice[a].left = dice[b].left;
        dice[a].top = dice[b].top;
        dice[a].down = dice[b].down;
        dice[a].totalPoint = dice[b].totalPoint;
        dice[b].front = tmp.front;
        dice[b].right = tmp.right;
        dice[b].back = tmp.back;
        dice[b].left = tmp.left;
        dice[b].top = tmp.top;
        dice[b].down = tmp.down;
        dice[b].totalPoint = tmp.totalPoint;
    }
}

//DONT contain the main function...
//Or you would get "compiler error".