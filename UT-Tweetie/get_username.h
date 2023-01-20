#include <stdio.h>
#include <string.h>
char *get_username(char *order)
{
    char *str=(char*)malloc(strlen(order));
    strcpy(str,order);
    char *username = strtok(str, " ");
    return username;
    free(str);
    free(username);
}