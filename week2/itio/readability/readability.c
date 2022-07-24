#include <cs50.h>
#include <stdio.h>

void output_grade(double index);
double average_calc(int word, int charOrSentence);
int word_count(string str);
int word_one_character(string str);
int word_sentence(string str);

int main(void)
{
	// input
	string str = get_string("Text: ");
	printf("str: %s\n", str);

	int word = word_count(str);
	int one_character = word_one_character(str);
	int sentence = word_sentence(str);

	double L = average_calc(word, one_character);
	double S = average_calc(word, sentence);
	printf("L S:%f %f\n", L, S);

	// output
	double index = 0.0588 * L - 0.296 * S - 15.8;
	output_grade(index);
	return 0;
}

int word_count(string str) {
	int count = 1;
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == ' ') count++;
	}
	return count;
}

int word_one_character(string str) {
	int count = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		if (('a' <= str[i] && str[i] <= 'z')
			|| ('A' <= str[i] && str[i] <= 'Z')) {
				count++;
			}
	}
	return count;
}

int word_sentence(string str) {
	int count = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == '.' || str[i] == '!' || str[i] == '?') {
				count++;
			}
	}
	return count;
}

double average_calc(int word, int charOrSentence) {
	printf("%d %d\n", word, charOrSentence);
	// 14ワードあたり65文字は、100ワードあたり平均約464.29文字です（65/14 * 100 = 464.29であるため）。-> L
	// 14ワードあたり4センテンスは、100ワードあたり平均約28.57センテンスです（4/14 * 100 = 28.57であるため）。-> S
	return (double)charOrSentence / word * 100;
}

void output_grade(double index) {
	if (index < 1.5) printf("Before Grade 1\n");// 例外１
	else if (1.5 <= index && index < 2.5) printf("Grade 2\n");
	else if (2.5 <= index && index < 3.5) printf("Grade 3\n");
	else if (3.5 <= index && index < 4.5) printf("Grade 4\n");
	else if (4.5 <= index && index < 5.5) printf("Grade 5\n");
	else if (5.5 <= index && index < 6.5) printf("Grade 6\n");
	else if (6.5 <= index && index < 7.5) printf("Grade 7\n");
	else if (7.5 <= index && index < 8.5) printf("Grade 8\n");
	else if (8.5 <= index && index < 9.5) printf("Grade 9\n");
	else if (9.5 <= index && index < 10.5) printf("Grade 10\n");
	else if (10.5 <= index && index < 11.5) printf("Grade 11\n");
	else if (11.5 <= index && index < 12.5) printf("Grade 12\n");
	else if (12.5 <= index && index < 13.5) printf("Grade 13\n");
	else if (13.5 <= index && index < 14.5) printf("Grade 14\n");
	else if (14.5 <= index && index < 15.5) printf("Grade 15\n");
	else if (15.5 <= index) printf("Grade 16+\n");// 例外２
}

/* 問題概要入力された文章の読解レベルを、何年生レベルかで算出するプログラム */

// なんかのアルゴリズム算出計算式
// index = 0.0588 * L - 0.296 * S - 15.8

/*
Lはテキスト中の100語あたりの平均文字数、
Sはテキスト中の100語あたりの平均文数である。
*/

// 14ワードあたり65文字は、100ワードあたり平均約464.29文字です（65/14 * 100 = 464.29であるため）。-> L
// 14ワードあたり4センテンスは、100ワードあたり平均約28.57センテンスです（4/14 * 100 = 28.57であるため）。-> S
// string -> char *strでも可

