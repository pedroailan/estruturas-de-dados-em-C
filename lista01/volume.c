#include <stdio.h>

float VolumeEsfera(float  x) {
	float volume, *r;

	volume = (4 * 3.1416 * (x*x*x)) / 3.0;
	 
	r = &volume;
	
	return *r;
}


int main()
{

	float x;
	float y;
	float z;
	
	scanf("%f", &x);
	scanf("%f", &y);
	scanf("%f", &z);
	
	printf("\n");
	printf("%.2lf\n", VolumeEsfera(x));
	printf("%.2lf\n", VolumeEsfera(y));
	printf("%.2lf", VolumeEsfera(z));

	return 0;
}