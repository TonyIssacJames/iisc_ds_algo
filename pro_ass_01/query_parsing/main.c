#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "query_parsing.h"

int main()
{
    char query[MAX_QUERY_STRING_SIZE];
    char c = 'c';

    while(c != 'x')
    {
        printf("Enter x to exit ENTER for continue\n");
        scanf("%c",&c);
        if(c == 'x')
        {
            printf("You pressed x exiting\n");
            break;
        }
        printf("ENTER your Query\n");
        gets(query);


        if(get_query_cmd(query, &gQuery_Parsed))
        {
            printf("Found a Valid Query Command\n");
        }
        else
        {
            printf("Input string does not match a valid Query pattern\n");
        }

        printf("cmd = %d\n", (int)gQuery_Parsed.cmd);
        printf("count = %d\n", (int)gQuery_Parsed.count1);

        for(int i =0; i<gQuery_Parsed.count1; i++)
        {
            printf("temp_data = %s\n", gQuery_Parsed.temp_data[i]);
        }
    }
    return 0;
}
