/*
	break��continue��forѭ���в��������ʽ����for���������ʽ����

*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<set>


int Taylor()
{
	 int n = 1, count = 1;
	 double e = 1.0;
	 double term = 1.0;
	 while (fabs(term) >= 0.2) //��ĩ���С
	{
		 term = term/n; //����ۼ���
		 e = e + term; //�ۼ�
		 n++; // ������һ��
		 count++; //ͳ���ۼ�����
	}
	printf("e = %f, count = %d\n", e, count);
	return 0;
}


//ʹ����ٷ�����winenr������
int ageOfwiener() {

	int i3, i4;
	std::set<int> iset = {};
	for (int i = 10; i < 22 ; i++)
	{
		i4 = i*i*i*i;
		i3 = i*i*i;
		while (i3) {
			if (iset.find(i3 % 10) == iset.end())
				iset.insert(i3 % 10);
			else
				break;
			i3 /= 10;
		}
		while (!i3&&i4) {
			if (iset.find(i4 % 10) == iset.end())
				iset.insert(i4 % 10);
			else
				break;
			i4 /= 10;
		}
		if (!i3&&!i4) {
			printf("age = %d    i^3 = %d    i^4 = %d \n", i, i*i*i, i*i*i*i);
			break;
		}
		iset = {};
	}
	return 0;
}

//��һ��int�����и���λ�����ֵĵ����ֽ��м���
void countAint() {
	unsigned long input = 0;
	int	count[10] = {0};
	if (scanf("%d", &input) == 1) {
		printf("input: %d\n", input);
		input = fabs(input);
		while (input)
		{
			count[input % 10]++;
			input /= 10;
		}
		for (int i = 0; i < 10; i++)
			printf("%d:%d\n", i, count[i]);
	}
}

//�������
void bonus() {
	int profit = 0;
	int bonus = 0;
	if (scanf("%d", &profit)==1) {
		bonus = profit % 100001 * 0.1
			+ ((profit % 200001 - 100000) < 0 ? 0 : (profit % 200001 - 100000)*0.075)
			+ ((profit % 400001 - 200000) < 0 ? 0 : (profit % 400001 - 200000)*0.05)
			+ ((profit % 600001 - 400000) < 0 ? 0 : (profit % 600001 - 400000)*0.03)
			+ ((profit % 1000001 - 600000) < 0 ? 0 : (profit % 1000001 - 600000)*0.015)
			+ ((profit - 1000000) < 0 ? 0 : (profit - 1000000)*0.01);
		printf("bonus=%ld\n", bonus);
	}
}