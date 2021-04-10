# Dice Heaven!!

> Author : Ya Chen<br>
> Date : 2021 / 4 / 10<br>
> List :
>
> > <a href = "#description">Description</a><br> &emsp;|-- <a href = "#total">Total Points</a><br> &emsp;|-- <a href = "#diceheaven.h">diceheaven.h</a><br> &emsp;|-- <a href = "#main.c">main.c</a><br><a href = "#input">Input</a><br><a href = "#output">Output</a><br><a href = "#examples">Examples</a>

---

<br>
<div id = "description">

## Description

Arrange n dice in a row, and then each dice have 1 point top, 4 points front, 2 points right (shown in the left figure below) initially, and Its development drawing is shown in the right figure below.

<img src = "https://i.imgur.com/3St4YFY.png">

</div>
<br>
<div id = "total">

### Total Points

A dice total points are defined as:

<img src = "https://i.imgur.com/aMN3kdo.png">

For example, a dice its initial status is 4 points on front, 2 points right, 3 points backward, 5 points left, 1 point top, and 6 points downward. Therefore, we calculate its total points as:

```c
                        Total Points = 423516
```

</div>

### Next,

there are `m` operations, and each operation contains two integer `a` and `b`.

- `a`, `b` <b>&isin; N</b>, swapping the dice position between number `a` and `b`.
- As `b` equal to `-1`, the dice number `a` rotates forward.
- As `b` equal to `-2`, the dice number `a` rotates right.
- As `b` equal to `-3`, sorting the dice between number `a` to the last ascending by total points.
- As bb equal to -4, sorting the dice between the first to the number `a` descending by total points.

Print the total points between number `0` to `n-1` after the `m` times operations.

Here provide two files named `diceheaven.h` and `main.c` below.<br>
`diceheaven.h` is a header file and `main.c` is a reference. We would call your function in the main, output the answer.

<div id = "diceheaven.h">

### diceheaven.h

```c
#pragma once

#include <stdbool.h>

//Define the dice structure
struct s_dice{
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
```

</div>
<div id = "main.c">

### main.c

```c
#include <stdio.h>
#include <stdbool.h>
#include "diceheaven.h"

int main(){
    //Read variable
    int n = 0 , m = 0;
    scanf("%d %d", &n, &m);

    //Initialize the dice array.
    struct s_dice dice[n];
    for (int i = 0 ; i < n ; i += 1){
        initDice(&dice[i]);
    }

    //Call your function to finish operation
    for (int i = 0 ; i < m ; i += 1){
        int a = 0 , b = 0;
        scanf("%d %d", &a, &b);
        solve(dice, n, a, b);
    }

    //Output answer
    for (int i = 0 ; i < n ; i += 1){
        if (i != 0){
            printf(" ");
        }
        printf("%d", dice[i].totalPoint);
    }
    printf("\n");
}

void initDice(struct s_dice *dice){
    dice->front = 4;
    dice->right = 2;
    dice->back  = 3;
    dice->left = 5;
    dice->top = 1;
    dice->down = 6;
    dice->totalPoint = 423516;
}
```

</div>

Therefore,you should have a file named `diceheaven.c`, and must complete the <b>solve</b> function, others function is optional, could implement your own function and call in the solve function.

### diceheaven.c

```c
//You can include the header file in need
#include "diceheaven.h"

//Optional function
void sortDice(struct s_dice dice[], int n, int from, int to, bool isAscending){

}

//Optional function
void rotateDice(struct s_dice *dice, char direction[]){

}

//Optional function
int calculate_totalPoints(struct s_dice dice){

}

//Main function would call this function.
void solve(struct s_dice dice[], int n, int a, int b){

}

//DONT contain the main function...
//Or you would get "compiler error".
```

<br>
<br>
<div id = "input">

## Input

- The 1st line of the input contains two numbers, `n` and `m`. Two consecutive numbers separated with space.
- The following `m` lines are the operation. Each line contains two integers `a`, `b`.

</div>
<br>
<br>
<div id = "output">

## Output

Print the `n` total points in order, and the consecutive numbers separated with space, ending with a newline character.

> Don’t deal with the output.

</div>
<br>
<br>
<div id = "examples">

## Examples

### Input 1

```
1 2
0 -2
0 -1
```

### Output 1

```
512634
```

<br>

### Input 2

```
3 3
1 -1
2 -2
2 0
```

### Output 2

```
413652 126534 423516
```

<br>

### Input 3

```
3 4
1 -1
2 -2
2 0
0 -3
```

### Output 3

```
126534 413652 423516
```

<br>

### Input 4

```
3 4
1 -1
2 -2
0 1
1 -3
```

### Output 4

```
126534 413652 423516
```

</div>
