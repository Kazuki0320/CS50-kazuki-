```
#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
// アルファベットの各文字に点数を割り当てる
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);
int one_char_score(char test);

int main(void)
{
    // Get input words from both players
    // 両方のプレイヤーから入力語を取得する
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    // 両方の単語を採点する
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);
    // printf("score1:%d\n", score1);
    // printf("score2:%d\n", score2);

    // TODO: Print the winner
    // TODO: 勝者を表示する
    //1がかつ場合:Player 1 wins!
    //2が勝つ場合:Player 2 wins!
    // :Tie!
    if (score1 > score2) printf("Player 1 wins!\n");
    else if (score1 < score2) printf("Player 2 wins!\n");
    else printf("Tie!\n");

    // test
    // printf("%d\n", one_char_score('a'));// 1
    // printf("%d\n", one_char_score('A'));// 1
    // printf("%d\n", one_char_score('z'));// 10
    // printf("%d\n", one_char_score('!'));// 0

    return 0;
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    // TODO: 文字列のスコアを計算し、返す
    // アルファベットの各文字の点数を POINTS という整数の配列に格納していることに注意。
    int sum = 0;
    int i = 0;
    while (word[i] != '\0') {
        sum = sum + one_char_score(word[i]);
        i++;
    }
    return sum;
}

// TODO: aが入ってきたら１点！のような関数を作ろうとしていた
int one_char_score(char test) {
    char conver_char = tolower(test);
    int index = (int)conver_char - 97;

    if ('a' <= conver_char && conver_char <= 'z') {
        return POINTS[index];
    } else {
        return 0;
    }
}

// POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
// こいつのインデックス番号が欲しい。
// a -> 97 ->こいつを０にしてぇ！

// POINTS[i] <- このiに当たる部分を、aが入ってきたら０にしたい
// POINTS['a']  -> 0になってほしいけど、現状97になっちゃう
// POINTS['b']  -> 1になってほしいけど、現状98になっちゃう
// POINTS['z']  -> 25になってほしいけど、現状122になっちゃう

// POINTS['a']もといPOINTS[97] に対して、なにをすればindex0番がとれるのか。。。！
// abcd
// for (int i = 0; i < 4; i++) {
//     // 配列[97] -> なにをすれば０に...?
//     // 配列[98] -> なにをすれば1に...?
//     // 配列[99] -> なにをすれば2に...?
//     // 配列[100] -> なにをすれば3に...?
// }
```