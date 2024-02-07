#include "Log.h"
#include <iostream>
#include "Util.h"

void Log::Logging(uint8 s, std::string m)
{
	std::string _temp;
	std::string _timestamp = Util::GetDateTime(DATE_LEVEL_TIMESTAMP);
	int _cli = NULL;
	switch (s)
	{
	case LOG_LEVEL_INFO:
		_temp = "[INFO] " + _timestamp + " - " + m;
		_cli = CONSOLE_LOG_LEVEL_NORMAL;
		break;
	case LOG_LEVEL_FATAL:
		_temp = "[FATAL] " + _timestamp + " - " + m;
		_cli = CONSOLE_LOG_LEVEL_ABNORMAL;
		break;
	case LOG_LEVEL_ERROR:
		_temp = "[ERROR] " + _timestamp + " - " + m;
		_cli = CONSOLE_LOG_LEVEL_ABNORMAL;
		break;
	case LOG_LEVEL_WARN:
		_temp = "[WARNING] " + _timestamp + " - " + m;
		_cli = CONSOLE_LOG_LEVEL_ABNORMAL;
		break;
	case LOG_LEVEL_DEBUG:
		_temp = "[DEBUG] " + _timestamp + " - " + m;
		_cli = CONSOLE_LOG_LEVEL_NORMAL;
		break;
	case LOG_LEVEL_UNKNOWN:
		_temp = "[UNKNOWN] " + _timestamp + " - " + m;
		_cli = CONSOLE_LOG_LEVEL_ABNORMAL;
		break;
	case LOG_LEVEL_TRACE:
		_temp = "[TRACE] " + _timestamp + " - " + m;
		_cli = CONSOLE_LOG_LEVEL_NORMAL;
		break;
	case LOG_LEVEL_DATABASE:
		_temp = "[DATABASE] " + _timestamp + " - " + m;
		_cli = CONSOLE_LOG_LEVEL_NORMAL;
		break;
	}
	ConsoleLog(_cli, _temp);
	Write(_temp);
}

void Log::Write(std::string m)
{
	if (!std::filesystem::exists("Logs"))
		std::filesystem::create_directory("Logs");
	std::string _file = "Logs/Report_" + Util::GetDateTime(DATE_LEVEL_DATE) + ".log";
	std::ofstream _buffer(_file.c_str(), std::ios::out | std::ios::app);
	if (!_buffer.is_open())
		ConsoleLog(CONSOLE_LOG_LEVEL_ABNORMAL, "[FATAL] " + Util::GetDateTime(DATE_LEVEL_TIMESTAMP) + " - Something Went Wrong With Loggers File Handling!");
	if (!_buffer.fail())
		ConsoleLog(CONSOLE_LOG_LEVEL_ABNORMAL, "[FATAL] " + Util::GetDateTime(DATE_LEVEL_TIMESTAMP) + " - Something Went Wrong When Writing Logs at Log File!");
	_buffer << m << "\n";
	_buffer.close();
}

void Log::ConsoleLog(uint8 c, std::string m)
{
	switch (c)
	{
	case 0:
		std::cout << m << std::endl;
		break;
	case 1:
		std::cerr << m << std::endl;
		break;
	}
}