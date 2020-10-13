#include "LoggerAPI.h"

#include <stdio.h>
#include <string.h>

void LOGGER(const Levels level, const char *message, const char *filename, const char *time, unsigned int line, const char *func)
{
    LogStruct log = { };
    char temp[SIXTEEN_BYTES] = "";

    strncpy(log.level, LevelsLUT[level], strlen(LevelsLUT[level]));
    strncpy(log.filename, filename, strlen(filename));
    strncpy(log.message, message, strlen(message));
    strncpy(log.time, time, strlen(time));
    sprintf(temp, "%d", line);
    strncpy(log.line, temp, strlen(temp));
    strncpy(log.function, func, strlen(func));
    printf("%s - %s - %s - %s - %d\n", LevelsLUT[level], message, filename, time, line);
    enqueue_log(&log);
}

void enqueue_log(const LogStruct *log)
{
    printf("%lu", sizeof(*log));
}