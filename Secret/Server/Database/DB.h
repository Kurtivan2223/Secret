#pragma once
#include <iostream>
#include <windows.h>
#include <sql.h>
#include <sqlext.h>
#include <string>
#include "Configuration.h"
#include "Log.h"

class Database {
public:
	void Initialize();
	void Connect();
	void Query(const std::string _query);
	void Shutdown();
private:
	std::string Construct();
	Configuration::DatabaseInfo _db;
	SQLHENV _hEnv;
	SQLHDBC _hDbc;
};