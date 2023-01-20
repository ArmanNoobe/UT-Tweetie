#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int function_check(char *function)
{
    int result=10;
    result=strcmp(function,"signup");
    if (result==0)
    {
        return 1;
    }
    else
    {
        result=strcmp(function,"login");
        if (result==0)
        {
            return 2;
        }
        else
        {  
            result=strcmp(function,"logout");
            if (result==0)
            {
                return 3;
            }
            else
            {
                result=strcmp(function,"info");
                if (result==0)
                {
                    return 4;
                }
                else
                {
                    result=strcmp(function,"find_user");
                    if (result==0)
                    {
                        return 5;
                    }
                    else
                    {
                        result=strcmp(function,"post");
                        if (result==0)
                        {
                            return 6;
                        }
                        else
                        {
                            result=strcmp(function,"like");
                            if (result==0)
                            {
                                return 7;
                            }
                            else
                            {
                                result=strcmp(function,"delete");
                                if (result==0)
                                {
                                    return 8;
                                }
                                else
                                {
                                    return 9;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
/*commands list;
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