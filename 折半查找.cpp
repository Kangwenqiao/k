#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
#define maxint 100
typedef enum status { succ,fall,uncreate}status;
typedef struct SSTABLE
{
	int length;
	string num;
}sstable[maxint];
status create(sstable st)
{
	int i;
	string num;
	cin >> st->length;
	for (i = 1; i <= 10; i++)
	{
		cin >> num;
		st[i].num = num;
	}
	return succ;
}
int search_bin(sstable st,string key)
{
	int low, high,mid; int i, j;
	low = 1, high = st->length;
	while (low<=high)
	{
		mid = (low + high) / 2;
		if (key == st[mid].num) return mid;
		else if (key < st[mid].num) high = mid - 1;
		else low = mid + 1;
	}
	cout << "not found";
	return 0;
}
int main()
{
	sstable st;
	create(st);
	string key; cin >> key;
	cout<<search_bin(st, key);
}
