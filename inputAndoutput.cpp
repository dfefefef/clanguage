/*

	printf();输出函数
	printf(格式控制字符串, 输出值参数表);
	格式控制字符串中“%d”转换说明符与参数值类型相匹配
	格式字符：
			d:decimal		int型
			u:unsigned		无符号int型
			f:float			小数形式输出float,double型 包含6位小数（printf无法区分float与double，
							编译器自动将float转换成double型）
			e:exponent		以标准指数形式输出float，double
							10.3 = 1.030000e+001
			c:character		字符类型
							字符类型数据可以以 %c 字符格式输出字符；也可以以 %d 输出对应ASCII值
	格式修饰:
			l：		加在d，u前输出long型
			h：		加在d，u前输出short型
	数据位宽修饰:
			"%m.nf"(右对齐)	m：数据最小位宽，包括小数点
							n：数据精度
			"%-m"(左对齐)

	------------------------------------------------------

	scanf();输入函数
	scanf(格式控制字符串, 输入地址表);
	从输入缓冲区按格式读入数据，返回读取成功的数据个数,格式控制字符串中格式与参数表格式匹配，否则不能正确读入scanf返回0，
	没有成功读取输入缓冲区的数据时候，缓冲区的数据依然存在（可能会被后面的读入函数误读入）。

	输入格式控制
	分隔符：
			\n,\t,\0和其他非法字符
			或者达到输入位宽
	格式控制：
			scanf("%2d%2d", &a, &b);指定输入数据的宽度
			不能指定输入数据的精度，如：%5.2f
			不能包含\n换行符
			格式控制字符串中的普通字符原样输入
	格式修饰符：
			l：		加d、u前输入long型
					加f、e前输入double型
			L：		加f、e前输入long double型
			h：		加d前输入short型
			*：		读入并忽略



	
	------------------------------------------------

	getchar();从输入缓冲区读入一个字符并返回，
	putchar();输出一个字符到输出缓冲器
	比scanf()和printf()速度快




	------------------------------------------------

	逻辑关系语句
	int x=0,y=5,z=3;
	5. while(z-->0 && ++x<5)// z>0不满足时不再做后面的判断，所以++x不执行；
	6. {
	7. y=y-1;
	8. }
	9. printf("%d,%d,%d\n",x,y,z);


*/
#include<stdio.h>
#include<math.h>

void printff() {
	int i ;
	if(scanf("%d", &i) == 1)
		printf("%2d\n", i);
}

//输入两个时间点：小时，分钟	计算他们的时间间隔
void timeBtime() {
	int h1, h2, m1, m2, h3 = 0, m3 = 0;

	printf("please input time one (hour,minute)\n");
	scanf("%d%*c%d",&h1, &m1);
	if (h1 > 23 || h1 < 0 || m1 < 0 || m1>60)
		printf("time one out of range!\n");

	printf("please input time tow (hour,minute)\n");
	scanf("%d%*c%d", &h2, &m2);
	if (h2 > 23 || h2 < 0 || m2 < 0 || m2>60)
		printf("time tow out of range!\n");

	//h1,m1保存较大的时间点
	if (h1 < h2 || (h1 == h2 && m1 < m2))
	{
		h1 = h2 - h1;
		h2 = h2 - h1;
		h1 = h2 + h1;
		m1 = m2 - m1;
		m2 = m2 - m1;
		m1 = m2 + m1;
	}
	m3 = h1 - h2;
	if (m1 < m2)
	{
		m3 = 60 + m1 - m2;
		--h3;
	}
	else
		m3 = m1 - m2;

	printf("%d hours, %d minutes \n",h3, m3);
}