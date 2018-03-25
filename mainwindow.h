/* ******************************************************************************************
 * This Program was created by Ridwan Afwan Karim Fauzi (www.github.com/ridwanakf)
 * You can use this program for free, but you can't delete this watermark and/or the license.
 * ******************************************************************************************
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidgetItem>
#include <QObject>
#include <QAbstractButton>
#include <QString>
#include <QHeaderView>
#include <string>
#include "rootfinderbase.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public RootfinderBase {
    Q_OBJECT

private:
    Ui::MainWindow *ui;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setEquation(std::string persamaan, std::string turunan);
    double funcNewtonRaphson();
    void outNewtonRaphson();
    double funcSecant();
    void outSecant();

public slots:
    void updateNewtonRaphson();
    void updateSecant();
};

#endif // MAINWINDOW_H
