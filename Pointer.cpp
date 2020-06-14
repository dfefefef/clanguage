/*
	������ָ�붨�壺 void ��*fun������
		���ͺ����� void gun��void ��*fun��������int a����ʹ�ú���ָ�룬���ݵ���ʱʹ�õĲ�������ӵĺ���ָ�벻һ��
		���ﵽʵ����ͬһ��������ʵ�ֲ�ͬ�������ܵ�Ч����gun��fun��a��

	sizeof(������),sizeof(ָ�������ָ��)�����һ����ǰ���������С��������ָ����ռ�ռ��С

	��ά�������ָ����ָ��
		��ָ���ȡ*���Ǹ�ָ�룻��ָ���ָ���ָ�벻ͬ��int [][]���ܸ�ֵ��int **


*/


#include<algorithm>
#include<iostream>

const int N = 100;


void ZigzagMatrix(int a[][N], int n)
{
	bool updown = false;
	int num = 1;
	int sum = 0;
	int i = 0;
	int j = 0;

	for (; sum <= n+n-2; sum++)
	{
		i = updown ? 0 : sum;
		for (j = sum - i; j >= 0 && j <= sum; )
		{
			if (sum-j < n&&j < n)
			{
				a[sum-j][j] = num;
				num++;
			}
			updown ? --j : ++j;
		}
		updown = !updown;
	}
}

void ZZMatrix()
{
	int	n = 0;
	int z[N][N];
	
	if (std::cin>>n)
	{
		ZigzagMatrix(z, n);

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				std::cout <<z[i][j] <<"  ";
			}
			std::cout << std::endl;
		}
	}
}

bool isPalindrome(int n)
{
	if (n < 0)
		return false;
	int pop = 0, x = 0;
	while (n)
	{
		pop = n % 10;
		
		if (x > INT_MAX / 10 || (x == INT_MAX&&pop == 8))
			return false;
		x = pop + 10 * x;
	}
	return x == n ? true : false;
}

