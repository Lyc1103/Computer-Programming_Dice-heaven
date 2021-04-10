#include <stdio.h>
#include <stdbool.h>
#include "diceheaven.h"

void initDice(struct s_dice *dice);

int main()
{
    //Read variable
    int n = 0, m = 0;
    scanf("%d %d", &n, &m);

    //Initialize the dice array.
    struct s_dice dice[n];
    for (int i = 0; i < n; i += 1)
    {
        initDice(&dice[i]);
    }

    //Call your function to finish operation
    for (int i = 0; i < m; i += 1)
    {
        int a = 0, b = 0;
        scanf("%d %d", &a, &b);
        solve(dice, n, a, b);

        // for (int i = 0; i < n; i += 1)
        // {
        //     if (i != 0)
        //     {
        //         printf(" ");
        //     }
        //     printf("%d", dice[i].totalPoint);
        // }
        // printf("\n");
    }
    //Output answer
    for (int i = 0; i < n; i += 1)
    {
        if (i != 0)
        {
            printf(" ");
        }
        printf("%d", dice[i].totalPoint);
    }
    printf("\n");
}

void initDice(struct s_dice *dice)
{
    dice->front = 4;
    dice->right = 2;
    dice->back = 3;
    dice->left = 5;
    dice->top = 1;
    dice->down = 6;
    dice->totalPoint = 423516;
}