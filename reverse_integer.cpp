#include"stdio.h"
#include"math.h"

void reverse_i() {
	int i;
	int ri = 0;
	scanf("%d", &i);
	i = fabs(i);
	while (i) {
		int pop = i % 10;
		i /= 10;
		ri = ri * 10 + pop;
	}
	printf(" ri = %d\n",ri);
}