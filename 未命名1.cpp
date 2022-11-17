#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
	char str[4][1010];
	int i, j;
	for (i = 0; i <4; i++)
	{
		gets(str[i]);
	}
	char zhongwen[3];
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 2; j++)
		{
			zhongwen[j] = str[i][j];
		}	
		printf("%s", zhongwen);
	}
	printf("\n");
	return 0;
}
