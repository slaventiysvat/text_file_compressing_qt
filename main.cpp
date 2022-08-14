#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QLabel>
#include <QTranslator>
#include <iostream>
#include <stack>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "compressin_algorithm_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    MainWindow w;
    w.setWindowTitle("CD - 2");
    w.show();
    return a.exec();
}
