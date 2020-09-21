#ifndef DEBUG_HELP_H
#define DEBUG_HELP_H


#define DEBUG_PR(num, ...) do{\
            printf("%s: %d %s\t",__FILE__, __LINE__,##__VA_ARGS__);\
            }while(0)
#endif // DEBUG_HELP_H
