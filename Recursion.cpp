/*
*	尾递归和普通递归。尾递归：直接
*
*
*	局部变量和全局变量同名时，局部变量隐藏全局变量
*	
*	常量存储区：（只读存储区）代码和常量，“ ”
*	静态存储区：全局变量和静态变量等，数据形成发生在编译和链接的时候
*	动态存储区：随着语句块运行出现和消失的变量，包括函数返回地址，函数形参
*
*	存储类型声明关键字
*		auto：动态存储区，动态局部变量，由系统自动分配和释放内存。
*
*		static：静态存储区（注意：不随语句块运行出现或消失），
*				静态局部变量：运行时语句块进入不再初始化（static int a = 1，已在编译阶段完成）
*				没有初始化编译阶段编译器初始化为零一次。
*				静态全局变量：只能在本文件使用，有助于消除全局变量的缺陷。
*
*		extern：静态存储区，外部变量，不同文件之间共用的全局变量，提示编译器该变量在外部定义了。
*
*		register：寄存器变量（该声明具体是否起作用关键在于编译器，编译器根据优化结果具体选取需要保存在寄存器的变量）。
*	
*
*/


#include<iostream>

void TimesOfSounds()
{
	int sum = 0;
	int a = 0;
	int b = 0;
	int c = 0;
	int flag = 0;

	for (int i = 1; i <=  7*21; i++)
	{
		if (i % 5 == 0 && a < 21)
		{
			a++;
			flag++;
		}
		if (i % 6 == 0 && b < 21)
		{
			b++;
			flag++;
		}

		if (i % 7 == 0 && c < 21)
		{
			c++;
			flag++;
		}
		sum += flag > 0 ? 1 : 0;
		flag = 0;

	}

	printf("sum of sounds: %d\n", sum);
}

int AgeOfNth(int n)
{
	if (n == 1)
		return 10;
	else
		return 2 + AgeOfNth(n - 1);
}

void NumOf()
{
	int n;

	if (scanf("%d", &n) != 1 || n <= 1 || n > 5)
		printf("input n error\n");


}