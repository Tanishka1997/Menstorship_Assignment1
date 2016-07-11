/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    if (n<0)
    return false;
    for(int i=0;i<n;i++)
    if(values[i]==value)
    return true;
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++){
            if(values[j]>values[j+1]){
            temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
        
            }
        }
    }
    return;
}