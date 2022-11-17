#include<stdio.h>
#define maxsize 1003
#include<stdlib.h>
typedef struct node *stack;
struct node{
	char ch[maxsize];
	int top;
};
stack creat()
{
	stack s;
	s=(stack)malloc(sizeof(struct node));
	s->top=-1;
	return s;	
} 
void push(stack s,char cht)
{
	s->top++;
	s->ch[s->top]=cht;	
} 

int main()
{
	int i,k=0,j;
	static char ch1[1000],ch2[1000],ch[10000];
	struct node *s1=NULL;
	s1=creat();
	ch1['(']=')';
	ch1['{']='}';
	ch1['[']=']';
	//'*/'?'>'???; 
	//'/*'?'<'???; 
	ch1['<']='>';
	for(i=0;;i++)
	{
		gets(ch);
		if(ch[0]=='.'&&ch[1]=='\0') break;
		for(j=0;ch[j]!='\0';j++)
		{
			if(ch[j]=='('||ch[j]==')'||ch[j]=='['||ch[j]==']'||ch[j]=='{'||ch[j]=='}')
			{
				ch2[k++]=ch[j];
			}
			else if(ch[j]=='/'&&ch[j+1]=='*')
			{
				ch2[k++]='<';
				j++;
			}
			else if(ch[j]=='*'&&ch[j+1]=='/')
			{
				ch2[k++]='>';
				j++;
			}
		}
	}
	int flag=1;
	for(i=0;i<k;i++)
	{
		if(ch2[i]=='('||ch2[i]=='['||ch2[i]=='{'||ch2[i]=='<')
		{
			push(s1,ch2[i]);
		}
		else if(ch2[i]==')'||ch2[i]==']'||ch2[i]=='}'||ch2[i]=='>')
		{
			if(s1->top!=-1&&ch1[s1->ch[s1->top]]==ch2[i])
			{
				s1->top--;
			}
			else 
			{
				printf("NO\n");
				//??????; 
				if(s1->top==-1)
				{
					if(ch2[i]==')') printf("?-)");
					else if(ch2[i]=='}') printf("?-}");
					else if(ch2[i]==']') printf("?-]");
					else if(ch2[i]=='>') printf("?-*/"); 
				}
				//??????; 
				else if(ch1[s1->ch[s1->top]]!=ch2[i])
				{
					if(s1->ch[s1->top]=='(') printf("(-?");
					else if(s1->ch[s1->top]=='[') printf("[-?");
					else if(s1->ch[s1->top]=='{') printf("{-?");
					else if(s1->ch[s1->top]=='<') printf("/*-?");
				}
				flag=0;
				break;
			}
		}
	}
    //??,???YES?,??????;
	if(flag==1&&s1->top==-1) printf("YES");
    //???????"[[[]"?;
    //????????;
    else if(flag==1&&s1->top!=-1)
    {
        printf("NO\n");
        if(s1->ch[s1->top]=='(') printf("(-?");
		else if(s1->ch[s1->top]=='[') printf("[-?");
					else if(s1->ch[s1->top]=='{') printf("{-?");
					else if(s1->ch[s1->top]=='<') printf("/*-?");
    }
	return 0;
}

