#define _CRT_SECUREA_NO_WARNINGS
#include<iostream>
using namespace std;
#define MAXQSIZE 100
#define elemtype int
typedef struct SqQueue
{
	elemtype *base;
	int front;
	int rear;
}SqQueue;
typedef enum Status {yes,no,uncreate}Status;
Status InitQueue(SqQueue& Q)
{
	Q.base = new elemtype[MAXQSIZE];
	if (!Q.base) exit(OVERFLOW);
	Q.front = Q.rear = 0;
	return yes;
}
int length(SqQueue q)
{
	return (q.rear-q.front+MAXQSIZE)%MAXQSIZE;
}
Status enter(SqQueue& q, elemtype e)
{
	if ((q.rear + 1) % MAXQSIZE == q.front)
		exit(OVERFLOW);
	q.base[q.rear] = e;
	q.rear = (q.rear + 1) % MAXQSIZE;
	return yes;
}
Status de(SqQueue& q, elemtype& e)
{
	if (q.front == q.rear)exit(0);
	e = q.base[q.front];
	q.front = (q.front + 1) % MAXQSIZE;
	return yes;
}
elemtype gethead(SqQueue &q)
{
	if (q.front != q.rear)
		return q.base[q.front];
	else
		exit(0);
}


int main()
{
	SqQueue q;
	InitQueue(q);
	
	int i;
	for (i = 1; i <= 99; i++)
	{ 
		enter(q, i);
	}
	cout << length(q)<<endl;
	int e;
	for (;;)
	{
		cout<<gethead(q)<<endl;
		de(q, e);
		
	}
}
