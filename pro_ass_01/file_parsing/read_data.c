
#include "read_data.h"

int read_course_list(FILE *ip_file, const char *delim)
{
   char line[100];
   char *course_name;
   int course_no;


   while(fgets(line, 100, ip_file) != NULL)
   {
       //printf("%s",line);

        course_no    = atoi(strtok(line, delim));
        course_name  = strtok(NULL, delim);

        printf("%s: %d\n", course_name, course_no);
   }
}

int read_student_registration_list(FILE *ip_file, const char *delim)
{
   char line[100];
   char *student_name;
   int course_no;


   while(fgets(line, 100, ip_file) != NULL)
   {
       //printf("%s",line);

       student_name = strtok(line, delim);
       course_no    = atoi(strtok(NULL, delim));

       printf("%s: %d\n", student_name, course_no);
   }
}
