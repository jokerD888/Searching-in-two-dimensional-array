#define _CRT_SECURE_NO_WARNINGS 1
//��Ŀ����
//��ά�����еĲ��ң���һ����ά�����У�ÿ��һά����ĳ�����ͬ����ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳������
//�����һ������������������һ����ά�����һ���������ж��������Ƿ��и�������
#include<stdio.h>
//��ֱ�ӵķ�������ֱ�ӽ���ֵ�������ݹ�һ�ߣ����η�ʱ�临�Ӷ�λO(N)
//��Ҫ��Сʱ�临�Ӷȣ����д����Ż�
//���˼·
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
//����˼·�����Ͻǲ���,��ʽ��
int Find2(int* p, int n, int row, int col)
{
	int i = 0;
	int j = col - 1;
	while (i<row && j>=0)//ѭ������ͬʱ����Ƿ�����
	{
		if (*(p + i * col + j) == n)//������Ŀ�����������У�һ��ʼ�Ƚϵľ��Ƕ�ά�������Ͻǵ�Ԫ�أ����ҵ�����1
			return 1;
		else if (*(p + i * col + j) < n)//����Ԫ��С��Ŀ�����֣���˵����Ԫ��ǰ���Ԫ�ض�ҪС��Ŀ������ ����ֱ�Ӳ�����һ��
			++i;
		else                       //����Ԫ�ش���Ŀ�����֣���˵����������
			--j;
	}
	return 0;
}
//��ʽ
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
