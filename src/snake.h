#ifndef _SNAKE_H
#define _SNAKE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tc.h"

#define row 20
#define col 20

typedef struct
{
    int x;
    int y;
} point;
typedef struct
{
    point body[30];
    int len;
} snake;

void fill_field(int, int, int[][col]);
void draw_field(int, int, int[][col]);
void draw_snake(snake *, int[][col]);
void move_snake(point, snake *);
point draw_rabbit(int[][col]);

// int collision(point);

#endif // _SNAKE_H
