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
void show_posts (posts *phead, int userID, int postscount)
{
    int flag = 0 , i = 1;
    posts *curr=phead;
    while (i <= postscount)
    {
        if (curr->userid=userID)
        {
            if (curr->postid==0)
            {
                curr=curr->next;
                i++;
            }
            else
            {
            printf("Post ID = %d\n", curr->postid);
            printf("[%s]\n" , curr->context);
            printf("%d likes\n" , curr->likecount);
            curr=curr->next;
            flag++;
            i++;
            }
        }
        else
        {
            curr=curr->next;
            i++;
        }
    }
    if (flag==0)
    {
        printf("\nno posts? start posting rn by using post command!\n");
    }
}