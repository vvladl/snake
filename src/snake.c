#include "snake.h"

void fill_field(int r, int c, int field[][col])
{
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
        {
            if (i == 0 || i == r - 1)
                field[i][j] = '#';
            else
            {
                if (j == 0 || j == c - 2)
                    field[i][j] = '#';
                else
                    field[i][j] = ' ';
            }
            if (j == c - 1)
                field[i][j] = '\n';
        }
}

void draw_field(int r, int c, int field[][col])
{
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
        {
            if (field[i][j] == '#')
                printf("%s%c%s", TC_YEL, field[i][j], TC_NRM);
            else if (field[i][j] == '@')
                printf("%s%c%s", TC_RED, field[i][j], TC_NRM);
            else if (field[i][j] == 'O')
                printf("%s%c%s", TC_GRN, field[i][j], TC_NRM);
            else
                printf("%c", field[i][j]);
        }
}

void draw_snake(snake *snake, int field[][col])
{
    for (int i = 0; i < snake->len; i++)
    {
        int r = (snake->body[i]).x;
        int c = (snake->body[i]).y;
        field[r][c] = '@';
    }
}
void move_snake(point dp, snake *snake)
{
    for (int i = snake->len; i > 0; --i)
    {
        (snake->body[i]).x = (snake->body[i - 1]).x;
        (snake->body[i]).y = (snake->body[i - 1]).y;
    }
    snake->body[0].x += dp.x;
    if (snake->body[0].x == 0)
        snake->body[0].x = row - 2;
    else if (snake->body[0].x == row - 1)
        snake->body[0].x = 1;
    snake->body[0].y += dp.y;
    if (snake->body[0].y == 0)
        snake->body[0].y = col - 3;
    else if (snake->body[0].y == col - 2)
        snake->body[0].y = 1;
}
point draw_rabbit(int field[][col])
{
    point rabbit;
    srand((unsigned)time(NULL));
    rabbit.x = rand() % (row - 2) + 1;
    rabbit.y = rand() % (col - 3) + 1;
    // printf("(%d, %d)", rabbit.x, rabbit.y);
    field[rabbit.x][rabbit.y] = 'O';
    return rabbit;
}
// int collision(snake *sn)
// {
//     point head = sn->body[0];
//     if (head.x > 1 && head.x < (row - 2) && head.y > 1 && head.y < (col - 1))
//         return 0;
//     else
//         return 1;
// }