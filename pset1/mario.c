#include<cs50.h>
#include<stdio.h>
int main(void)
{   int i;
    do{    
       printf("height:");
        i=GetInt();
        printf("\n");    
       }while(i<1&&i>23);
int j;
    for(j=0;j<=i;j++)
    { int k;
        for( k=0;k<=i-j-1;k++)
        printf(" ");
        for(k=0;k<=j+1;k++)
        printf("#");
        printf("\n");
    }

    return 0;
}