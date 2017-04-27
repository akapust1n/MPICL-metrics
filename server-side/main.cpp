#include <iostream>
#include <MainMenu.h>
#include <QtSql/QSqlDatabase>

int main()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
     db.setDatabaseName("mpicl");
     db.setUserName("root");
     db.setPassword("1111");
     bool ok = db.open();
    MainMenu mainMenu;
    mainMenu.readMenuItem();
    

    return 0;;
}
