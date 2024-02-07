#include "DB.h"
#include "Log.h"


void Database::Initialize()
{
	Log::Logging(LOG_LEVEL_INFO, "Connecting To the Database");
	Construct();
	Connect();
}

void Database::Connect()
{
	SQLAllocHandle(SQL_HANDLE_ENV,
		SQL_NULL_HANDLE,
		&_hEnv);
	SQLSetEnvAttr(_hEnv,
		SQL_ATTR_ODBC_VERSION,
		(SQLPOINTER)SQL_OV_ODBC3_80,
		SQL_IS_INTEGER);
	SQLAllocHandle(SQL_HANDLE_DBC,
		_hEnv,
		&_hDbc);
	SQLRETURN _return = SQLDriverConnectA(_hDbc,
		NULL,
		(SQLCHAR*)Construct().c_str(),
		SQL_NTS,
		NULL,
		0,
		NULL,
		SQL_DRIVER_COMPLETE);
	if (SQL_SUCCEEDED(_return))
		Log::Logging(LOG_LEVEL_DATABASE, "Connected To Server");
	else
	{
		SQLCHAR _sstate[6], _errmsg[256];
		SQLINTEGER _nerr;
		SQLSMALLINT _len;
		SQLGetDiagRecA(SQL_HANDLE_DBC,
			_hDbc,
			1,
			_sstate,
			&_nerr,
			_errmsg,
			sizeof(_errmsg),
			&_len);
		std::string _temp(reinterpret_cast<char*>(_errmsg), size_t(sizeof(_errmsg)));
		Log::Logging(LOG_LEVEL_ERROR, _temp);
	}
}

std::string Database::Construct()
{
#ifdef _TESTING
	return "DRIVER=MySQL Server;SERVER" + _db._host + ";DATABASE=" + _db._dbname + ";USER=" + _db._user + ";PASSWORD" + _db._pwd + ";PORT=" + _db._port + ";";
#else
	return "DRIVER={MySQL ODBC 8.0 ANSI Driver};SERVER" + _db._host + ";DATABASE=" + _db._dbname + ";USER=" + _db._user + ";PASSWORD" + _db._pwd + ";PORT=" + _db._port + ";";
#endif
}

void Database::Query(const std::string _query)
{
	if (_hDbc == NULL)
	{
		Log::Logging(LOG_LEVEL_ERROR, "Connection not Established!");
		return;
	}
	SQLHSTMT _hStmt;
	SQLAllocHandle(SQL_HANDLE_STMT,
		_hDbc,
		&_hStmt);
	SQLExecDirectA(_hStmt,
		(SQLCHAR*)_query.c_str(),
		SQL_NTS);

	//TODO: Query Results
	// *
	// *

	SQLFreeHandle(SQL_HANDLE_STMT,
		_hStmt);
}

void Database::Shutdown()
{
	SQLDisconnect(_hDbc);
	SQLFreeHandle(SQL_HANDLE_DBC, _hDbc);
	SQLFreeHandle(SQL_HANDLE_ENV, _hEnv);
}