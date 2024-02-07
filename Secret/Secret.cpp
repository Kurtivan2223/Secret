#include <iostream>
#include "Common/Logs/Log.h"
#include "Common/Configuration/Configuration.h"

int main()
{
    Log Logs;
    Configuration Configuration;

    Logs.Logging(LOG_LEVEL_INFO, "App is Starting");
    Logs.Logging(LOG_LEVEL_INFO, "Setting Configuration");
    Configuration.Configure();
#ifdef _DEBUG
    Logs.Logging(LOG_LEVEL_DEBUG, "HOST: " + Configuration._db._host);
    Logs.Logging(LOG_LEVEL_DEBUG, "USERNAME: " + Configuration._db._user);
    Logs.Logging(LOG_LEVEL_DEBUG, "PASSWORD: " + Configuration._db._pwd);
    Logs.Logging(LOG_LEVEL_DEBUG, "DBNAME: " + Configuration._db._dbname);
    Logs.Logging(LOG_LEVEL_DEBUG, "PORT: " + Configuration._db._port);
#endif

    Logs.Logging(LOG_LEVEL_INFO, "Connecting To the Database");

    return 0;
}
