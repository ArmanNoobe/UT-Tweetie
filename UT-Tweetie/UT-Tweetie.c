#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "check_ID.h"
#include "new_user.h"
#include "findID.h"
#include "function_check.h"
#include "create_post.h"
#include "show_posts.h"
#include "get_text.h"
#include "delete_post.h"
#include "get_postID.h"
#include "find_user.h"
#include "get_username.h"
#include "get_pass.h"
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
int main()
{
    user *initialhead=NULL;
    user *newhead=initialhead;
    posts *phead = NULL;
    int postscount = 0;
    int userID = 0, usercount = 0;
    int result = 9;
    printf("Welcome to UT-TWEETIE!");
    while (1)
    {
        char *function = (char *)malloc(strlen(function) * sizeof(char));
        char *order = (char *)malloc(strlen(order) * sizeof(char));
        char *givenusername = (char *)malloc(strlen(givenusername) * sizeof(char));
        char *givenpassword = (char *)malloc(strlen(givenpassword) * sizeof(char));
        printf("\n[SignIn]Type (login -space- your_username -space- your_password) command if you already are a part of our community in order to sign into your account!");
        printf("\n[SignUp]You don't have an account yet?\nType (signup -space- your_prefered_username -space- your_prefered_password) in order to join us quickly.\nRemmember to use small letters only, numbers and all of the characters are allowed!\n");
        result = 9;
        while (result != 0)
        {
            scanf("%s", function);
            gets(order);
            result = function_check(function);
            if (result == 9) // wrong command
            {
                printf("\nsorry but I don't get it, press any button and repeat plz?\n");
                getch();
                result = 0;
            }
            else if (result == 1) // signup
            {
                givenusername = get_username(order);
                givenpassword = get_password(order);
                if (check_ID(givenusername, givenpassword, &newhead) == 1)
                {
                    new_user(givenusername, givenpassword, &newhead, usercount);
                    usercount++;
                    printf("signup process completed, welcome to the party!!!\nnow press any button to go back and login to get int your account!\n");
                    getch();
                    result = 0;
                }
                else
                {
                    printf("username or password already exists!\npress any button to try again!\n");
                    getch();
                    result = 0;
                }
            }
            else if (result == 2) // login
            {
                givenusername = get_username(order);
                givenpassword = get_password(order);
                if (check_ID(givenusername, givenpassword, &newhead) == 2)
                {
                    printf("1\n");
                    printf("\nlogin successful!\n");
                    userID = find_ID(givenusername, givenpassword, &newhead);
                    free(function);
                    free(order);
                    int count = 1;
                    user *curr = newhead;
                    while (count < userID)
                    {
                        curr = curr->next;
                        count++;
                    }
                    printf("\nwelcome %s !\n", curr->username);
                    printf("\n[post]Type <post -space- (your_posts_context)> in order to post something and share ideas or thoughts or anything that you want!");
                    printf("\n[Delete a post]Type <delete -space- (your_posts_ID)> in order to delete one of your posts that you don't like it anymore! Don't forget that you can only delete your own posts!");
                    printf("\n[Info]Type <info> if you wanna see your accounts stats and data.");
                    printf("\n[Find a user]Type <find_user -space- (username_of_the_user_that_you_are_looking_for)> in order to find someone specific.");
                    printf("\n[Like a post]Type <like -space- (username_of_the_user_that_you_wanna_like_their_post) -space- (the_posts_ID)> in order to like a post.");
                    printf("\n[LogOut]Type <logout> command if you want to get out of your account!\n");
                    while (result < 12)
                    {
                        printf("\nHome page\n\n");
                        show_posts(phead, userID, postscount);
                        printf("\nawaiting your command!\n");
                        char *function = (char *)malloc(10);
                        char *order = (char *)malloc(500);
                        result = 9;
                        while (result < 11)
                        {
                            scanf("%s", function);
                            gets(order);
                            result = function_check(function);
                            if (result == 9)
                            {
                                printf("\nsorry but I don't get it, can u repeat plz?\n");
                                result = 11;
                            }
                            else if (result == 3) //<logout>
                            {
                                printf("\nLogout successful! press any button.\n");
                                result = 14;
                                getch();
                            }
                            else if (result == 4) //<info>
                            {
                                printf("Username: %s\nPassword: %s\nUserID: %d\n", curr->username, curr->password, curr->userid);
                                show_posts(phead, userID, postscount);
                                printf("press any button to return!");
                                getch();
                                result = 11;
                            }
                            else if (result == 5) // find user -username
                            {
                                givenusername = get_username(order);
                                find_user(givenusername, newhead, phead, usercount, postscount);
                                free(givenusername);
                                printf("\npress any button to return!\n");
                                getch();
                                result = 11;
                            }
                            else if (result == 6) // post - context
                            {
                                char *text = get_text(order);
                                phead = create_post(phead, text, userID, postscount);
                                postscount++;
                                phead = realloc(phead, sizeof(posts));
                                printf("%s\n", phead->context);
                                printf("press any button to return!\n");
                                getch();
                                result = 11;
                            }
                            else if (result == 7) // like -username -post id
                            {
                            }
                            else if (result == 8) // delete - post id
                            {
                                int postID = 0;
                                char *text = get_text(order);
                                postID = get_postID(text);
                                postID++;
                                if (delete_post(phead, userID, postscount, postID) == 1)
                                {
                                    printf("\npost deleted successfully!\n");
                                }
                                else
                                {
                                    printf("are you sure that this post even exists? or maybe is just isn't yours, idk there was a problem anyways!\n");
                                }
                                printf("press any button to return!");
                                getch();
                                result = 11;
                            }
                            else
                            {
                                printf("\nyou are already loged in , first logout with <logout> command!\n");
                                result = 11;
                            }
                            fflush(stdin);
                            free(function);
                            free(order);
                        }
                    }
                    result = 0;
                }
                else
                {
                    printf("\nsorry! I can't find you, or maybe there is another issue, try again!\n");
                    getch();
                    result = 0;
                }
                free(givenusername);
                free(givenpassword);
            }
            else // other commands
            {
                printf("\ncommand unavailable! first login or signup.\n press any button to try again!\n");
                getch();
                result = 0;
            }
            printf(".");
            fflush(stdin);
            printf(".");
            free(function);
            printf(".");
            free(order);
            printf(".");
            free(givenpassword);
            printf(".");
            free(givenusername);
            printf(".\n");
        }
    }
}
/*
commands list;
1]signup
2]login
3]logout
4]info(basic)
5]find_user(basic)
6]post
7]like
8]delete (post)
9]error
*/