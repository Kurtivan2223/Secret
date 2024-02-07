#include "Configuration.h"
#include "Log.h"

void Configuration::Read(const std::string& _filename)
{
	std::ifstream _file(_filename);
	std::string _line;

	std::string _csection;

	while (std::getline(_file, _line))
	{
		Trim(_line);

		if (_line.empty() || _line.at(0) == ';')
			continue;

		if (_line.at(0) == '[' && _line.back() == ']')
			_csection = _line.substr(1, _line.size() - 2);
		else
		{
			size_t _eposition = _line.find('=');
			if (_eposition != std::string::npos)
			{
				std::string _key = _line.substr(0, _eposition);
				std::string _value = _line.substr(_eposition + 1);
				Trim(_key);
				Trim(_value);

				DATA[_csection + "." + _key] = _value;
			}
		}
	}
}

std::string Configuration::Value(const std::string& _section, const std::string& _key) const
{
	auto _temp = DATA.find(_section + "." + _key);
	return (_temp != DATA.end()) ? _temp->second : "";
}

void Configuration::Configure()
{
	Log::Logging(LOG_LEVEL_INFO, "Setting Configuration");
	std::string _temp;
	std::string _file = "Settings.ini";
	if (std::filesystem::exists(_file))
	{
		Log::Logging(LOG_LEVEL_DEBUG, "Reading Config File");
		Read(_file);
		Log::Logging(LOG_LEVEL_DEBUG, "Done Reading Config File");
		_db._host = Value("DATABASE", "HOST");
		_db._user = Value("DATABASE", "USER");
		_db._pwd = Value("DATABASE", "PASSWORD");
		_db._dbname = Value("DATABASE", "DBNAME");
#ifdef _TESTING
		_db._port = Value("DATABASE", "PORT");
#else
#ifdef _RELEASE
		_db._port = std::stoi(Value("DATABASE", "PORT"));
#else
		std::string _tport = Value("DATABASE", "PORT");
		try
		{
			_db._port = std::stoi(_tport);
		}
		catch (const std::invalid_argument& _e)
		{
			_temp = _e.what();
			Log::Logging(LOG_LEVEL_FATAL, "Conversion error: " + _temp);
		}
		catch (const std::out_of_range& _e)
		{
			_temp = _e.what();
			Log::Logging(LOG_LEVEL_FATAL, "Conversion error: " + _temp);
		}
#endif
#endif
		Log::Logging(LOG_LEVEL_DATABASE, "HOST: " + _db._host);
		Log::Logging(LOG_LEVEL_DATABASE, "USERNAME: " + _db._user);
		Log::Logging(LOG_LEVEL_DATABASE, "PASSWORD: " + _db._pwd);
		Log::Logging(LOG_LEVEL_DATABASE, "DBNAME: " + _db._dbname);
		Log::Logging(LOG_LEVEL_DATABASE, "PORT: " + _db._port);
		Log::Logging(LOG_LEVEL_DEBUG, "Successfully Initialize Configuration");
	}
	else
	{
		Log::Logging(LOG_LEVEL_ERROR, "Configuration File can't be found!");
		exit(1);
	}
}

void Configuration::Trim(std::string& _str)
{
	size_t _first = _str.find_first_not_of(" \t\n");
	size_t _last = _str.find_last_not_of(" \t\n");
	_str = _str.substr(_first, (_last - _first + 1));
}