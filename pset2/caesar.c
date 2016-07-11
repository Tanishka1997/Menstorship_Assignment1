#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int main(int argc,string argv[])
{
    if(argc!=2)
       { printf("enter 1 argument and recomplile\n");return 1;}
        
        
          unsigned long int k = atoi(argv[1]);
            string s=GetString();
            int i;
            for(i=0;i<strlen(s);i++)
            {  if(isalpha(s[i]))
                { if(isupper(s[i]))
                    {int a=s[i];
                    s[i]=(char)((a+k-64)%26+64);
                    }
                  else
                   {int a=s[i];
                    s[i]=(char)((a+k-96)%26+96);
                    }
                                         
                    
                    
                }
            }
        
            puts(s);
        return 0;
    
    
}