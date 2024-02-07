#pragma once
#include <iostream>
#include <math.h>
#include <time.h>
#include <string>
#include "../define.h"

class Util {
public:
	static std::string GetDateTime(uint8 c);
	static int strtobool(std::string s);
};

enum DateTimeLevel : uint8 {
	DATE_LEVEL_TIMESTAMP = 1,
	DATE_LEVEL_DATE = 2,
	DATE_LEVEL_YEAR = 3,
	DATE_LEVEL_MONTH = 4,
	DATE_LEVEL_DAY = 5,
	DATE_LEVEL_HOUR = 6,
	DATE_LEVEL_MINUTE = 7,
	DATE_LEVEL_SECOND = 8,

	DATE_LEVEL_INVALID = 0xFF
};