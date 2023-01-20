#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef user_h
#define user_h
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
#endif
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
int find_ID(char *givenusername, char *givenpassword, user **head)
{
    int value = 1 ;
    user *curr = *head;
    printf(".");
    char *user=(char*)malloc(strlen(givenusername));
    strcpy(user,givenusername);
    char *pass=(char*)malloc(strlen(givenpassword));
    strcpy(pass,givenpassword);
    printf(".");
    while (curr!=NULL)
    {
        char *one=(char*)malloc(strlen(curr->username));
        strcpy(one,curr->username);
        if (strcmp(user,one)==0)
        {
            char *two=(char*)malloc(strlen(curr->password));   
            strcpy(two,curr->password);   
            if (strcmp(two,pass)==0)
            {
                return curr->userid;
                break;
            }
            else
                curr = curr->next;
            free(two);  
        }
        else
        {
            curr = curr->next;
        }
        free(one);
    }
    free(pass);
    free(user);
}