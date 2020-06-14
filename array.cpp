/*

������string.hͷ�ļ�
void *(memset)(void *s, int c, size_t n)
{
	const unsigned char uc = c;
	unsigned char *su;



	for (su = s; 0 < n; ++su, --n)
		*su = uc;
	return s;
}

memsetһ��ֻ�������㣬���ֽڸ�ֵ

*/

#include<string>
#include<iostream>

extern int IsPrime(int);

/*
*0~9�Ǹ�������Ϊ������λ���������������ֱ�����������������һ������
*
*������ٷ����ֱ����λ�������ʹ�ϵ����ֵ��Ȼ�����ж��Ƿ����㻥����ͬ��������
*�����ȡ�ȷֳַ�������λ�����жϹ�ϵ�Ƿ�����ķ����Ļ����ڷֳ�������λ��һ������ʵ�֡�
*/
void devide()
{
	int nums[10];
	int p[3];
	int flag = 1;

	for ( p[0] = 102; p[0] <= 329; p[0]++)
	{
		memset(nums, 0, sizeof(int)*10);

		for (int i = 0; i < 3; i++)		//�ֱ��������λ����������ϵ��ֵ
		{
			p[i] = (i + 1)*p[0];
			int mid = p[i];
			while (mid)					//��ÿλ��λ������λ����������ֵ����һ�˾Ͳ���������
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
*�������ڲ鿴��������Ϣ�ջ��ǹ�����
*�������������ɹ����
*/
void WorkingOrRest()
{
	int Y;
	int M;
	int D;
	int sum_day = 0;
	int Md[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};//����ÿ���µ�����

	std::cout << "input YYYY-MM-DD : ";
	if (scanf("%4d-%2d-%2d", &Y, &M, &D) == 3)
	{
		printf("%4d-%2d-%2d\n", Y, M, D);

		int leap = LeapYear(Y) ? 1 : 0;							   //��ǰ��������Ƿ�Ϊ����

		if ((M == 2) && (leap == 0) && (D > 28))						   //��ǰƽ����·��Ƿ�Ϸ���ϸ���ˣ�
		{
			printf("invalid input \n");
			return;
		}

		if (Y < 1990 || 12 < M || M < 1 || D > Md[M-1] || D < 0)	//��������Ƿ���Ч�������·ݺ������Ƿ�Ϸ�
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

//ͳ������ĸ������ַ�����
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
