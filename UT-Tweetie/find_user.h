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
#ifndef posts_h
#define posts_h
typedef struct posts posts;
struct posts
{
    int userid;
    char *context;
    int postid;
    char *likeid;
    int likecount;
    posts *next;
};
#endif
void find_user(char *givenusername , user *head ,posts *phead , int usercount , int postscount)
{
    int result = 1 , count = 1 , userID = 0 ;
    user *curr = head ;
    char *copyusername=(char*)malloc(strlen(givenusername));
    strcpy(copyusername , givenusername);
    for ( count = 1 ; count < usercount+1 ; count++ )
    {
        char *availableusername=(char*)malloc(strlen(givenusername));
        strcpy(availableusername,curr->username);
        result = strcmp(copyusername , availableusername);
        if (result==0)
        {
            break;
        }
        else
            curr=curr->next;
        free(availableusername);
    }
    free(copyusername);
    if (result==0)
    {
        printf("Username: %s\n" , curr->username );
        userID=curr->userid;
        int flag = 0 , i = 1;
        posts *pcur=phead;
        while (i <= postscount)
        {
            if (pcur->userid=userID)
            {
                if (pcur->postid==0)
                {
                    pcur=pcur->next;
                    i++;
                }
                else
                {
                    printf("Post ID = %d\n", pcur->postid);
                    printf("[%s]\n" , pcur->context);
                    printf("%d likes\n" , pcur->likecount);
                    pcur=pcur->next;
                    flag++;
                    i++;
                }
            }
            else
            {
                pcur=pcur->next;
                i++;
            }
        }
        if (flag==0)
        {
            printf("\nhomie ain't got any posts yet!\nHe's stucking, LOL!\n");
        }
    }
}