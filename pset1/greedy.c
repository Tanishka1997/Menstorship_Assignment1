#include<sc50.h>
#include<math.h>
#include<stdio.h>
int main (void)
{
    float f;
    do{
        printf("O hai! How much change is owed?");
        f=GetFloat();
    }while(f>=0);
}