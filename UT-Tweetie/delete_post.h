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
int delete_post(posts* phead , int userID , int postscount , int postID)
{
    int j = 1 , i = 1;
    posts *curr=phead;
    posts *prev=phead;
    while (i <= postscount)
    {
        if (curr->userid==userID)
        {
            if (curr->postid==postID)
            {
                break;
            }
            else
            {
                curr=curr->next;
                i++;
            }
        }
        else
        {
            curr=curr->next;
            i++;
        }
    }
    if (i>postscount)
    {
        return 0;
    }
    else
    {
        for(j=1;j<i;j++)
        {
            prev=prev->next;
        }
        prev->next=prev->next->next;
        return 1;
    }
}