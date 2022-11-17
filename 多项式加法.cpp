//???????????????????
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
typedef enum Status{success,fail,uncreat}Status;
typedef struct num
{
	int js;
	int zs;
	int flag;
	struct num* next;
}num, * shuzi;
num* head1;
num* head2;
num* head3;
Status creat(shuzi&s)
{
	
	
	s= (num*)malloc(sizeof(num));
	s->next = NULL;
	return success;
}
Status charu(shuzi& s,int jishu,int zhishu)
{
	num* p;
	num* p1;
	p = (num*)malloc(sizeof(num));
	p->js = jishu;
	p->zs = zhishu;
	p->flag = 0;
	p1 = s;
	for (;;)
	{
		if (p1->next == NULL)
		{
			break;
		}
		p1 = p1->next;
		if (p1->next == NULL)
		{
			break;
		}
	}
	
	p->next = p1->next;
	p1->next = p;
	return success;
}
Status xiangjia(shuzi& head1, shuzi& head2)
{
	num* p1, * p2;
	p1 = head1->next, p2 = head2->next;
	for (;;)
	{
		for (;;)
		{
			if (p1->zs == p2->zs)
			{
				charu(head3, p1->js + p2->js, p1->zs);
				p2->flag=p2->flag+1;
				p2 = head2->next;
				break;
			}
			if (p2->next == NULL) 
			{
				charu(head3, p1->js, p1->zs);
				p2 = head2->next;
				break;
			}
			p2 = p2->next;
		}
		if (p1->next == NULL) break;
		p1 = p1->next;
	}
	p2 = head2->next;
	for (;;)
	{
		if (p2->flag == 0)
		{
			charu(head3, p2->js, p2->zs);
		}
		if (p2->next == NULL) break;
		p2 = p2->next;
	}
	return success;
}
Status print(shuzi& head)
{
	num* p;
	p = head->next;
	for (;;)
	{

		printf("%d %d ", p->js, p->zs);
		if (p->next == NULL) break;
		p = p->next;
	}
	return success;
}
int main()
{
	int i,jishu,zhishu;
	creat(head1);
	int a;
	scanf("%d", &a);
	for (i = 1; i <= a; i++)
	{
		scanf("%d", &jishu), scanf("%d", &zhishu);
		charu(head1, jishu, zhishu);
	}
	creat(head2);
	int b;
	scanf("%d", &b);
	for (i = 1; i <= b; i++)
	{
		scanf("%d", &jishu), scanf("%d", &zhishu);
		charu(head2, jishu, zhishu);
	}
	creat(head3);
	xiangjia(head1, head2);
	print(head3);
	return 0;
}

