#include <stdio.h>
#include <string.h>
char *get_password(char *order)
{
    char *str=(char*)malloc(strlen(order));
    strcpy(str,order);
    char *username = strtok(str, " ");
    char *password = strtok(NULL, " ");
    return password;
    free(str);
    free(username);
    free(password);
}