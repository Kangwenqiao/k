#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
typedef enum Status{ success,fail,uncreat }Status;
typedef struct fuhao
{
	char c;
	struct fuhao* next;
}fuhao,*fuhao1;
fuhao1 p;
fuhao1 s;
Status creat(fuhao1& s)
{
	s = NULL;
	return success;
}
Status push(fuhao1& s,char c)
{
	p = new fuhao;
	p->c = c;
	p->next = s;
	s = p;
	return success;
}
int pop(fuhao1& s)
{
	char c;
	p = new fuhao;
	p = s;
	c = s->c;
	s = s->next;
	free(p);
	return c;
}
int gettop(fuhao1& s)
{
	char e;
	e = s->c;
	return e;
}
int main()
{
	creat(s);
	char c='\0', d, b;
	int k=0, flag=1,flag2=0,flag3=0,flag4=0;
	for (;;)
	{	
		
		if (k == 1)
		{
			scanf("%c", &c);
			k =0;
			continue;
			
		}
		scanf("%c", &c);
		if (c == '.')
		{
			flag2 = 1;
			continue;
		}
		
		if (flag2 == 1&&c=='\n')
		{
			break;
		}
		else if (flag2 == 1)
		{
			flag2 = 0;
			continue;
		}
		if (c == '*'&&flag4!=1)
		{
			flag3 = 1;
			continue;
		}
		if (flag3 == 1 && c == '/')
		{
			c = '*';
			flag3 = 0;
		}
		else if(flag3==1)
		{
			flag3 = 0;
			continue;
		}


		if (c == '/')
		{
			flag4 = 1;
			continue;
		}
		if (flag4 == 1 && c == '*')
		{
			c = '/';
			flag4 = 0;
		}
		else if (flag4 == 1)
		{
			flag4 = 0;
			continue;
		}

		
	
		switch (c)
		{
		case '[':
		case'(':
		case'{':
			push(s, c);
			break;
		case '/':
			push(s, '<');
			
			break;
		case ']':
			if (s == NULL)
			{
				flag = 0;
				break;
			}
			d = gettop(s);
			if (s != NULL && d == '[')
			{
				b = pop(s);
				break;
			}
			else
			{
				flag = 0;
				break;
			}
		case ')':
			if (s == NULL)
			{
				flag = 0;
				break;
			}
			d = gettop(s);
			if (s != NULL && d == '(')
			{
				b = pop(s);
				break;
			}
			else
			{
				flag = 0;
				break;
			}
		case'}':
			if (s == NULL)
			{
				flag = 0;
				break;
			}
			d = gettop(s);
			if (s != NULL && d == '{')
			{
				b = pop(s);
				break;
			}
			else
			{
				flag = 0;
				break;
			}
		case '*':
			
			if (s == NULL)
			{
				flag = 0;
				break;
			}
			d = gettop(s);
			if (s != NULL && d == '<')
			{
				b = pop(s);
				
				break;
			}
			else
			{
				flag = 0;
				break;
			}
		}

		if (flag == 0)
		{
			break;
		}
	}
	if (flag == 1&&s==NULL)
	{
		printf("YES");
	}
	else
	{
		printf("NO");
		if (s == NULL)
		{
			printf("\n?-%c",c);
		}
		else
		{
			if (gettop(s) == '<')
			{
				printf("\n/*-?");
				exit(0);
			}
			printf("\n%c-?",gettop(s));
		}
	}
	return 0;
}
