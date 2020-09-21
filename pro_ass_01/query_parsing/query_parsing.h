
#ifndef QUERY_PARSING_H
#define QUERY_PARSING_H

#include <stdbool.h>
#include "debug_help.h"

#define NUMBER_OF_TEMPLATES  11
#define MAX_QUERY_STRING_SIZE  70
#define MAX_WORDS_IN_TEMPLATE  15


enum QueryCmd {GET_STUDENTS_FOR_A_COURSE = 0,
                GET_COURSEs_FOR_A_STUDENT,
                GET_STUDENTS_FOR_TWO_COURSE,
                GET_NO_STUDENTS_FOR_A_COURSE,
                REGISTER_STUDENT_FOR_A_COURSE,
                UNREGISTER_STUDENT_FOR_A_COURSE,
                QUERY_HAS_STUDENT_REGISTERED_FOR_A_COURSE,
                GET_STUDENTS_REGISTEREN_FOR_N_COURSES,
                GET_LIST_OF_STUDENTS,
                GET_LIST_OF_ALL_COURSES,
                GET_COURSES_WITH_MORE_THAN_N_STUDENTS,
                UNDEFINED_COMMAND,
                };

typedef struct Parsed_Query_t{
    enum QueryCmd  cmd;
    char student_name[20];
    int course_no[2];
    int count1; //to track how many entry are made in temp_date
    char temp_data[3][20];
} Parsed_Query;

#if 1

bool do_query_match(char *ip_cmd, char *query_template, Parsed_Query *query_Parsed);
bool get_query_cmd(char *ip_cmd, Parsed_Query *query_Parsed);

#endif

extern char query_cmd_string[NUMBER_OF_TEMPLATES][MAX_QUERY_STRING_SIZE];
extern Parsed_Query gQuery_Parsed;

#endif // _QUERY_PARSING_H
