#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

int main()
{
	int fib[10];
	int n;
	int i;

	fib[0] = 1;
	fib[1] = 1;

	printf("Zadaj kolko cisel chces z fibonaciho postupnosti ? ");
	scanf("%d", &n);

	for (i = 2; i < n; i++)
		fib[i] = fib[i - 1] + fib[i - 2];

	for (i = 0; i < n; i++)
		printf("%d \n", fib[i]);

	system("pause");
	return 0;
}
