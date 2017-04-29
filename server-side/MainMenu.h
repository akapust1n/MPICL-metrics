#ifndef MAINMENU_H
#define MAINMENU_H
#include <QVector>
#include <QString>
#include <QTextStream>
#include "FileHandler.h"
#include "FileShow.h"

class MainMenu
{
public:
    MainMenu();
    QVector<QString> menu;
    void readMenuItem();


private:

   void loadFile();
   void showExistingFiles();

private:
    QTextStream cout;
    QTextStream cin;
    int menuNumber;
    FileHandler fileHandler;
    FileShow fileShow;


};

#endif // MAINMENU_H
