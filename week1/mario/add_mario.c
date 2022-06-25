#include <cs50.h>
#include <stdio.h>

void printOnelineBlock(int space, int asterisk);

int main(void)
{
    int n = 8;
    do
    {
        n = get_int("Size: ");
    }
    while (n <= 0 || 9 <= n);

    for (int i = 1; i <= n; i++)
    {
        printOnelineBlock( n - i, i);
        printf("\n");
    }
}

void printOnelineBlock(int space, int asterisk){
    for (int i = 0; i < space; i++){
        printf(" ");
    }
    for (int i = 0; i < asterisk; i++){
        printf("*");
    }
}