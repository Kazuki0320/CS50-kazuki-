#include<stdio.h>
#include<cs50.h>
#include <stdbool.h>

int one_word(string str);
int sentence(string str);
int all_word(string str);
double average_wordL(int all_word_count, int word_count);
double average_wordS(int sentence_count, int word_count);
void grade_output(double L, double S);

int main(void)
{
	string str = get_string("Text: ");
		printf("str:%s\n",str);

	int word_count = one_word(str);
		printf("Word_count:%d\n", word_count);
	int sentence_count = sentence(str);
		printf("sentence_count:%d\n", sentence_count);
	int all_word_count = all_word(str);
		printf("all_word_count:%d\n",all_word_count);

	double L = average_wordL(all_word_count,word_count);
		printf("%f\n",L);
	double S = average_wordS(sentence_count,word_count);
		printf("%f\n",S);

	grade_output(L,S);
}

int one_word(string str)
{
	int count = 1;

	for(int i = 0;str[i] != '\0';i++)
	//文字列をヌル文字まで回す処理
	//str[i] <= '\0'と書くと、73と0の比較になり、for文の処理が行われない
	{
		if(str[i] == ' ')//この場合、文字定数によって空白を１文字として扱う
			count++;
	}
	return count;
}

int sentence(string str)
{
	int count = 0;

	for(int i = 0;str[i] != '\0';i++)
	{
		if(str[i] == '.' || str[i] == '!' || str[i] == '?')
			count++;
	}
	return count;
}

int all_word(string str)
{
	int count = 0;
	for(int i = 0;str[i] != '\0';i++)
	{
		if(('a' <= str[i] && str[i] <= 'z') || ('A' <= str[i] && str[i] <= 'Z'))
			count++;
	}
	return count;
}


double average_wordL(int all_word_count, int word_count)
{
	return ((double)all_word_count / (double)word_count * 100);
}

double average_wordS(int sentence_count, int word_count)
{
	return ((double)sentence_count / (double)word_count * 100);
}

void grade_output(double L, double S)
{
	double calc = 0.0588 * L - 0.296 * S - 15.8;

	if(calc < 1.5)
		printf("Before Grade 1\n");
	else if(calc < 2.5)
		printf("Grade 2\n");
	else if(calc < 3.5)
		printf("Grade 3\n");
	else if(calc < 4.5)
		printf("Grade 4.5\n");
	else if(calc < 5.5)
		printf("Grade 5\n");
	else if(calc < 6.5)
		printf("Grade 6\n");
	else if(calc < 7.5)
		printf("Grade 7\n");
	else if(calc < 8.5)
		printf("Grade 8\n");
	else if(calc < 9.5)
		printf("Grade 9\n");
	else if(calc < 10.5)
		printf("Grade 10\n");
	else if(calc < 11.5)
		printf("Grade 11\n");
	else if(calc < 12.5)
		printf("Grade 12\n");
	else if(calc < 13.5)
		printf("Grade 13\n");
	else if(calc < 14.5)
		printf("Grade 14\n");
	else if(calc < 15.5)
		printf("Grade 15\n");
	else
		printf("Grade 16+\n");
}

/*【処理の流れ】
    ・get_stringで、入力テキストを受け取る

	・引数に、strを渡す
    ・単語数をカウントする
		→count　= 単語数
	※単語数をカウントするにはどんな条件分岐を書けばいいか
		→空白をカウントすると単語数がわかる処理を書けば良い
	例）I am kazuki → ３単語
	↑3単語に対して、空白は２個あるので最後（最初でも同じ）に空白に＋１すれば、記述した単語数になる
		→配列を回していて、” ”になったら、if文の中に入る処理を書いて、そこで＋１するようにする
	・カウントした単語数は新しい変数に代入することで、そこの処理が何をしているのかをわかりやすくする←可読性がアップ

	・文章をカウントする
		→文章の数を数えているので、文章の文末には「.」「！」「？」この３つが使われるので、これをカウントすることで、文章が何文あるのかわかる
		→配列で受け取った文字列の中に、「.」「！」「？」があった場合、カウント＋１とする
		→sentence = 文章の数
		→for文で、ヌル文字までの処理を書いて、if文で条件分岐
	例）Mr. and Mrs. Dursley, of number four Privet Drive, were proud to say that they were perfectly normal, thank you very much.
	↑上記文は３文となる

	・文字数をカウントする
		→文字列を受け取って、if文の中で、文字数をカウントしている

	・Lはテキストの 100 語あたり平均文字数
	(65 / 14 * 100 = 464.29 )
	→int型で、それぞれの数値を出してるため、double型に直す必要がある
	→返り値をdoubleにする
	→引数がint型なので、小数点以下が計算されない。６５/14=4.64...になるように処理を変えてあげる必要がある
	・Sの平均文字数、 はテキストの 100 語あたりの平均文数を算出
	(4 / 14 * 100 = 28.57 )

	・学年レベルを出力できる処理
	index = 0.0588 * L - 0.296 * S - 15.8
	結果のインデックス番号が 16 以上 (上級学部の読書レベルと同等またはそれ以上) の場合、プログラムは"Grade 16+"正確なインデックス番号を与える代わりに出力する必要があります。
	インデックス番号が 1 未満の場合、プログラムは を出力する必要があります"Before Grade 1"。
	→インデックスが1未満は"Before Grade 1"と出力
	→インデックスが16以上は"Grade 16+"と出力
    */
