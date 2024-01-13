#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void sum(int a, int b)
{
    printf("%d\n", a + b);
}
void mult(int a, int b)
{
    printf("%d\n", a * b);
}
void divv(int a, int b)
{
    printf("%d\n", a / b);
}
void (*select_option())(int, int)
{
    int option = 0;
    printf("%e\n", 10.3459);
    printf("Select option:\n");
    printf("\t1) add\n");
    printf("\t2) multiply\n");
    printf("\t3) divide\n");
    printf("Enter: ");
    scanf("%d", &option);
    switch (option)
    {
    case 1:
        return sum;
        break;
    case 2:
        return mult;
        break;
    case 3:
        return divv;
        break;
    default:
        return NULL;
    }
}

typedef struct
{
    char name[10];
    int age;
    char role[10];
} user;

int main(int argc, char const *argv[])
{
    void (*operation)(int, int) = select_option();
    operation(34, 56);
    user vlad = {"Vlad",
                 62,
                 "admin"};
    user *u = &vlad;
    printf("%s\n", u->name);
    char *s = malloc(sizeof(char) * 20);
    strcpy(s, "Hello World.");
    // s = "Hello world.";
    for (size_t i = 0; i < strlen(s); i++)
    {
        printf("%c ", s[i]);
    }

    /*    int seconds = 0;
       int d = 6;
       printf("Seconds: ");
       scanf("%d", &seconds);
       while (seconds > 0)
       {
           printf("\r%02d ", seconds);
           fflush(stdout);
           clock_t stop = clock() + CLOCKS_PER_SEC;
           while (clock() < stop)
           {
           }
           seconds--;
       }
    */
    free(s);
    return 0;
}
