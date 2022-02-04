#include <stdio.h>

void separa() {
    int v[15];
    int v1[5];
    int v2[5];
    int c;
    int impar = 0;
    int par = 0;
    
    void imprime_par () {
        int x, y;
        for(x = 0; x < 5 && v1[x] != NULL; x++){
          printf("par[%d] = %d\n", x, v1[x]);
        }
        memset(v1, NULL, sizeof(v1));
    }
    
    void imprime_impar () {
        int x, y;
        for(y = 0; y < 5 && v2[y] != NULL; y++){
          printf("impar[%d] = %d\n", y, v2[y]);
        }
        memset(v2, NULL, sizeof(v2));
    }
    
    for (int i = 0; i < 15; ++i)
    {
      if(i == 10){
          par = 0;
          impar = 0;
      }
        scanf("%d", &v[i]);
        setbuf(stdin, NULL);
        fflush(stdin);
        if (v[i]%2 == 0)
        {   
            v1[par] = v[i];
            par++;
            if(par == 5) imprime_par();
        } else  {
          v2[impar] = v[i];
          impar++;
          if(impar == 5) imprime_impar();
        }
    
    }
    imprime_impar();
    imprime_par();
}

int main()
{
    
    separa();


    return 0;
}