#include<stdio.h>

extern int add(int a, int b);

int main()
{
	int a, b, ans;
	printf("#########################################################\n");
	printf("Program to find the sum of two numbers\n");
	printf("#########################################################\n");
	printf("Give two numbers as input: ");
	scanf("%d %d", &a, &b);
	ans = add(a,b);
	printf("Answer: %d\n", ans);
}
