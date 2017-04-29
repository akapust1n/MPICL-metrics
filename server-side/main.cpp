#include <iostream>
#include <MainMenu.h>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QString>
#include <QDebug>
#include <zdb/zdb.h>

ConnectionPool_T pool;

int main()
{

    URL_T url = URL_new("mysql://localhost/mpicl?user=root&password=1111");

    pool = ConnectionPool_new(url);
    ConnectionPool_start(pool);

    MainMenu mainMenu;
    mainMenu.readMenuItem();
    

    return 0;;
}
