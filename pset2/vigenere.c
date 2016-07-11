#include<cs50.h>
#include<ctype.h>
#include<stdio.h>
#include<string.h>
int main(int argc,string argv[])
{
    if(argc!=2)
    { printf("enter 1 argument and recomplile\n");return 1;}
    int i,j=0;
    string key=argv[1];
    for(i=0;i<strlen(key);i++)
    {
        if(!isalpha(key[i]))
        {printf("not valid key");return 1;}
    }
    string s=GetString();
    
    int n=strlen(key);
    for(i=0;i<strlen(key);i++)
    key[i]=toupper(key[i]);
    for(i=0;i<strlen(s);i++)
    { if(isalpha(s[i]))
        {
            if(isupper(s[i]))
            {  int a=s[i];
            int b=key[j];
            s[i]=(char) ((a+b-65-64)%26+64); 
             }
         else
          {
              int a=s[i];
            int b=key[j];
            s[i]=(char) ((a+b-65-96)%26+96); 
              
          }
         if(j<n-1)
         j++;
         else
         j=0;
        }    
    }
     puts(s);
     return 0;
    
}