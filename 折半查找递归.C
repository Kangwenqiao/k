#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define ListSize 100
#define ElemType int 
typedef struct
{
    ElemType* elem;
    int length;
}SeqList;
void InitList(SeqList& L)//¶ÔË³Ðò±í³õÊ¼»¯
{
    L.elem = (ElemType*)malloc(ListSize * sizeof(ElemType));
    L.length = 0;
}
void CreatList(SeqList& L)//½¨Á¢Ò»¸öË³Ðò±í 
{
    printf("请输入顺序表的表长：");
    scanf("%d", &L.length);
    printf("请输入顺序表中元素：");
    for (int i = 1; i <= L.length; i++)
    {
        scanf("%d", &L.elem[i]);
    }
    printf("\n");
}
void ShowList(SeqList L)
{
    printf("所建立的顺序表为:");
    for (int i = 1; i <= L.length; i++)
        printf("%-3d", L.elem[i]);
}
int BinSearchRec(SeqList L, ElemType key, int low, int high)//¶ÔÉýÐòÓÐÐò±í½øÐÐµÝ¹éÕÛ°ë²éÕÒ 
{
    int mid;
    low = 1;
    high = L.length;
    if (low > high)
        return 0;
    mid = (high + low) / 2;
    if (key > L.elem[mid])
        BinSearchRec(L, key, mid + 1, high);
    else if (key < L.elem[mid])
        BinSearchRec(L, key, low, mid - 1);
    else printf("%d", mid);
    return mid;
}
int main()
{
    SeqList L;
    InitList(L);
    CreatList(L);
    ShowList(L);
    int mid;
    printf("\n");
    int key, low, high;
    printf("输入你要查找的元素:");
    scanf("%d", &key);
    printf("再次输入表长为:");
    scanf("%d", &L.length);
    low = 1; high = L.length;
    BinSearchRec(L, key, low, high);
    return 0;
}
