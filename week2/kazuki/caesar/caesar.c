#include <cs50.h>
#include <stdio.h>
#include<stdbool.h>
#include<stdlib.h>

int is_valid_input(int argc, string input_str);
string create_ciphertext(string str, int number_argv);

int main(int argc, string argv[])
{
    char ciphertext[256];

    printf ("argv[1]:%s\n", argv[1]);

    if(is_valid_input(argc, argv[1]) == 0)//入力値が正しいかどうかを聞いているので、1(true)を返してくれば正しい
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int number_argv = atoi(argv[1]);

    string str = get_string ("plaintext:");
    printf ("文字列:%s\n", str);

    printf("ciphertext:%s\n", create_ciphertext(str, number_argv));

    return 0;
}

int is_valid_input(int argc, string input_str)
{
    // printf("argc:%d\n input_str:%s\n", argc, input_str);

    if(argc == 1 || 2 < argc)return 0;

    for(int i = 0; input_str[i] != '\0'; i++)
    {
        if(input_str[i] < '0' || '9' < input_str[i])
            return 0;
    }
    return 1;
}

string create_ciphertext(string str, int number_argv)
{
    int ciphertext_uppershift;
    int ciphertext_lowershift;

    for(int i = 0; str[i] != '\0'; i++ )
    {
        if('a' <= str[i] && str[i] <= 'z')
        {
            int cipher_upperword = str[i] - 'a';
            ciphertext_uppershift = (cipher_upperword + number_argv) % 26;
            str[i]= 'a' + ciphertext_uppershift;

            printf("cipher_upperword:%d\n", cipher_upperword);
            printf("ciphertext_sum:%d\n", ciphertext_uppershift);
            printf("str:%s\n", str);
        }
        else if('A' <= str[i] && str[i] <= 'Z')
        {
            int cipher_lowerword = str[i] - 'A';//ci = (pi + k) % 26
            ciphertext_lowershift = (cipher_lowerword + number_argv) % 26;
            str[i]= 'A' + ciphertext_lowershift;

            printf("cipher_lowerword:%d\n", cipher_lowerword);
            printf("ciphertext_lowersum:%d\n", ciphertext_lowershift);
            printf("str:%s\n", str);
        }
        else
        {
            str[i] = str[i];
        }
    }
    return str;
}

/*
【全体の処理の流れ】 = main関数に関わってくるところ
1.まず始めの処理として、整数値をコマンドライン引数として受け取る(k)○
■プログラムは、1 つのコマンドライン引数 (負でない整数) を受け入れる必要があります○
■プログラムをコマンドライン引数なしで、または複数のコマンドライン引数を指定して実行した場合、プログラムはエラーメッセージ (printfで) を出力し、
mainから値1 (エラーを示す) をすぐに返します。○
■コマンドライン引数の文字のいずれかが10進数でない場合、プログラムは"Usage: ./caesar key"というメッセージを出力し、mainから値1が返されます。○
※is_valid_inputで上記処理と一緒に書いてしまう
■プログラムをコマンドライン引数なしで、または複数のコマンドライン引数を指定して実行した場合またはコマンドライン引数の文字のいずれかが10進数でない場合の処理
2."plaintext:"が出力されて、入力する文字を'ABC'として、文字列として受け取る（pi）○
3.受け取った文字列ABCを受け取った整数値分だけずらす
■プログラムは (改行なしの) plaintext:を出力し、ユーザに (get_stringを使って) プレーンテキストのstringを要求しなければなりません。○
■プログラムは (改行なしで) ciphertext:を出力しなければなりません。 平文と対応する暗号文が続き、平文中のアルファベット文字がそれぞれkずつ 「ずれて」 出力されます。○
アルファベット以外の文字はそのまま出力されます。○
■プログラムは大文字と小文字を保持する必要があります。大文字はずらしても大文字のままである必要があります。小文字はずらしても小文字のままである必要があります。○
4.整数値分ずらした文字列を出力
■暗号文を出力した後、改行を出力する必要があります。プログラムはmainに0を返して終了するはずです。

[create_ciphertextの処理の流れ]
・アスキーコードを使用していく
・”A"または"a"から、入力された文字を引くことで、何番目にあるのかわかる○
・argvの文字列→整数へ変換する（atoi）○
・大文字の時と小文字の時は、処理を分けると書きやすいかも？
→関数名を切り分けるとreturn文で返しやすくなる○
・何番目かわかったら次は出力をする文字を特定

　【現状困っていること】
・大文字と小文字の処理を分けているため、両方出力されている
→
*/

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
==================
$ ./caesar 1
plaintext:  ABC
ciphertext: BCD
==================
【全体の処理の流れ】 = main関数に関わってくるところ
1.まず始めの処理として、整数値の1をコマンドライン引数として受け取る(k)○
■プログラムは、1 つのコマンドライン引数 (負でない整数) を受け入れる必要があります。呼びましょう議論のために。
■プログラムがコマンドライン引数なしで実行された場合、または複数のコマンドライン引数を使用して実行された場合、プログラムは選択したエラー メッセージ ( を使用) を出力し、 (エラーを示す傾向がある)の値printfからすぐに戻る必要があります。main1
■コマンド ライン引数のいずれかの文字が 10 進数でない場合、プログラムはメッセージを出力し、値Usage: ./caesar keyから を返す必要があります。main1
2."plaintext:"が出力されて、入力する文字を'ABC'として、文字列として受け取る（pi）○
3.受け取った文字列ABCを受け取った整数値分だけずらす
4.整数値分ずらした文字列を出力

aまたはAを配列の要素[0]番目とする(多分、初期化)○
→A[0]B[1]C[2]...Z[25]
4.受け取ってきた値が、aだった場合、「aだから、[0]番目だ！」とわかるようにしたい
→1.大文字か 2.小文字か 3.それ以外か
→受け取ってきた文字列が、事前に用意した配列の要素番号と比較した時に、等しい場合その配列の要素番号を抽出するとか？
→受け取った文字列は、計算によって、ciを求めることができるので、事前に用意した配列の要素とマッチすれば、その数字を出力することができる
5.受け取った文字列が英字の場合、ci = (pi + k) % 26の計算を行い、ciを求める
例）整数値:1 ABC → BCD 配列の番号が[0][1][2]　→ [1][2][3]となる処理
6.それ以外の場合、エラー文を出力
→ユーザーがコマンドライン引数を１つも指定しないか、２つ以上指定した場合、Usage: "./caesar key\n"
*/
