#pragma once
#include <iostream>
#include "../define.h"


class Database {
public:
    typedef struct SQLInfo {
        //TODO:
    }SQLInfo;
    void Connect();
private:
    SQLInfo _sf;
};