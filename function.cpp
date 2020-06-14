/*
	
	
	函数声明：
		函数声明实际上是一个引用，不分配内存，函数声明方便编译器进行参数类型匹配的检测。
		隐含函数声明：未进行函数声明时候，部分编译器支持函数隐含函数声明，并且默认返回值为int，这种情况下容易发生冲突。
		函数声明是完全必要的，当函数之间存在调用时候，函数声明就起很好的作用了。

	main()函数的位置可以任意

	断言检测：
		void assert（int expression）：expression为真不做动作，为假时中断程序，程序包含在asser.h中。
		仅用于程序调试，不能用于程序功能，即仅用于debug，在release版本中不起作用（编译器会跳过assert语句）。
		使用断言：
			1.用于检查假设的正确性
			2.用于测试不可能发生的事不会发生
			3.用于捕获不应该发生的事

	模块化程序设计
		信息隐藏
		过程抽象，将过程抽象为函数。
		数据抽象，抽象数据类型，定义只能由施加于数据上的操作的数据类型，将操作和数据封装起来，对外不可见，实现信息隐藏。
	
		模块划分基本准则：模块内高内聚、模块之间低耦合原则。
		模块划分准则:基于过程抽象的模块划分方法、基于数据抽象的模块划分方法。
				
*/

#include<stdio.h>
#include<math.h>


//求阶乘
long Fact(int n)
{
	long ret = 1;
	
	if (n==0)
	{
		return 1;
	}

	for (int i= 1; i <= n; i++)
	{
		ret = i*ret;
	}
	return ret;
}


//找出满足m=a！+b！+c！的三位整数
void threeAddnumber()
{
	int n;
	int a1;
	int a2;
	int a3;

	for (n = 100; n < 10000; n++)
	{
		a1 = n % 10;
		a2 = (n / 10) % 10;
		a3 = n / 100;

		if (Fact(a1) + Fact(a2) + Fact(a3) == n)
			printf("%d! + %d! + %d! = %d \n", a3, a2, a1, n);
	}

}
////////////////////////////////////////////////
//求最大公约数
//更相减损术：
//辗转相除法：
//
///////////////////////////////////////////////
int Gcd(int a, int b)
{
	while (a != b) {
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}
	return a;
}


//分数化简
void DefusingFractions()
{
	int a;
	int b;

	if (scanf("%d,%d", &a, &b)!=2)
		return ;

	if (a<1 || a>10000 || b<1 || b>10000)
	{
		printf("input num out of range!\n");
		return ;
	}

	printf("%d/%d\n", a / Gcd(a, b), b / Gcd(a, b));
}

//判断是否为素数
int IsPrime(int a)
{
	for (int i = 2; i <= sqrt(a); i++)
		if (a%i == 0)
			return	0;
	return 1;
}

//求素数的和
void SumOfPrimes()
{
	int a;
	int	sum = 0;

	if (scanf("%d", &a) != 1)
		return;

	for (int i = 2; i <= a; i++)
		if (IsPrime(i) == 1)
			sum += i;
	
	printf("sum = %d\n", sum);
}

//字母金字塔
void LetterPyramid()
{
	char ch;
	int length = 0;

	if (scanf("%c", &ch)!=1 || ch<'A' || ch>'Z')
	{
		return;
	}

	length = ch - 'A';

	for (int i = 0; i <= length; i++)
	{
		for (int j = 0; j <= length+i; j++)
		{
			if (i + j >= length)	//金字塔不为空格处进行字符设置
				ch = 'A' + i - abs(j - length);			//'A'-i 为当前金字塔层的中心元素值，后一项为当前位置离中心的距离，
			else											//中心元素ASCII码值减去距离等于当前位置ASCII值
				ch = ' ';
			printf("%c",  ch);	
		}
		printf("\n");
	}
}

//sinx函数的实现
void SinX()
{
	int x;
	double term;
	double ans = 0;
	int sign = 1;
	int count = 1;

	if (scanf("%d", &x) != 1)
		return;

	term = x;
	ans = term;

	while (term >= 10e-5)  //级数展开
	{
		term = term*x*x / ((2 * count + 1) * 2 * count);
		sign = -sign;
		ans += sign*term;
		count++;
	}

	printf("count = %d, sin(%d) = %f \n", count, x, ans);
}

//a+aa+aaa+…+aa…a（n个a）
void Caculateaaaa()
{
	int a;
	int n;
	int term;
	int ans = 0;
	
	if (scanf("%d,%d ", &a, &n) != 2)
		return;

	term = a;

	for (int i = 1; i <= n; i++)
	{
		ans += term;
		term = term*10 + a;
	}

	printf("ans = %d\n", ans);
}