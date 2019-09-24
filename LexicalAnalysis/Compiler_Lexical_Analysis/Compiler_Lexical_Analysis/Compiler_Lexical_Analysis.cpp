﻿// compiler_Lexical_Analyse.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctype.h>
#include <stdio.h>

using namespace std;

#define MAXLINE 1024
#define IS_IDENFR	1
#define IS_NUMBER	2
#define IS_CHAR		3
#define IS_STRING	4
#define IS_TK		5
#define IS_COMPARE	6

//get the const for find out what your word is;

FILE * fp;
int line;
string word;
char c;

int getwords();
void putwords(int a);

int main()
{
	char buf[MAXLINE];
	int len;
	int a;
	if ((fp = fopen("testfile.txt", "r")) == NULL) {
		perror("fail to read");
		return 1;
	}

	while ((a = getwords()) != -1) {
		putwords(a);
	}
	return 0;
}

void putwords(int a) {

}

int getwords() {
	return -1;
	word = "";
	c = fgetc(fp);
	while (c == ' ' || c == '	' || c == '\n') {
		c = fgetc(fp);
	}
	if (c == EOF) {
		return -1;
	}
	if (isalpha(c) || c == '_') {
		while (isalpha(c) || c == '_') {
			word += c;
			c = fgetc(fp);
		}
		cout << word << endl;
		fseek(fp, -1, 1);
		return IS_IDENFR;
	}
	if (isdigit(c)) {
		while (isdigit(c)) {
			word += c;
			c = fgetc(fp);
		}
		cout << word << endl;
		fseek(fp, -1, 1);
		return IS_NUMBER;
	}
	if (c == '+' || c == '-' || c == '*' || c == '/') {
		return IS_TK;
	}
	if (c == '(' || c == ')' || c == '(' || c == '[' || c == ']' || c == '{' || c == '}') {
		return 8;
	}
}

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
