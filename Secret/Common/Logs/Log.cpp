#include "Log.h"
#include <iostream>
#include "Util.h"

void Log::Logging(uint8 s, std::string m)
{
	std::string _temp;
	std::string _timestamp = Utils.GetDateTime(DATE_LEVEL_TIMESTAMP);
	uint8 _cli;
	switch (s)
	{
	case 1:
		_temp = "[INFO] " + _timestamp + " - " + m;
		_cli = CLI_LEVEL_NORMAL;
		break;
	case 2:
		_temp = "[FATAL] " + _timestamp + " - " + m;
		_cli = CLI_LEVEL_ABNORMAL;
		break;
	case 3:
		_temp = "[ERROR] " + _timestamp + " - " + m;
		_cli = CLI_LEVEL_ABNORMAL;
		break;
	case 4:
		_temp = "[WARNING] " + _timestamp + " - " + m;
		_cli = CLI_LEVEL_ABNORMAL;
		break;
	case 5:
		_temp = "[DEBUG] " + _timestamp + " - " + m;
		_cli = CLI_LEVEL_NORMAL;
		break;
	case 6:
		_temp = "[UNKNOWN] " + _timestamp + " - " + m;
		_cli = CLI_LEVEL_ABNORMAL;
		break;
	case 7:
		_temp = "[TRACE] " + _timestamp + " - " + m;
		_cli = CLI_LEVEL_NORMAL;
		break;
	}
	CLI(_cli, _temp);
	Write(_temp);
}

void Log::Write(std::string m)
{
	if (!std::filesystem::exists("Logs"))
		std::filesystem::create_directory("Logs");
	std::string _file = "Logs/Report_" + Utils.GetDateTime(DATE_LEVEL_DATE) + ".log";
	std::ofstream _buffer(_file.c_str(), std::ios::out | std::ios::app);
	if (!_buffer.is_open())
		CLI(CLI_LEVEL_ABNORMAL, "[FATAL] " + Utils.GetDateTime(DATE_LEVEL_TIMESTAMP) + " - Something Went Wrong With Loggers File Handling!");
	if (!_buffer.fail())
		CLI(CLI_LEVEL_ABNORMAL, "[FATAL] " + Utils.GetDateTime(DATE_LEVEL_TIMESTAMP) + " - Something Went Wrong When Writing Logs at Log File!");	
	_buffer << m << "\n";
	_buffer.close();
}

void Log::CLI(uint8 c, std::string m)
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