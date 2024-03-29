
#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    // お客様に何セント払えばいいのかを聞く
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    //顧客に渡すクウォーターの数を計算する
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("合計:%i\n", coins);
}

int get_cents(void)
{
    int change;
    printf("お釣りは？: ");
    do
    {
        change = get_int("cash: ");
    }
    while (change <= 0);
    return change;
}

int calculate_quarters(int cents)
{
    int n = cents / 25;
    printf("%d円硬貨 : %d枚\n", 25, n);
    return n;
}

int calculate_dimes(int cents)
{
    int n = cents / 10;
    printf("%d円硬貨 : %d枚\n", 10, n);
    return n;
}

int calculate_nickels(int cents)
{
    int n = cents / 5;
    printf("%d円硬貨 : %d枚\n", 5, n);
    return n;
}

int calculate_pennies(int cents)
{
    int n = cents / 1;
    printf("%d円硬貨 : %d枚\n", 1, n);
    return n;
}
