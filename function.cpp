/*
	
	
	����������
		��������ʵ������һ�����ã��������ڴ棬��������������������в�������ƥ��ļ�⡣
		��������������δ���к�������ʱ�򣬲��ֱ�����֧�ֺ���������������������Ĭ�Ϸ���ֵΪint��������������׷�����ͻ��
		������������ȫ��Ҫ�ģ�������֮����ڵ���ʱ�򣬺�����������ܺõ������ˡ�

	main()������λ�ÿ�������

	���Լ�⣺
		void assert��int expression����expressionΪ�治��������Ϊ��ʱ�жϳ��򣬳��������asser.h�С�
		�����ڳ�����ԣ��������ڳ����ܣ���������debug����release�汾�в������ã�������������assert��䣩��
		ʹ�ö��ԣ�
			1.���ڼ��������ȷ��
			2.���ڲ��Բ����ܷ������²��ᷢ��
			3.���ڲ���Ӧ�÷�������

	ģ�黯�������
		��Ϣ����
		���̳��󣬽����̳���Ϊ������
		���ݳ��󣬳����������ͣ�����ֻ����ʩ���������ϵĲ������������ͣ������������ݷ�װ���������ⲻ�ɼ���ʵ����Ϣ���ء�
	
		ģ�黮�ֻ���׼��ģ���ڸ��ھۡ�ģ��֮������ԭ��
		ģ�黮��׼��:���ڹ��̳����ģ�黮�ַ������������ݳ����ģ�黮�ַ�����
				
*/

#include<stdio.h>
#include<math.h>


//��׳�
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


//�ҳ�����m=a��+b��+c������λ����
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
//�����Լ��
//�����������
//շת�������
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


//��������
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

//�ж��Ƿ�Ϊ����
int IsPrime(int a)
{
	for (int i = 2; i <= sqrt(a); i++)
		if (a%i == 0)
			return	0;
	return 1;
}

//�������ĺ�
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

//��ĸ������
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
			if (i + j >= length)	//��������Ϊ�ո񴦽����ַ�����
				ch = 'A' + i - abs(j - length);			//'A'-i Ϊ��ǰ�������������Ԫ��ֵ����һ��Ϊ��ǰλ�������ĵľ��룬
			else											//����Ԫ��ASCII��ֵ��ȥ������ڵ�ǰλ��ASCIIֵ
				ch = ' ';
			printf("%c",  ch);	
		}
		printf("\n");
	}
}

//sinx������ʵ��
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

	while (term >= 10e-5)  //����չ��
	{
		term = term*x*x / ((2 * count + 1) * 2 * count);
		sign = -sign;
		ans += sign*term;
		count++;
	}

	printf("count = %d, sin(%d) = %f \n", count, x, ans);
}

//a+aa+aaa+��+aa��a��n��a��
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