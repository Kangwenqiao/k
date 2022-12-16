#include<iostream>
using namespace std;
#define maxsize 100
#define elemtype int
typedef struct
{
	elemtype data;
	int key;
	int length;
}sqlist[maxsize];
int l = 1;
void create(sqlist s)
{
	int i, j;
	for (i = 1; i <= s->length; i++)
	{
		cin >> s[i].data;
		s[i].key = i;
	}
}
void print(sqlist s)
{
	int h;
	cout << "第" << l << "趟 :"; l++;
	for (h = 1; h <= s->length; h++)
	{
		cout << s[h].data << " ";

	}
	cout << endl;
}
void insertsort(sqlist s)
{
	int i, j;
	for (i = 2; i <= s->length; i++)
	{
		if (s[i].data > s[i - 1].data)
		{
			print(s);
			continue;
		}
		s[0].data = s[i].data;
		s[i].data = s[i - 1].data;
		
		for (j = i - 2;s[0].data < s[j].data;j--)
		{
			s[j + 1].data = s[j].data;
		}
		s[j + 1].data = s[0].data;
		print(s);
	}
	
}
int main()
{
	sqlist s;
	cout << "几个数?";
	cin >> s->length;
	create(s);
	insertsort(s);
	return 0;
}
