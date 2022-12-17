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
int partition(sqlist l, int begin, int end)
{
	l->data = l[begin].data;
	int pivotkey = l[begin].data;
	while (begin<end)
	{
		while (begin < end && l[end].data >= pivotkey) end--;
		l[begin].data = l[end].data;
		while (begin < end && l[begin].data <= pivotkey) begin++;
		l[end].data = l[begin].data;
	}
	l[begin].data = l->data;
	return begin;
}
void qsort(sqlist l, int begin, int end)
{
	if (begin < end)
	{
		int pivotloc = partition(l, begin, end);
		qsort(l, begin, pivotloc - 1);
		qsort(l, pivotloc + 1, end);
		print(l);
	}
	
}

int main()
{
	sqlist s;
	cout << "几个数?";
	cin >> s->length;
	create(s);
	qsort(s, 1, s->length);
	return 0;
}
