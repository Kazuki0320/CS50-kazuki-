#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <limits.h>
#include <stdlib.h>

int check_text(string text);
string encrypt(int conversion, string text);

int main(int argc, string argv[])
{
    /* 例外処理 exception handling*/
    if (argc == 2)//最初の例外処理 farst exception handling
    {
        int check = check_text(argv[1]);
        if (check == -1)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //数字へ変換 conversion & second exception handling
    unsigned long tmp = atoi(argv[1]);
    int conversion = atoi(argv[1]);
    if (tmp > 2147483647 && conversion < 0)
    {
        printf("Key must be a no-negative integer.\n");
        return 1;
    }

    /*メインシステム main system*/
    //暗号の平文入力
    string text = get_string("plaintext:  ");

    //暗号化と出力 encrypt&output
    string secret_message = encrypt(conversion, text);
    printf("ciphertext: %s\n", secret_message);
    return 0;
}

int check_text(string text)
{
    for (int i = 0; text[i] != '\0'; i++)
    {
        //全参照
        if (isdigit(text[i]))
        {
            continue ;
        }
        else
        {
            return -1;
        }
    }
    return 0;
}

string encrypt(int conversion, string text)
{
    //使えるようにするDeformation
    //A 65  Z 90  差分　25
    int deform = conversion;
    for (int i = 0; deform >= 26; i++)
    {
        deform -= 26;
    }


    //全参照 ASCIIコード32～126までOK
    ////小文字は小文字内　大文字は大文字内ループで変換
    for (int i = 0; text[i] != '\0'; i++)
    {
        if ('A' <= text[i] && text[i] <= 'Z')
        {
            if (text[i] + deform >= 91)
            {
                text[i] -= 26;
                text[i] += deform;
            }
            else
            {
                text[i] += deform;
            }
        }
        else if ('a' <= text[i] && text[i] <= 'z')
        {
            if (text[i] + deform >= 122)
            {
                text[i] -= 26;
                text[i] += deform;
            }
            else
            {
                text[i] += deform;
            }
        }
    }
    return text;
}