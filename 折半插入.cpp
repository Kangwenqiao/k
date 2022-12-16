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
void binsertsort(sqlist l)
{
	int i, j; int high, low, mid;
	for (i = 2; i <= l->length; i++)
	{
			l[0].data = l[i].data;
			low = 1; high = i - 1;
			while (low<=high)//等号是为了处理i-1=1情况
			{
				mid = (low + high) / 2;
				if (l->data < l[mid].data) high = mid - 1;
				else low = mid + 1;
			}
			for (j = i - 1; j >= high + 1; j--)
				l[j + 1].data = l[j].data;
			l[high + 1].data = l->data;
			print(l);
	}
}
int main()
{
	sqlist s;
	cout << "几个数?";
	cin >> s->length;
	create(s);
	binsertsort(s);
	return 0;
}
