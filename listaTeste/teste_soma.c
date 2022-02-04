#include <stdio.h>

void soma (int a, int b) {
	a = a+b;
	printf("X = %d\n", a);
}

int main()
{
	int A, B;
	scanf("%d", &A);
	scanf("%d", &B);
	soma(A, B);
	return 0;
}