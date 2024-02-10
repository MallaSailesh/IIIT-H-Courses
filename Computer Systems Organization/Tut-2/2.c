#include<stdio.h>

extern int fun(int a, int b);

int main()
{
	int a, b, ret_val;
	printf("#########################################################\n");
	printf("Program to find if given two numbers, which of them is greater\n");
	printf("The program returns 1 if the first number is greater than or equal to the second and 0 otherwise\n");
	printf("#########################################################\n");
	printf("Give two numbers as inputs:\n");
	scanf("%d %d", &a, &b);
	ret_val = fun(a,b);
	printf("Answer: %d\n", ret_val);
}
