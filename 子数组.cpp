//给你一个正整数数组 arr ，请你计算所有可能的奇数长度子数组的和。

//子数组 定义为原数组中的一个连续子序列。

//请你返回 arr 中 所有奇数长度子数组的和 。

/*输入：arr = [1,4,2,5,3]
输出：58
解释：所有奇数长度子数组和它们的和为：
[1] = 1
[4] = 4
[2] = 2
[5] = 5
[3] = 3
[1,4,2] = 7
[4,2,5] = 11
[2,5,3] = 10
[1,4,2,5,3] = 15
我们将所有值求和得到 1 + 4 + 2 + 5 + 3 + 7 + 11 + 10 + 15 = 58

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/sum-of-all-odd-length-subarrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
int sum(vector<int> &arr)
{
	int summ = 0;
	for (int i = 1; i <= arr.size(); i = i + 2)//i为字串长度
	{
		for (int j = 0; j + i <= arr.size(); j++)//j表示开始位置
		{
			for (int k=j; k < j + i;++k)
			{
				summ += arr[k];
			}
		}
	}
	return summ;
}
int main()
{
	vector<int> arr;
	arr = { 1,4,2,5,3 };
	sum(arr);
}