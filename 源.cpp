#include<iostream>
#include<string>
#include"stdio.h"
using namespace std;

void reverse_i();
void caculate_deposit();
void roots();
void printff();
void timeBtime();
int Taylor();
int ageOfwiener();
void countAint();
void bonus();
void threeAddnumber();
void DefusingFractions();
void SumOfPrimes();
void LetterPyramid();
void SinX();
void Caculateaaaa();
void TimesOfSounds();
void devide();
void SumOfPrime();
void WorkingOrRest();
void Counter();
void Transpose();
void ZZMatrix();
void SetValue();


/*
template<class T>
int* add(T& a, T& b) {
	int c = 0;
	int L = sizeof(a) / sizeof(a[0]);
	int d[L+1];
	for (int i = 0; i < L; i++) {
		d[i] = a[i] ^ b[i] ^ c;
		c = a[i] & b[i] + a[i] & c + b[i] & c;
	};
	d[L + 1] = c;
	return d;
}

int main() {
	int b[] = { 1,0,0,0,1,1,1,1,1,0,0 };
	int a[] = { 1,0,0,0,1,1,1,1,1,0,0 };
	int* c = add(a, b);
	cout<<c[0]<<endl;
	system("pause");
	return 0;
}
*/


//À¨ºÅÆ¥Åä
bool isValid(string s) {
	string ss = s;
	int top = 0;
	ss[top] = s[0];
	for (int i = 1; i < (int)s.length(); i++) {
		if (top == -1) { ss[++top] = s[i]; }
		else {
			if (ss[top] == '(' && s[i] == ')') top--;
			else if (ss[top] == '[' && s[i] == ']') top--;
			else if (ss[top] == '{' && s[i] == '}') top--;
			else ss[++top] = s[i];
		}
	}
	if (top == -1) return true;
	return false;
}

int main() {


	gets();
	//string sss = "[([([([([([])])])])])]";
	//printf("%d /n",isValid(sss));
	char key = 'c';
	while (key == 'c') {
		SetValue();
		printf("if continue please enter 'c'\n");
		scanf(" %c", &key);
	}

	system("pause");
	return 0;
}

