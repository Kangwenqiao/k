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

void bubblesort(sqlist l)
{
	int max=0,cup,i,j,flag;
	for (i = 1; i <= l->length; i++)
	{
		max = 0;
		for (j = i ; j <= l->length; j++)
		{
			if (max < l[j].data) { max = l[j].data; flag = j; }
		}
		cup = l[i].data; l[i].data = l[flag].data; l[flag].data = cup;
		print(l);
	}
	
}
int main()
{
	sqlist s;
	cout << "几个数?";
	cin >> s->length;
	create(s);
	bubblesort(s);
	return 0;
}
