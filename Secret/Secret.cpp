#include <iostream>
#include "Log.h"
#include "Configuration.h"
#include "DB.h"

int main()
{
    Database Database;
    Configuration Configuration;
    Log::Logging(LOG_LEVEL_INFO, "App is Starting");
    Configuration.Configure();
    Database.Initialize();

    return 0;
}