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

void selectsort(sqlist l)
{
	int i, j,k,t;
	for (i = 1; i < l->length; i++)
	{
		k = i;
		for (j = i + 1; j <= l->length; j++)
		{
			if (l[j].data < l[k].data) k = j;
		}
		if(k!=i)
		{
			t = l[i].data; l[i].data = l[k].data; l[k].data = t;
		}
		print(l);
	}
}
int main()
{
	sqlist s;
	cout << "几个数?";
	cin >> s->length;
	create(s);
	selectsort(s);
	return 0;
}
