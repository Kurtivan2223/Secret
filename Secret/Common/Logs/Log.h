#pragma once
#include <fstream>
#include <windows.h>
#include "../define.h"

class Log
{
public:
	static void Logging(uint8 s, std::string m);
	static void Write(std::string m);
    static void CLI(uint8 c, std::string m);
};

enum LogLevel : uint8
{
    LOG_LEVEL_DISABLED = 0,
    LOG_LEVEL_INFO = 1,
    LOG_LEVEL_FATAL = 2,
    LOG_LEVEL_ERROR = 3,
    LOG_LEVEL_WARN = 4,
    LOG_LEVEL_DEBUG = 5,
    LOG_LEVEL_UNKNOWN = 6,
    LOG_LEVEL_TRACE = 7,

    LOG_LEVEL_INVALID = 0xFF
};

enum CliLevel : uint8
{
    CLI_LEVEL_NORMAL = 0,
    CLI_LEVEL_ABNORMAL = 1,

    CLI_LEVEL_INVALID = 0xFF
};