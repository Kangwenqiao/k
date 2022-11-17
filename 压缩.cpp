#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int e; int zipArray[15];
void scan(int p[5][5])
{
	
	int i, j;
	FILE* fp = fopen("??1.txt", "r");
	fscanf(fp, "%d", &e);
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			fscanf(fp, "%d", &p[i][j]);
		}
	}
}
void scan1(int p[5][5])
{

	int i, j;
	FILE* fp = fopen("??2.txt", "r");
	fscanf(fp, "%d", &e);
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			fscanf(fp, "%d", &p[i][j]);
		}
	}
}

void zipdj(int a[5][5])
{
	int k=0;
	
	int i, j;
	for (i = 0;i<5; i++)
	{
		for (j = 0;j<=i; j++)
		{
			zipArray[k] = a[i][j];
			k++;
		}
	}
}
int leijia(int a)
{
	int i, j;
	int sum=0;
	for (i = 1; i <= a; i++)
	{
		sum = sum + i;
	}
	return sum;
}
void search1()
{
	int h, l;
	printf("?:");
	scanf("%d",&h);
	printf("?:");
	scanf("%d", &l);
	if ((l-1) > h)//?????
	{
		int temp;
		temp = l; l = h; h = temp;
	}
	h = h - 1;
	int k;
	if (h == 0)//????(1,1)???
	{
		k = 0;
	}
	else
	k = leijia(h);
	if ((k + l) == 1)//??
	{
		printf("\n??????%d??  %d\n", 1, zipArray[0]);
		exit(0);
	}
	printf("\n??????%d??  %d\n",k+l, zipArray[k+l-1]);
}
void search2()
{
	int h, l;
	printf("?:");
	scanf("%d", &h);
	printf("?:");
	scanf("%d", &l);
	if ((l - 1) >= h)
	{
		printf("???0\n");
		exit(0);
	}
	h = h - 1;
	int k;
	if (h == 0)
	{
		k = 0;
	}
	else
		k = leijia(h);
	if ((k + l) == 1)
	{
		printf("\n??????%d??  %d\n", 1, zipArray[0]);
		exit(0);
	}
	printf("\n??????%d??  %d\n", k + l, zipArray[k + l - 1]);
}
int  main() 
{
	int MatrixA[5][5], MatrixB[5][5];
	
	//scan(MatrixA);
	//zipdj(MatrixA);search1();
	
	
	scan1(MatrixB);
	zipdj(MatrixB); search2();
	return 0;
}
