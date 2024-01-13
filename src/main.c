#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "snake.h"
#include <unistd.h>
#include <pthread.h>

int main(int argc, char const *argv[])
{

    snake sn = {{{8, 8}, {8, 9}}, 2};
    point dp = {0, 1};
    int field[row][col];
    int ch = 'w';

    // tc_echo_off();
    do
    {
        fill_field(row, col, field);
        system("clear");
        draw_snake(&sn, field);
        draw_rabbit(field);
        draw_field(row, col, field);
        int ch = getchar();
        switch (ch)
        {
        case 'i':
            dp.x = -1;
            dp.y = 0;
            move_snake(dp, &sn);

            break;
        case 'k':
            dp.x = 1;
            dp.y = 0;
            move_snake(dp, &sn);

            break;
        case 'j':
            dp.x = 0;
            dp.y = -1;
            move_snake(dp, &sn);

            break;
        case 'l':
            dp.x = 0;
            dp.y = 1;
            move_snake(dp, &sn);

            break;
        case 'x':
            return 0;
        }
        sleep(1);
    } while (ch != 'x');
    // tc_echo_on();
    return 0;
}
