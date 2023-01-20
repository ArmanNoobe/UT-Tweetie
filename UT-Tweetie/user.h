#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct user user;
struct user
{
    char *username;
    char *password;
    int userid;
    user *next;
};