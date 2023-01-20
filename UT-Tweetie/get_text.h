#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *get_text (char *order)
{
    int i = 1 , count1 = 0 , count2 = 0;
    char *text = (char*)malloc(500);
    for ( i = 0 ; i < 500 ; i++ )
    {
        if (*(order+i)==' ')
        {
            break;
        }
        else
        {
            count1++;
        }
    }
    for ( i = count1 ; i < 500 ; i++)
    {
        if (*(order+i)=='\0')
        {
            *(text+count2-1)=*(order+i);
            break;
        }
        else
        {
            *(text+count2-1)=*(order+i);
            count2++;
        }
    } 
    text=realloc(text,count2);
    return text ;
}