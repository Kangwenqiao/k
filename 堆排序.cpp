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

void heapadjust(sqlist l, int s, int m)
{
	int i, j;
	int rc = l[s].data;
	for (j = 2 * s; j < m; j *= 2)
	{
		if (j < m && l[j].data < l[j + 1].data) j++;
		if (rc >= l[j].data) break;
		l[s].data = l[j].data; s = j;
	}
	l[s].data = rc;
}
void creatheap(sqlist l)
{
	int n = l->length;
	for (int i = n / 2; i > 0; --i)
	{
		heapadjust(l, i, n);
	}
}
void heapsort(sqlist l)
{
	creatheap(l);
	for (int i = l->length; i > 1; i--)
	{
		int x = l[1].data;
		l[1].data = l[i].data;
		l[i].data = x;
		heapadjust(l, 1, i - 1);
		print(l);
	}
}
int main()
{
	sqlist s;
	cout << "几个数?";
	cin >> s->length;
	create(s);
	heapsort(s);
	return 0;
}
