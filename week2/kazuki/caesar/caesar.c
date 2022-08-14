#include <cs50.h>
#include <stdio.h>

int is_alphabet_input(string str);

int main(int argc, string argv[])
{
    printf ("argv[1]:%s\n", argv[1]);
    string str = get_string ("plaintext:");
    printf ("文字列:%s\n", str);

    int alphabet_number  = is_alphabet_input(str);
    printf("alphabet_number:%d\n", alphabet_number);
}

int is_alphabet_input(string str)
{
    char lower_word[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char upper_word[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

    for(int i = 0; str[i] != '\0'; i++)
    {
        for(int j = 0; lower_word[j] != '\0'; j++)
        {
            if(str[i] == lower_word[j])
            {
                printf("lower_word[%d]: %c\n", j, lower_word[j]);
            }
        }

        for(int k = 0; upper_word[k] != '\0'; k++)
        {
            if(str[i] == upper_word[k])
            {
                printf("upper_word[%d]: %c\n", k, upper_word[k]);
            }
        }
    }
    return 0;
}

/*
・受け取ってきた文字列を、lower or upperと比較して、その配列の要素番号を抽出..できるのか？
→'文字列（アスキコード番号）'　==　配列の要素の中にある番号　←これができるのか？←できた！！！
→Aはできて、Bはできてない←つまり、ループを回さず、配列の要素の０番目だけしか抽出できていない
→もし、一致した場合、返す値は配列の要素番号とする　←これもできるのか？←できた！！！
・受け取ってきた文字列の配列要素数ごとに、既に宣言している文字の何番目に当たるのか確認する必要がある
・return文で、何を返すか
・if文の中の処理で、何をすべきか
*/

/*
【やる事】
・アルファベットを受け取って、その文字を暗号化していく
・暗号化する際は、コマンドライン引数で、整数も指定されるので、指定された整数値の分、受け取った文字から〇〇番目のアルファベットを出力
例）整数値:1 ABC → BCDが暗号文として表示される
整数値:13 hello, world → uryyb, jbeyq
p = 何らかの平文 (つまり、暗号化されていないメッセージ)
k = 秘密鍵 (つまり、非負の整数)
ci = 暗号文の文字が何番目かを表す
ci = (pi + k) % 26
例）c = (z(25)+1)%26 →26で割って余りが1
つまり、z→aとなる

【処理】
1.まず始めの処理として、整数値を1をコマンドライン引数として受け取る(k)○
2.入力される文字を'ABC'として、文字列として受け取る（pi）○
3.aまたはAを配列の要素[0]番目とする(多分、初期化)○
→A[0]B[1]C[2]...Z[25]
4.受け取ってきた値が、aだった場合、「aだから、[0]番目だ！」とわかるようにしたい
1.大文字か 2.小文字か 3.それ以外か
→受け取ってきた文字列が、事前に用意した配列の要素番号と比較した時に、等しい場合その配列の要素番号を抽出するとか？
→受け取った文字列は、計算によって、ciを求めることができるので、事前に用意した配列の要素とマッチすれば、その数字を出力することができる
5.受け取った文字列が英字の場合、ci = (pi + k) % 26の計算を行い、ciを求める
例）整数値:1 ABC → BCD 配列の番号が[0][1][2]　→ [1][2][3]となる処理
6.それ以外の場合、エラー文を出力
→ユーザーがコマンドライン引数を１つも指定しないか、２つ以上指定した場合、Usage: "./caesar key\n"
*/
