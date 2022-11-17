#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
using namespace std;
typedef struct htnode
{
	char bank;
	int weight;
	int parent, lchild, rchild;
}htnode, * huffmantree;
typedef char** huffmancode;

char b[26];
int c[26] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }; char* ps;
int judge(char b[], char c)//下面三个函数都是统计字符串的每个字符频度
{
	char* p = b;
	while (*p != '\0')
	{
		if (*p == c)
		{
			return 1;
		}
		p++;
	}
	return 0;
}
void rank1(char a[])
{
	char* p = a;  int flag = 0; int i = 0;
	b[0] = '\0';
	while (*p != '\0')
	{
		if (*p != '\0')
		{
			flag = 0;
			flag = judge(b, *p);
		}
		if (flag == 0)
		{
			b[i] = *p; b[i + 1] = '\0'; i++;
		}
		p++;
	}
	p = a; int j = 0;
	ps = b;
	while (*p != '\0')
	{
		for (j = 0; j < i; j++)
		{
			if (b[j] == *p)
			{
				c[j]++;
			}
		}
		p++;
	}
	c;
}

void rate()
{
	char a[26] = "ABRACADABRA" ;
	
	rank1(a);
}

void select(huffmantree ht, int len, int& s1, int& s2)
{
	int i, min1 = 0x3f3f3f3f, min2 = 0x3f3f3f3f;
	int x1 = 0, x2 = 0;

	for (int i = 1; i <= len; i++) {
		if (ht[i].parent == 0 && ht[i].weight < min1) {
			x2 = x1;
			min2 = min1;
			min1 = ht[i].weight;
			x1 = i;
		}
		else if (ht[i].parent == 0 && ht[i].weight < min2) {
			min2 = ht[i].weight;
			x2 = i;
		}
	}
	s1 = x1;
	s2 = x2;
}
void creathuffmantree(huffmantree& ht, int n)
{

	int m = 2 * n - 1;
	int s1, s2;
	ht = new htnode[m + 1];
	for (int i = 1; i <= m; i++) {
		ht[i].lchild = 0;
		ht[i].parent = 0;
		ht[i].rchild = 0;
		ht[i].weight = 0;
	}
	
	for (int i = 1;*ps!='\0'; i++)
	{
		ht[i].bank = *ps;
		ht[i].weight = c[i - 1];
		ps++;
	}

	for (int i = n + 1; i <= m; i++) {
		select(ht, i - 1, s1, s2);
		ht[i].lchild = s1;
		ht[i].rchild = s2;
		ht[s1].parent = i;
		ht[s2].parent = i;
		ht[i].weight = ht[s1].weight + ht[s2].weight;
	}


}

void creathuffmancode(huffmantree ht, huffmancode& hc, int n)
{
	int i, start, c, f;
	hc = new char* [n + 1];         						
	char* cd = new char[n];							
	cd[n - 1] = '\0';
	for (i = 1; i <= n; ++i)
	{
		start = n - 1;
		c = i; f = ht[i].parent;
		while (f != 0)
		{
			--start;
			if (ht[f].lchild == c) cd[start] = '0';
			else cd[start] = '1';
			c = f; f = ht[f].parent;

		}
		hc[i] = new char[n - start];
		strcpy(hc[i], &cd[start]);
	}
	delete cd;
}


void show(huffmantree ht, huffmancode hc)
{
	for (int i = 1; i <= sizeof(hc) + 1; i++)
		cout << ht[i].bank << "编码为" << hc[i] << endl;

}
int main()
{
	huffmantree ht;
	huffmancode hc;
	int n;
	cout << "请输入叶子结点的个数：\n";
	cin >> n;
	rate();
	creathuffmantree(ht, n);
	creathuffmancode(ht, hc, n);
	show(ht, hc);
	return 0;
}