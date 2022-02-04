#include <stdio.h>
#include <stdlib.h>


void intercala (int *v, int *w, int n) {
	for (int i = 0; i < (n*2); ++i)
	{
		printf("%d\n", v[i]);
		printf("%s\n", w[i]);
	}
}


int main()
{
	int *v;
	int *w;
	int n;

	scanf("%d", &n);
	v = malloc(n * sizeof(int));
	w = malloc(n * sizeof(int));

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &v);
	}

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &w);
	}

	intercala(v, w, n);

	return 0;
}