#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#define maxint 100
typedef enum status{succ,fall,uncreate}status;
typedef struct listion
{
	status state;
	int length;
	int num;
	int key;
}list_[maxint], * ptlist;
typedef struct hs
{
	int vexs;
}key[maxint];

status create(list_ l)
{
	int leng; int i, j,num;
	cin >> leng;
	l->length = leng;
	for (i = 1; i <= l->length; i++)
	{
		cin >> num;
		l[i].num = num;
		l[i].state = uncreate;
	}
	return succ;
}
int hs_function(int n)
{
	int hs;
	hs = n % 11;
	return hs;
}
status hs(list_ l, key k)
{
	int long_ = l->length; int key_;
	int i, j;

	for (i = 0; i <= l->length; i++)
	{
		k[i].vexs = maxint;
	}

	for (i = 1; i <= l->length; i++)
	{
		key_ = hs_function(l[i].num);
		l[i].key = key_;
		if (k[key_].vexs==maxint)
			k[key_].vexs = l[i].num, l[i].state = succ;
	}
	return succ;
}
status dea_conflict(list_ l, key k)
{
	int i, j;
	for (i = 1; i <= l->length; i++)
	{
		if (l[i].state == uncreate)
		{
			for (j = l[i].key;j<l->length; j++)
			{
				if (k[j].vexs == maxint) { k[j].vexs = l[i].num, l[i].state = succ; break;}
			}
		}
	}
	for (i = 1; i <= l->length; i++)
	{
		if (l[i].state == uncreate)
		{
			for (j = 1; j < l->length; j++)
			{
				if (k[j].vexs==maxint) k[j].vexs = l[i].num, l[i].state = succ;
			}
		}
	}

	for (i = 0; i < l->length; i++)
	{
		cout << k[i].vexs<<' ';
	}

	return succ;
}
int main()
{
	list_ l; key k;
	create(l);
	hs(l, k);
	dea_conflict(l, k);
	return 0;
}
