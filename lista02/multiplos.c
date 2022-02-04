#include <stdio.h>
#include <stdlib.h>

void multiplo (int i, int f, int x) {
	int *p;
	p = &x;
    while(*p <= f && *p != 0) {
      if (*p == i) { 
        printf("%d\n" , *p);
        *p = *p+(*p/2);
      }
      else if (*p >= i) {
        printf("%d\n", *p);
        if(*p%2 == 0) *p = *p+(*p/2);
        else *p = *p+(*p/3);
      }
      else if (*p < i){
        *p = *p*2;
        }
    }
}
int main()
{
    int i, f, x;

    //i = 10;
    //f = 20;
    //x = 7;

    scanf("%d", &i);
    scanf("%d", &f);
    scanf("%d", &x);

    multiplo(i, f, x);

    return 0;
}