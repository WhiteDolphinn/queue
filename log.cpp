#include "log.h"
#include <time.h>
#include <string.h>
#include <stdlib.h>

static void close_log_file_txt();

FILE* get_log_file(const char* resolution)
{
    time_t timer = time(NULL);
    struct tm* time = localtime(&timer);

    char filename[100] = "";

    sprintf(filename, ".log/%d_%d_%d_%d_%d_log%s", time->tm_hour, time->tm_min, time->tm_mday,
            time->tm_mon+1, time->tm_year+1900, resolution);


    static FILE* log_file_txt = nullptr;
    static FILE* log_file_dot = nullptr;

    if(!strcmp(resolution, ".txt"))
    {
        //printf("resolution = %s\n", resolution);
        if(log_file_txt == nullptr)
        {
            if(PRINT_IN_CONSOLE == 0)

            {
                log_file_txt = fopen(filename, "w");
                atexit(close_log_file_txt);
            }
            else
                log_file_txt = stdout;
        }
        return log_file_txt;
    }

    if(!strcmp(resolution, ".dot"))
    {
        if(log_file_dot == nullptr)
        {
                log_file_dot = fopen(filename, "w");
                //atexit(close_log_file_dot);
        }
        return log_file_dot;
    }

    return nullptr;
}

void close_log_file_txt()
{
    FILE* ftxt = get_log_file(".txt");
    fclose(ftxt);
}
