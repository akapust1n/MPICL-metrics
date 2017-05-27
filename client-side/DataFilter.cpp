#include "DataFilter.h"
#include <QMessageBox>

DataFilter::DataFilter(Info* _info)
    : info(_info)
{
}

bool DataFilter::checkMinMaxTime(double minTime, double MaxTime)
{
    if (minTime >= MaxTime) {

        return false;
    }
    return true;
}
