#include<stdio.h>
#include<math.h>
using namespace std;

//定期存款计算
void caculate_deposit() {
	double rate, capital, deposit;
	int years;
	printf("please enter ：rate, years, capital\n");
	scanf("%lf,%d,%lf",&rate, &years, &capital);
	printf("rate = %f, years = %d, capital = %f\n", rate,years,capital);
	deposit = rate*capital*years + capital;
	printf("deposit = %.3f\n", deposit);
}

//4位整数拆分
void resolution() {
	int n, a, b;
	printf("please enter integer n has 4 bit\n");
	a = n / 100;
	b = n % 100;

}

//正负余数计算
void reminder() {

}

void roots() {
	printf("quadratic equation with one unknown\n");
	float a, b, c;
	scanf("%f,%f,%f",&a, &b, &c);
	printf("x1 = %.4f \n", -b / 2 * a + sqrt(b * b - 4 * a*c) / 2 * a);
	printf("x2 = %.4f \n", -b / 2 * a - sqrt(b * b - 4 * a*c) / 2 * a);
}