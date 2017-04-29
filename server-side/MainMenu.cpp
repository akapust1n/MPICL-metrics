#include "MainMenu.h"
#include <QTextStream>
#include <algorithm>

MainMenu::MainMenu()
    : cout(stdout)
    , cin(stdin)
{
    menu << (QString(">1) Load file"));
    menu << (QString(">2) Show "
                     "loaded file"));

    for (auto line : menu) {
        cout << line << "\n";
    }
    cout.flush();
}

void MainMenu::readMenuItem()
{

    cout << ">";
    cout.flush();
    cin >> menuNumber;
    switch (menuNumber) {
    case 1:
        loadFile();
        break;
    case 2:
        showExistingFiles();
        break;
    default:
        cout << "error Menu number\n";
    }
}

void MainMenu::loadFile()
{
    QString filename;
    cout << "Input filename: ";
    cout.flush();
    cin >> filename;
    fileHandler.loadFile(filename);
}

void MainMenu::showExistingFiles()
{
    cout << "Existing files: \n";
    cout.flush();
    QStringList list = fileShow.listFiles();
    std::for_each(list.begin(), list.end(), [=](QString _filename) {cout<<_filename<<"\n"; cout.flush(); });
}
