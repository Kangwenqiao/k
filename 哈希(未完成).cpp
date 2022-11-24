#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<time.h>
#include<set>
using namespace std;
set<int> s1;
typedef struct key_ino
{
	int key;
	int number;
}*ptkey_ino;
int hash_wk(int n)
{
	return n % 11;
}
bool conflic(int key)
{
	pair<set<int>::iterator, bool> retpair;
	retpair = s1.insert(key);
	if (retpair.second == 1)//检验是否冲突
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void test(vector<int> v1,int n)
{
	int key; bool bool_set;  set<ptkey_ino>s2;
	vector<int>::iterator start = v1.begin();
	vector<int>::iterator end = v1.end();
    for (; start != end; start++)
	{
		key = hash_wk(*start);
		while (!conflic(key))
		{
			key = key + 1;
		}
		ptkey_ino k = new key_ino;
		k->key = key,k->number=*start;
		
		cout << key<<" "<<*start<<" " << k << endl;
		s2.insert(k);
	}
	int ad;
	cin >> hex >> ad;
	ptkey_ino pt;
	pt = (ptkey_ino);
	auto it = s2.find(pt);
	cout << *it << endl;
}
int main()
{
	int n,m;
	cin >> n;
	vector<int>v1;
	srand(time(0));
	for (int i = 1; i <= n; i++)
	{
		m = rand();
		v1.push_back(m);
	}
	test(v1,n);
	return 0;
}
