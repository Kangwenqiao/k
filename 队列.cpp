#define _CRT_SECURE_NO_WARNINGS
#include<fstream>
#include<iomanip>
#include<stdlib.h>
using namespace std;
typedef enum status { success, fail, uncreat }status;
typedef struct QNode
{
	char date;
	struct QNode *next;
}QNode, * QueuePtr;
typedef struct
{
	QueuePtr front;
	QueuePtr rear;
}LinkQuence;

status creat(LinkQuence& q)
{
	q.front = q.rear = new QNode;
	q.front->next = NULL;
	return success;
}

status enter(LinkQuence& q)
{

	QNode* p;
	char e;
	q.front = q.rear = new QNode;
	q.front->next = NULL;
	fstream file;
	file.open("QNode.txt");
	if (!file)
	{
		printf("error\n");
		exit(fail);
	}
	
	while (!file.eof())
	{
		p = new QNode;
		file >> e;
		p->date = e;
		p->next = NULL; 
		q.rear->next = p;
		q.rear = p;
	}
	return success;
}
status DeQueue(LinkQuence& q)
{
	char e;
	if (q.front == q.rear)return fail;
	QueuePtr p;
	p = q.front->next;
	e = p->date;
	printf("%c\n", e);
	q.front->next = p->next;
	if (q.rear == p)q.rear = q.front;
	free(p);
	return success;
}
status GetQueueLen(LinkQuence& q)
{
	int i=0;
	QueuePtr p;
	p = q.front;
	for (;;)
	{
		p = p->next; i++;
		if (p ==q.rear)
		{
			printf("%d\n",i-1);
			break;
		}
	}
	return success;
}
char gethead(LinkQuence& q)
{
	if (q.front != q.rear)
	{
		printf("%c\n", q.front->next->date);
		return 0;
		
	}
}
int main()
{
	int ch=5000;
	LinkQuence dui;
	printf("1.����һ���ն���\n2.��QNode.txt�ļ��е�����ͨ����Ӳ���EnQueue���뵽��������\n3.����������ִ��DeQueue��������������Ԫ��\n4.����������ִ��GetHead������ȡ��ͷԪ�أ�\n5.ִ��ȡ�ӳ�����GetQueueLen��������г���\n6.0 exit\n");
	while (ch!=0)
	{
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			creat(dui);
			printf("�����ɹ�\n");
			break;
		case 2:
			enter(dui);
				printf("����ɹ�\n");
				break;
		case 3:
			DeQueue(dui);
			DeQueue(dui);
			printf("�ɹ�\n");
			break;

		case 4:
			gethead(dui);
			printf("�ɹ�\n");
			break;
		case 5:
			GetQueueLen(dui);
			break;
		

		}
	}
}
