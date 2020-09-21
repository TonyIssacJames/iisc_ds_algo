#include <stdio.h>
#include <stdlib.h>

#include "read_data.h"


int main()
{
    char line[100];
    char delim[3] = ",\n";
    FILE *ip_file = fopen("course_list.txt","r");

    if(ip_file == NULL)
    {
        printf("Error opening file course_list.txt\n");
        exit(-1);
    }

    read_course_list(ip_file, &delim);

    fclose(ip_file);

    ip_file = fopen("student_registration_list.txt","r");

    if(ip_file == NULL)
    {
        printf("Error opening file student_registration_list.txt\n");
        exit(-1);
    }

    read_student_registration_list(ip_file, &delim);

    fclose(ip_file);

    printf("Hello world!\n");

    return 0;
}
