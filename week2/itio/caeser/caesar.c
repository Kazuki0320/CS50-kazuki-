#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

bool check_argv(string numStr);
string cesar_slide(string input_str, string inputStr);

int main(int argc, string argv[])
{
	// errer check
	if (argc != 2)
	{
		return 1;
	}

	// errer check
	if (check_argv(argv[1]) == false)
	{
		return 1;
	}

	// input part
	string input_str = get_string("plaintext: ");

	// main part
	string ans = cesar_slide(argv[1], input_str);
	printf("ciphertext: %s\n", ans);
}

bool check_argv(string num_str)
{
	for (int i = 0; num_str[i] != '\0'; i++)
	{
		if (num_str[i] < '0' || '9' < num_str[i])
		{
			return false;
		}
	}
	return true;
}

bool check_range_azAZ(char input_char)
{
	if (('a' <= input_char && input_char <= 'z') || ('A' <= input_char && input_char <= 'Z'))
	{
		return true;
	}
	return false;
}

char convert_char(char plain_text, int argv)
{
	char ret_char = (char)(plain_text + argv);
	while (check_range_azAZ(ret_char) == false)
	{
		ret_char -= 26;
	}
	return ret_char;
}

string cesar_slide(string argv, string input_str)
{
	for (int i = 0; input_str[i] != '\0'; i++)
	{
		if (check_range_azAZ(input_str[i]) == true)
		{
			input_str[i] = convert_char(input_str[i], atoi(argv));
		}
	}
	return input_str;
}

/*
とりあえず、一文字ずつシーザーNumの分ずらしていこう。
問題は、アルファベット以外にどう対処するか。
if文で大文字か小文字の範囲内かを判定する関数を作る
んで、範囲内だったらずらす関数に入れてcharをずらす
範囲外ならそのままの文字を連結
みたいな感じでイケそう。

とりあえず、まず、string cesar_slide(string inputStr);
を作ろう。
*/