#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int tamanho (char v[]) {
    int n = 0;
    while(v[n] != '\0'){
        n++;
    }
    return n;
}

char converte (char v[]) {
    char *string, msc; 
    string = v;
    int x = tamanho(v);

    for (int i = 0; i < x; ++i)
    {
        msc = toupper(*string);
        printf("%c", msc);
        string++;
        
    }
    
    //return string;
}


int main()
{
    char *str;

    //str = "ailan Silva";
    scanf("%c", &str);

    converte(str);

    return 0;
}