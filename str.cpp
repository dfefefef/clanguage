/*
*	scanf()在以%d和%s读入字符串时，开始读入前会跳过空格制表符和回车等空白字符，再读入字符直到遇到这些字符结束
*	而gets()函数不会对空白字符进行处理，依然读入制表符和空格，而以换行符终止，即读入一行。并且读走回车符。
*	
*	
*	char *ptr = "hello man";，这里的字符串在常量存储区，所以ptr不能对其进行修改（只读存储区）
*	和char ch[] = "hello man";中的字符数组有存储区域上的差异。
	
	gets(),从标准输入读入字符串到对应字符数组，由于不能限制读入长度，容易造成缓冲区溢出
	fgets(目的字符数组缓冲区, 最大长度，文件流)
	strlen(,)
	strcpy(目的字符数组，源字符串)//
	strncpy(str1,str2,n)//
	strcat(str1,str2)//
	strncat(str1,str2,n)//指定了需要连接的字符串的大小，保证安全
	strcmp(str1,str2)//相等返回0，str1>str2返回负数，str1>str2返回正数。

*/

//从第十周开始

#include<string>

int _dl vs(char * a, ...)
{

}