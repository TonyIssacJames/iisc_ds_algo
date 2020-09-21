#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "query_parsing.h"

Parsed_Query gQuery_Parsed; //global variable to hold the parsed query cmd input by user

char query_cmd_string[NUMBER_OF_TEMPLATES][MAX_QUERY_STRING_SIZE] = {
    "GET ALL STUDENTS REGISTERED FOR THE COURSE get_input",
    "GET ALL COURSES get_input HAS REGISTERED FOR",
    "GET ALL STUDENTS REGISTERED FOR THE COURSES get_input AND get_input",
    "GET NUMBER OF STUDENTS REGISTERED FOR get_input",
    "REGISTER STUDENT get_input FOR THE COURSE get_input",
    "UNREGISTER STUDENT get_input FOR THE COURSE get_input",
    "HAS STUDENT get_input REGISTERED FOR THE COURSE get_input ?",
    "GET ALL STUDENTS WHO HAVE REGISTERED FOR MORE THAN get_input COURSES",
    "GET A LIST OF ALL STUDENTS",
    "GET A LIST OF ALL COURSES",
    "GET ALL COURSES WHICH HAVE MORE THAN get_input STUDENTS"
};


bool do_query_match(char *org_ip_cmd, char *org_query_template, Parsed_Query *query_Parsed)
{
    char *ip_cmd[MAX_QUERY_STRING_SIZE];
    char *query_template[MAX_QUERY_STRING_SIZE];

    char query_cmd_words[MAX_WORDS_IN_TEMPLATE][20];
    int  wc = 0;
    const char delim[2] = " ";
    char *word;
    bool found_match = false;
    int i;
    const char *get_input = "get_input";

    /*we need to make new copies as str_stok modifies the string*/
    strcpy(ip_cmd, org_ip_cmd);
    strcpy(query_template, org_query_template);

    /*initialisation*/
    query_Parsed->count1 = 0; //no temp is added

    //printf("query_template = %s \n", query_template);
    //printf("ip_cmd = %s \n", ip_cmd);

    word = strtok(query_template, delim);
    strcpy(&query_cmd_words[wc][0], word);
    wc++;

    while(word != NULL)
    {
        word = strtok(NULL, delim);
        if(word)
        {
            strcpy(&query_cmd_words[wc], word);
            wc++;
        }
    }

    word = strtok(ip_cmd, delim);

    i = 0;
    while(word)
    {
        //printf("query_cmd_words[i] = %s len = %d i =%d \n", query_cmd_words[i], strlen(query_cmd_words[i]), i);
        //printf("word = %s len = %d i =%d \n", word, strlen(word), i);
        //printf("get_input = %s len = %d i =%d \n", get_input, strlen(get_input), i);

        if(!strcmp(&query_cmd_words[i],get_input))
        {
            printf("found_match: %d \n", 4);
            strcpy(&query_Parsed->temp_data[query_Parsed->count1++], word);
        }
        else
        {
            if(strcmp(word, &query_cmd_words[i]))
            {
                //printf("%s  %s: %d \n", word, &query_cmd_words[i], 4);
                found_match = false;
                break;
            }
            else
            {
                //printf("%s  %s: %d \n", word, &query_cmd_words[i], 5);
                found_match = true;
            }
        }

        i++;
        word = strtok(NULL, delim);
    }

    return found_match;
}

bool get_query_cmd(char *ip_cmd, Parsed_Query *query_Parsed)
{
    int tmplate;
    bool found_match = false;


    for(tmplate =0; tmplate < NUMBER_OF_TEMPLATES; tmplate++)
    {
        //DEBUG_PR(0, "tmplate = %d\n", tmplate);
        //DEBUG_PR(0, "ip_cmd = %s\n", ip_cmd);
        //printf("tmplate = %d\n", tmplate);
        //printf("ip_cmd = %s\n", ip_cmd);

        //printf("=====================================\n");
        if(do_query_match(ip_cmd, &query_cmd_string[tmplate][0], query_Parsed))
        {
            query_Parsed->cmd = (enum QueryCmd)tmplate;
            found_match = true;
            break;
        }
    }
    //printf("----------------------------------------\n");

    return found_match;
}
