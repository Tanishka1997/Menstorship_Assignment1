#include<cs50.h>
#include<ctype.h>
#include<stdio.h>
#include<string.h>
int main(void)
{
   
   string name=GetString();
   
   int i,j=0;
   char e[50];
   for(i=0;i<strlen(name);i++)
   {
    if(!isalnum(name[i])&&name[i]!=' ')
     {printf("not valid");return 1;}
   }
   for(i=0;i<strlen(name);i++)
   {
       if(i==0)
      { char c=name[i];
       c=toupper(c);
        e[j]=c; j++; 
      }
       else
       {
           if(name[i-1]==' ')
          { char c=name[i];
           c=toupper(c);
          e[j]=c;j++;
                }
   
       }
       }
    puts(e);
    return 0;
}