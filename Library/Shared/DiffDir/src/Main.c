#include <stdio.h>
#include "../include/CalcMean.h"

int main(void)
{

	double v1, v2, m;
	v1 = 5.5;
	v2 = 7.9;

	m = mean(v1, v2);

	printf("The mean of %3.2f and %3.2f is %3.2f\n", v1, v2, m);
	return 0;
}

