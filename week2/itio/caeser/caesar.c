#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

bool check_argv(string numStr);
string cesar_slide(string input_str, string inputStr);

int main(int argc, string argv[])
{
	// printf("%d\n%s\n%s\n", argc, argv[0], argv[1]);
	// 例外処理１
	if (argc != 2)
	{
		// printf("errer argc\n");
		return 1;
	}

	// 例外処理１
	if (check_argv(argv[1]) == false)
	{
		// printf("errer argv\n");
		return 1;
	}

	// input part
	string input_str = get_string("plaintext: ");
	// printf("input_str:%s\n", input_str);

	// printf("main part\n");
	string ans = cesar_slide(argv[1], input_str);
	printf("ciphertext: %s\n", ans);
}

bool check_argv(string num_str)
{
	for (int i = 0; num_str[i] != '\0'; i++)
	{
		// printf("numStr[i]:%c\n", num_str[i] );
		if (num_str[i] < '0' || '9' < num_str[i])
		{
			return false;
		}
	}
	return true;
}

bool check_range_azAZ(char input_char)
{
	// printf("check_range_azAZ:%c\n", input_char);
	// printf("check_range_azAZ d:%d\n", input_char);
	if (('a' <= input_char && input_char <= 'z') || ('A' <= input_char && input_char <= 'Z'))
	{
		return true;
	}
	return false;
}

// barfoo
// 23
// ans: yxocll

char convert_char(char plain_text, int argv)
{
	// printf("                      plain_text:%c argv:%d\n", plain_text, argv);
	char ret_char = (char)(plain_text + argv);
	// printf("(char)(plain_text + argv):%c\n", ret_char);
	while (check_range_azAZ(ret_char) == false)
	{
		// printf("check\n");
		if ('a' <= plain_text && plain_text <= 'z')
		{
			ret_char -= 26;
			// printf("ret_char:%c\n", ret_char);
			// printf("ret_char d:%d\n", ret_char);
		} else if ('A' <= plain_text && plain_text <= 'Z')
		{
			ret_char -= 26;
		}
		// ret_char -= 24;
	}
	// printf("ret_char:%c\n", ret_char);
	return ret_char;
}

string cesar_slide(string argv, string input_str)
{
	// printf("------------------argv:%s input_str:%s\n", argv, input_str);
	for (int i = 0; input_str[i] != '\0'; i++)
	{
		// printf("for i[%d]:%c\n", i, input_str[i]);
		if (check_range_azAZ(input_str[i]) == true)
		{
			// printf("true\n");
			input_str[i] = convert_char(input_str[i], atoi(argv));
		}
	}
	return input_str;
}

/*
とりあえず、一文字ずるシーザーNumの分ずらしていこう。
問題は、アルファベット以外にどう対処するか。
if文で大文字か小文字の範囲内かを判定する関数を作る
んで、範囲内だったらずらす関数に入れてcharをずらす
範囲外ならそのままの文字を連結
みたいな感じでイケそう。

とりあえず、まず、string cesar_slide(string inputStr);
を作ろう。
*/