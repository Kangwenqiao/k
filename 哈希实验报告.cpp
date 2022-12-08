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
int p;
status create(list_ l)
{
	int leng; int i, j,num;
	cin >> leng;//输入元素个数
	l->length = leng;
	for (i = 1; i <= l->length; i++)
	{
		cin >> num;
		l[i].num = num;
		l[i].state = uncreate;//加入初始数组的状态全都是未载入哈希
	}
	
	cin >> p;
	return succ;
}
int hs_function(int n)//哈希函数
{
	int hs;
	hs = n % p;
	return hs;
}
status hs(list_ l, key k)
{
	int long_ = l->length; int key_;
	int i, j;

	for (i = 0; i <= p; i++)
	{
		k[i].vexs = maxint;//哈希列先全部取最大树为空
	}

	for (i = 1; i <= l->length; i++)//将数字写入散列
	{
		key_ = hs_function(l[i].num);//哈希函数求key值
		l[i].key = key_;
		if (k[key_].vexs==maxint)
			k[key_].vexs = l[i].num, l[i].state = succ;//对成功写入的进行标记成功
	}
	return succ;
}
status dea_conflict(list_ l, key k)//冲突处理
{
	int i, j;
	for (i = 1; i <= l->length; i++)//先往下寻找空位
	{
		if (l[i].state == uncreate)
		{
			for (j = l[i].key;j<p; j++)
			{
				if (k[j].vexs == maxint) { k[j].vexs = l[i].num, l[i].state = succ; break;}
			}
		}
	}
	for (i = 1; i <= l->length; i++)//然后从表头开始
	{
		if (l[i].state == uncreate)
		{
			for (j = 1; j < p; j++)
			{
				if (k[j].vexs==maxint) k[j].vexs = l[i].num, l[i].state = succ;
			}
		}
	}

	for (i = 0; i < p; i++)//打印散列
	{
		if(k[i].vexs!=maxint)
		cout << k[i].vexs<<' '<<i<<endl;
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
