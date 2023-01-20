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
posts *create_post(posts* head, char *text , int userID , int postscount)
{
    posts *curr = (posts*) malloc(sizeof(posts));
    curr->userid=userID;
    curr->context=text;
    curr->postid=(postscount+1);
    curr->likecount=0;
    curr->next = head ;
    head = curr;
    printf("post made succesfully!\n");
    return head;
}