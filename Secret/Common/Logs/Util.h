#pragma once
#include <iostream>
#include <math.h>
#include <time.h>
#include <string>
#include "../define.h"

class Util {
public:
	static std::string GetDateTime(uint8 c)
	{
		time_t now = time(0);
		struct tm tstruct;
		char buffer[80] = { 0 };
		tstruct = *localtime(&now);
		switch (c)
		{
		case 1:
			strftime(buffer, sizeof(buffer), "%Y-%m-%d %X", &tstruct);
			break;
		case 2:
			strftime(buffer, sizeof(buffer), "%Y-%m-%d", &tstruct);
			break;
		case 3:
			strftime(buffer, sizeof(buffer), "%Y", &tstruct);
			break;
		case 4:
			strftime(buffer, sizeof(buffer), "%m", &tstruct);
			break;
		case 5:
			strftime(buffer, sizeof(buffer), "%d", &tstruct);
			break;
		}

		return std::string(buffer);
	}
};

enum DateTimeLevel : uint8 {
	DATE_LEVEL_TIMESTAMP = 1,
	DATE_LEVEL_DATE = 2,
	DATE_LEVEL_YEAR = 3,
	DATE_LEVEL_MONTH = 4,
	DATE_LEVEL_DAY = 5,


	DATE_LEVEL_INVALID = 0xFF
};

Util Utils;