/*
	函数的指针定义： void （*fun）（）
		泛型函数中 void gun（void （*fun）（），int a）中使用函数指针，根据调用时使用的参数中添加的函数指针不一样
		而达到实现在同一个函数中实现不同函数功能的效果：gun（fun，a）

	sizeof(数组名),sizeof(指向数组的指针)结果不一样，前者是数组大小，后者是指针所占空间大小

	二维数组和行指针列指针
		行指针的取*还是该指针；行指针和指针的指针不同，int [][]不能赋值给int **


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

