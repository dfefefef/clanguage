/*

包含在string.h头文件
void *(memset)(void *s, int c, size_t n)
{
	const unsigned char uc = c;
	unsigned char *su;



	for (su = s; 0 < n; ++su, --n)
		*su = uc;
	return s;
}

memset一般只用来清零，按字节赋值

*/

#include<string>
#include<iostream>

extern int IsPrime(int);

/*
*0~9是个数划分为三个三位数，其中两个数分别是两倍和三倍于另一个数。
*
*采用穷举法，分别给三位数按倍率关系赋初值，然后在判断是否满足互不相同的条件，
*如果采取先分分成三个三位数在判断关系是否满足的方法的话，在分成三个三位数一步很难实现。
*/
void devide()
{
	int nums[10];
	int p[3];
	int flag = 1;

	for ( p[0] = 102; p[0] <= 329; p[0]++)
	{
		memset(nums, 0, sizeof(int)*10);

		for (int i = 0; i < 3; i++)		//分别给三个三位数按倍数关系赋值
		{
			p[i] = (i + 1)*p[0];
			int mid = p[i];
			while (mid)					//给每位三位数各个位计数，计数值大于一了就不满主条件
			{
				if (++nums[mid % 10] > 1)
					flag = 0;
				mid /= 10;
			}
		}
		if (flag)
			std::cout <<p[0]<<"    "<<p[1]<<"    "<<p[2]<<std::endl;
		flag = 1;

	}
}

void SumOfPrime()
{
	int n = 0;
	int k = 0;
	int sum = 0;

	std::cout << "input n(n<=500)" << std::endl;
	if ((std::cin >> n) && n > 0 && n <= 500)
	{
		for (int i = n; i > 1 && k < 10; i--)
			if (IsPrime(i))
			{
				k++;
				sum += i;
				std::cout << i << "    " ;
			}
		std::cout<< "sum = " << sum << std::endl;
	}
}

bool LeapYear(int y)
{
	if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
		return true;
	else
		return false;
}

/*
*输入日期查看当天是休息日还是工作日
*“三天打鱼两天晒网”
*/
void WorkingOrRest()
{
	int Y;
	int M;
	int D;
	int sum_day = 0;
	int Md[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};//闰年每个月的天数

	std::cout << "input YYYY-MM-DD : ";
	if (scanf("%4d-%2d-%2d", &Y, &M, &D) == 3)
	{
		printf("%4d-%2d-%2d\n", Y, M, D);

		int leap = LeapYear(Y) ? 1 : 0;							   //当前输入年份是否为闰年

		if ((M == 2) && (leap == 0) && (D > 28))						   //当前平年二月份是否合法（细过滤）
		{
			printf("invalid input \n");
			return;
		}

		if (Y < 1990 || 12 < M || M < 1 || D > Md[M-1] || D < 0)	//输入年份是否有效，或者月份和天数是否合法
		{
			printf("invalid input \n");
			return;
		}

		for (int i = 1990; i < Y; i++)
			sum_day += LeapYear(i) ? 366 : 365;

		for (int i = 1; i < M; i++)
			sum_day += i == 2 ? 28 + leap : Md[i - 1];

		sum_day += D;
	}

	if (sum_day % 5 > 0 && sum_day % 5 < 4)
		std::cout << "   He is working\n";
	else
		std::cout << "   He is having a rest\n";
}

//统计输入的各类型字符数量
void Counter()
{
	char ch = ' ';
	int space = 0;
	int newline = 0;
	int other = 0;

	while ((ch = getchar()) != '#')
	{
		if (ch == ' ')
			space++;
		else if (ch == '\n')
			newline++;
		else
			other++;
	}

	std::cout << "space = " << space <<
		"    newline = " << newline <<
		"    other = " << other << std::endl;
}


void Transpose()
{
	int matrix[10][10];
	int n = 0;
	int x = 1;

	std::cout << "Input n:";
	if (scanf("%d", &n) == 1)
	{
		std::cout << "Input " << n << "*" << n << " matrix:" << std::endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				matrix[i][j] = x++;
				std::cout << matrix[i][j] << "  ";
			}
			std::cout << std::endl;
		}

		std::cout << "The transpose matrix is: "<< std::endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				std::cout << matrix[j][i] << "  ";
			std::cout << std::endl;
		}

	}
}
