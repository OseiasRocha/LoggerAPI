#ifndef LOGGERAPI_LOGGERAPI_H
#define LOGGERAPI_LOGGERAPI_H

/**
 * Macros
 * */
#define LOG(level, message) LOGGER(level, message, __FILE__, __TIME__, __LINE__, __FUNCTION__)

/**
 * Constants
 * */

#define MAX_SIZE_STRING 256
#define SIXTEEN_BYTES 16
#define EIGHT_BYTES 8

typedef enum Levels
{
    EInfo,
    ETrace,
    EWarning,
    EError,
    EAlert
} Levels;

typedef struct LogStruct
{
    char level[SIXTEEN_BYTES];
    char message[MAX_SIZE_STRING];
    char filename[MAX_SIZE_STRING];
    char time[EIGHT_BYTES];
    char line[SIXTEEN_BYTES];
    char function[SIXTEEN_BYTES];
} LogStruct;

static const char *LevelsLUT[5] = {"Info",
                                   "Trace",
                                   "Warning",
                                   "Error",
                                   "Alert"};

void LOGGER(const Levels level, const char *message, const char *filename, const char *time, const unsigned int line,
            const char *func);

void enqueue_log(const LogStruct *log);

#endif //LOGGERAPI_LOGGERAPI_H
