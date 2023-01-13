Sort函数使用模板:

Sort(start,end,排序方法)

1.第一个参数是要排序数组的起始地址

2.第二个参数是数组结束地址的下一位

3.第三个是排序的方法，可不填，默认升序

一般是直接对数组进行排序，例如对数组a[10]排序，sort（a,a+10）就行了。



一，如何对数组降序排序呢？
bool cmp(int a,int b)
{    
    return a>b;
  //return a>b?true:false;等价
}
然后sort（a，a+10，cmp）就可以降序排序了

二，如何对字符串进行排序呢？

假设创建了字符串数组

bool cmp(string a,string b)
{
    return a<b;
}
然后sort(s,s+n,cmp)就可以对很多个字符串进行排序了

三，如何对结构体进行排序呢？

假设自己定义了一个结构体node

有一个node类型的数组node arr[100]，想对它进行排序：先按a值升序排列，如果a值相同，再按b值降序排列，如果b还相同，就按c降序排列。就可以写这样一个比较函数：

以下是代码片段：

struct node
{
int a;
int b;
double c;
}
bool cmp(node x,node y)
{
if(x.a!=y.a) return x.a<y.a;
if(x.b!=y.b) return x.b>y.b;
return x.c>y.c;
}
以上就是比较常用的了。
————————————————
版权声明：本文为CSDN博主「moomhxy」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/qq_41785863/article/details/81128146
