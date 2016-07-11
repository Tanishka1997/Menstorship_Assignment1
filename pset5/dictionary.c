/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>

#include "dictionary.h"
#include <ctype.h>
#include <stdio.h>
#include <sys/resource.h>
#include <sys/time.h>
#include<string.h>
#include<stdlib.h>

/**
 * Returns true if word is in dictionary else false.
 */
typedef struct node{
    char word[LENGTH+1];
    struct node* next;
} node;

node* hashtable[27];


int hash(const char* p){
    char a=tolower(p[0]);
    int b=a-97;
    return b;
}
bool check(const char* word)
{node* temp=hashtable[hash(word)];
int len = strlen(word);
    char* lower_word = malloc(sizeof(char)*(len+1));
if (lower_word == NULL)
    {
    return false;
    }
 for (int i = 0; i < len; i++)
    {
        if (isupper(word[i]))
        {  
            lower_word[i] = tolower(word[i]);
        }
        else
        {
            lower_word[i] = word[i];
        }
    }
 lower_word[len] = '\0';
while(temp!=NULL)
{
    if(strcmp(lower_word,temp->word)==0){
    free(lower_word);
    return true;
}
    else
    {
    temp=temp->next;}
}
    free(lower_word);
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
int lines=0;
bool load(const char* dictionary)
{   node* new_node;
    int ch;
    FILE* fp=fopen(dictionary,"r");
    if(fp==NULL)
    return false;
    while ((ch = fgetc(fp)) != EOF)
    {
        if(ch == '\n')
        {
            lines++;
            ch = '\0';
        }
    }
    
    
    fseek( fp, 0, SEEK_SET );
    while(1)
    {
    new_node=malloc(sizeof(node));
    fscanf(fp,"%s",new_node->word);
    if(feof(fp))
    {free(new_node);
    break;
    }
    int i=hash(new_node->word);
    new_node->next=hashtable[i];
    hashtable[i]=new_node;
    }
     fclose(fp);
    return true;

   
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    
    return lines;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{node* temp;
    for(int i=0;i<26;i++){
        node* n=hashtable[i];
        temp=NULL;
        while(n!=NULL)
        {temp=n;
        n=n->next;
        free(temp);
        }
    }
    return true;
}
