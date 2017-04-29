#include "FileShow.h"

#include <zdb/zdb.h>
#include <zdb/Connection.h>
#include <string>
#include <QString>

extern ConnectionPool_T pool;
FileShow::FileShow()
{

}

QStringList FileShow::listFiles()
{
    Connection_T con = ConnectionPool_getConnection(pool);
    QStringList result;


    ResultSet_T r = Connection_executeQuery(con,"select distinct filename from Tracks");
    while (ResultSet_next(r))
    {
         std::string temp = ResultSet_getString(r,1);
         result.append(QString::fromStdString(temp));
    }
    return  result;
}
