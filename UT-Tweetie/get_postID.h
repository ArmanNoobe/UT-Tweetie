#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int get_postID(char *text)
{
    int x=0 ;
    sscanf(text, "%d", &x);
    return x;
}