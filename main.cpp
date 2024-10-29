#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <iostream>

#include <string>
#include <fstream>
#include "Group.h"
#include "Student.h"
#include "funcs.h"
#include <windows.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    MainWindow w;
    w.show();
    return a.exec();
}
