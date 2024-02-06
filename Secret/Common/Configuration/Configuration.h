#pragma once

#define TESTING

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include "../define.h"

class Configuration {
public:
	void Read(const std::string& _filename);
	typedef struct DatabaseInfo {
		std::string _host;
		std::string _user;
		std::string _pwd;
		std::string _dbname;
#ifdef TESTING
		std::string _port;
#else
		int _port;
#endif
	}DatabaseInfo;

	std::string Value(const std::string& _section, const std::string& _key) const;
	void Configure();

	DatabaseInfo _db;

private:
	std::map<std::string, std::string> DATA;
	void Trim(std::string& _str);
};