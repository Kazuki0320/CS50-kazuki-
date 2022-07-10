#include<stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

// size_t strlen(const char * str);

void get_triangle()
{
    int n = 5;

    for(int i = 1;i < n;i++)
    {
        for(int j = 1;j <= n - i;j++)
        {
            printf(" ");
        }
        for(int j = 1;j <= i * 2 - 1;j++)
        {
            printf("#");
        }
        printf("\n");
    }
}

void get_rectangle()
{
    int n = 3;

        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= n;j++)
            {
                printf("#");
            }
            printf("\n");
        }
}

bool flagNumOrString(char str[20])
{
    for (int i = 0; i < strlen(str); i++)
    {
        if ( '1' <= str[i] && str[i] <= '9') continue;
        return false;
    }
    return true;
}

int main()
{
    char str[20];
    
    /* ↓input test code↓ */
    // scanf("%s", str);
    // printf("scaf:%s\n", str);
    
    // bool n = flagNumOrString(str);
    // printf("bool:%d\n", n);
    // if (n == true) printf("true\n");
    // else if (n == false) printf("false\n");
    /* ↑input test code↑ */
    
    do
    {
        printf("表記に従って、1or2を入力してください。\n三角形の場合:1\n四角形の場合:2\n数値を入力してください: \n");
        scanf("%s", str);
        printf("scaf:%s\n", str);
    }
    while(flagNumOrString(str) == false);
    
    printf("bool:%d\n", flagNumOrString(str));
    int numInt = atoi(str);
    printf("int:%d\n", numInt);

    if(numInt == 1)
    {
        get_triangle();
    }
    else if(numInt == 2)
    {
        get_rectangle();
    }
}