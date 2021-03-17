#define _CRT_SECURE_NO_WARNINGS 1
//题目描述
//二维数组中的查找，在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
//请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
#include<stdio.h>
//最直接的方法就是直接将数值所有内容过一边，但次法时间复杂度位O(N)
//若要减小时间复杂度，进行代码优化
//最初思路
int Find1(int *p, int n,int t,int l)
{
	int i = 0;
	for (i = 0; i < t; i++)
	{
		int j = l-1;
		if (*(p + i * l + j) == n)
		{
			return 1;
		}
		else if (*(p + i * l + j) > n)
		{
			for (j-=1; j > 0; j--)
			{
				if (*(p + i * l + j) == n)
					return 1;
				if (*(p + i * l + j) < n)
					break;
				
			}
		}
	}
	return 0;
}
//整理思路（右上角查找,行式）
int Find2(int* p, int n, int row, int col)
{
	int i = 0;
	int j = col - 1;
	while (i<row && j>=0)//循环条件同时避免非法访问
	{
		if (*(p + i * col + j) == n)//根据题目条件递增排列，一开始比较的就是二维数组右上角的元素，若找到返回1
			return 1;
		else if (*(p + i * col + j) < n)//若该元素小于目标数字，则说明此元素前面的元素都要小于目标数字 ，则直接查找下一行
			++i;
		else                       //若该元素大于目标数字，则说明次行中最
			--j;
	}
	return 0;
}
//列式
int Find3(int* p, int n, int row, int col)
{
	int i = 0;
	int j = col-1;
	while (i < row && j >=0)
	{
		if (*(p + i * col + j) == n)
			return 1;
		else if (*(p + i * col + j) > n)
			--j;
		else
			++i;
	}
	return 0;
}
int main(void)
{
	int n = 0;
	int arr[4][4] = { {1,2,8,9}
					 ,{2,4,9,12}
	                 ,{4,7,10,13}
					 ,{6,8,11,15} };
	int i = 0;
	/*for (i = 0; i < 4; i++)
	{
		int j = 0;
		for (j = 0; j < 4; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}*/
	scanf("%d", &n);
	int ret=Find3(arr, n,4,4);
	if (ret == 1)
		printf("ture!");
	else
		printf("no!");
	return 0;
}
