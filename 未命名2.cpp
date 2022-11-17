#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

#define N 100

int MAZE[100][100];
//int Direction[8][2]={{0,1},{1,1},{0,-1},{-1,-1},{1,1},{0,-1},{-1,-1},{0,1}};
typedef struct {
    int x;
    int y;
    int pre; //?????????(??)
}position;

typedef struct my_queue {
    position data[1000];
    int front;
    int rear;
}Queue;

typedef struct{
	position data[1000];
	int top;
}Stack;

//??????????????
void InitQue(Queue *&q)//????? 
{
	q=(Queue *)malloc(sizeof(Queue));
	q->front=q->rear=-1;
}

int EmptyQueue(Queue *&q){//?? 
	return (q->front==q->rear);
}

int push(Queue *&q,position &e){//?? 
	if(q->rear>999)
		return 0;
	e.pre=q->front;
	q->rear++;
	q->data[q->rear]=e;
	return 1;
}

int pop(Queue *&q,position &e){//?? 
	if(EmptyQueue(q))
		return 0;
	q->front++;
	e=q->data[q->front];
	return 1;
}
//???? 
void print(Queue *&qu,int k)
{
	int j;//????????????,???????????
	Stack s;
	s.top=-1;
	while(k!=-1){//?????????qu->front?? 
		j=k;//??pre??????????????? 
		k=qu->data[k].pre;//????????pre????? 
		s.data[++s.top]=qu->data[j]; 
	}
	int ns=0;//????????,ns???? 
	while(s.top!=-1){
		ns++;
		printf("(%d,%d)",s.data[s.top].x,s.data[s.top].y);
		s.top--;
		if(ns%5==0)
			printf("\n");
		else
			printf("\t");
		
	}
	printf("\n");
}
//???? 
int mgpath1(int x,int y,int m,int n)
{
	position e;
	int i,j,pre;
	Queue *qu;
	InitQue(qu);
	
	e.x=x,e.y=y,e.pre=-1;
	MAZE[x][y]=-1;
	push(qu,e);
	
	while(!EmptyQueue(qu)){
		pop(qu,e);
		i=e.x,j=e.y,pre=e.pre;
		if(i==m&&j==n){
			print(qu,qu->front);
			return 1;
		}
		int d=-1;
		int in,jn;
		while(d<8){//?,??,?,??,?,??,?,??
			d++;
			switch(d){
				case 0:{in=i-1,jn=j;break;}
				case 1:{in=i-1,jn=j+1;break;}
				case 2:{in=i,jn=j+1;break;}
				case 3:{in=i+1,jn=j+1;break;}
				case 4:{in=i+1,jn=j;break;}
				case 5:{in=i+1,jn=j-1;break;}
				case 6:{in=i,jn=j-1;break;}
				case 7:{in=i-1,jn=j-1;break;}
			}
			if(MAZE[in][jn]==0){
				e.x=in,e.y=jn,e.pre=qu->front;
				push(qu,e);
				MAZE[in][jn]=-1;
			}
		}
	}
	return 0;
}
//????,??minnum?maxnum????? 
int random_index(int minnum,int maxnum) {
    struct timespec time1 = { 0, 0 };
    clock_gettime(CLOCK_REALTIME, &time1);
    srand(time1.tv_nsec);
    int choice = maxnum - minnum + 1;
    int a = rand() % choice + minnum;
    return a;
}

int main()
{
	int m,n;
	printf("???????"); 
	scanf("%d",&m);
	printf("???????"); 
	scanf("%d",&n);
	for(int i=0;i<m+2;i++){
		for(int j=0;j<n+2;j++){
			if(i==0||i==m+1)
				MAZE[i][j]=1;
			else if(j==0||j==n+1)
				MAZE[i][j]=1;
			else
				MAZE[i][j]=random_index(0,100)%2;
			MAZE[1][1]=0;
			MAZE[m][n]=0;
			printf("%d ",MAZE[i][j]);
			Sleep(m+n);
		}
		printf("\n");
	}
	
	if(!mgpath1(1,1,m,n))
		printf("??");
	return 0;
}

