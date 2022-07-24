#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);
int conversion_score(char word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie\n");
    }
    return 0;
}

int compute_score(string word)
{
    int sum = 0;
    int i = 0;
    // TODO: Compute and return score for string
    /*Todo:
    ・受け取った文字がヌル文字まで動く処理を書く
    ・文字の合計点を算出
    ・受け取った文字をスコアに変換するために、別の関数を作成する
    */
    while (word[i] != '\0')
    {
        sum = sum + conversion_score(word[i]);
        i++;
    }
    return sum;
}

int conversion_score(char word)
{
    /*Todo:
    ・受け取った文字の要素数をPOINTS[n]と合致するような処理を書く
    ・a=97,z=122であり、97から９７を引くと０になるため、POINTSのインデックス番号[0]と一致する
    ・大文字を受け取った時に、小文字と同じ点数になるような処理を書く
    ・特殊文字を弾く処理を書く→POINTS[0~25]以外は弾く
    */
    if ('a' <= word && word <= 'z')
    {
        return POINTS[(word - 97)];
    }
    else if ('A' <= word && word <= 'Z')
    {
        return POINTS[(word - 65)];
    }
    else
    {
        return 0;
    }
}
/*
【考えるべき事】
・islower()の関数を使う
・アルファベットの数とPOINTSの数は同じなので、処理としては要素数での比較を行いたい
→一致した場合、POINTS分を足していく○
→受け取った文字列が「何点なのか」を知りたい○
→受け取った文字列が、小文字でも大文字でも同じ点数
→受け取った文字列がpoints[n]の何番目に当たるのかを知りたい
・文字でないものは０点とする
・Player 1 wins!, Player 2 wins!, or Tieを出力する処理を書く
→①player1とplayer2のスコアが同じか②player1が大きいか③player2が大きいかの処理を書く
→if文を使って処理を分ける
・コンピューターは文字をアスキーという規格で、表現している

*/