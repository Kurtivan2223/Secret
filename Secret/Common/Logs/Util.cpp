#include <iostream>
#include "Util.h"
#include "../define.h"

std::string Util::GetDateTime(uint8 c)
{
	time_t now = time(0);
	struct tm tstruct;
	char buffer[80] = { 0 };
	tstruct = *localtime(&now);
	switch (c)
	{
	case DATE_LEVEL_TIMESTAMP:
		strftime(buffer, sizeof(buffer), "%Y-%m-%d %X", &tstruct);
		break;
	case DATE_LEVEL_DATE:
		strftime(buffer, sizeof(buffer), "%Y-%m-%d", &tstruct);
		break;
	case DATE_LEVEL_YEAR:
		strftime(buffer, sizeof(buffer), "%Y", &tstruct);
		break;
	case DATE_LEVEL_MONTH:
		strftime(buffer, sizeof(buffer), "%m", &tstruct);
		break;
	case DATE_LEVEL_DAY:
		strftime(buffer, sizeof(buffer), "%d", &tstruct);
		break;
	case DATE_LEVEL_HOUR:
		//TODO:
		break;
	case DATE_LEVEL_MINUTE:
		//TODO:
		break;
	case DATE_LEVEL_SECOND:
		//TODO:
		break;
	}
	return std::string(buffer);
}

int Util::strtobool(std::string s)
{
	//TODO:
	return 0;
}