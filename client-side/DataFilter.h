#ifndef DATAFILTER_H
#define DATAFILTER_H
#include "Info.h"

class DataFilter
{
public:
    DataFilter(Info *_info);
    bool checkMinMaxTime(double minTime, double MaxTime);
    private:
        Info *info;
};

#endif // DATAFILTER_H
