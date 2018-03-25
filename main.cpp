/* ******************************************************************************************
 * This Program was created by Ridwan Afwan Karim Fauzi (www.github.com/ridwanakf)
 * You can use this program for free, but you can't delete this watermark and/or the license.
 * ******************************************************************************************
 */

#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
