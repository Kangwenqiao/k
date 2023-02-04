#include<iostream>
using namespace std;
int box[50];
bool fla[50] = {0};
int main()
{
	void dfs(int);
	dfs(1);
	return 0;
}
void dfs(int step)
{
	if (step == 4)//终止条件
	{
		for (int i = 1; i <= 3; i++)
		{
			cout << box[i] << " ";
		}
		cout << endl;
		return;
	}
	//递归关系是
	for (int i = 1; i <= 3; i++)
	{
		if (fla[i] == 0)
		{
			box[step] = i;
			fla[i] = 1;
			dfs(step + 1);//递归分入口
			fla[i] = 0;//状态回溯
		}
	}
}
