#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef user_h
#define user_h
typedef struct user user;
struct user
{
    char *username;
    char *password;
    int userid;
    user *next;
};
#endif
void new_user(char *givenusername , char *givenpassword , user **head ,int usercount)
{
    user *newhead = (user*)malloc(sizeof(user));
    user *last = *head; 
    int i = usercount;
    newhead->username=givenusername;
    newhead->password=givenpassword;
    i++;
    newhead->userid=i;
    newhead->next = NULL;
    if (*head == NULL)
    {
       *head = newhead;
       return;
    } 
    while (last->next != NULL)
        last = last->next;
    last->next = newhead;
    return;
}