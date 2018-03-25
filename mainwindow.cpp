#include <iostream>
#include <string>
#include <cmath>
#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->cariNewton,SIGNAL(clicked(bool)),this,SLOT(updateNewtonRaphson()));
    connect(ui->cariSecant,SIGNAL(clicked(bool)),this,SLOT(updateSecant()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setEquation(string persamaan, string turunan)
{
    setPersamaan(persamaan);
    setTurunan(turunan);
}

void MainWindow::updateNewtonRaphson()
{
    string persamaan = ui->persNewton->toPlainText().toStdString();
    string turunan = ui->deriveNewton->toPlainText().toStdString();
    double RAE = ui->raeNewton->value();
    double x0 = ui->x0Newton->value();
    int iterasi = ui->iterasiNewton->value();
    setx0(x0);
    setEquation(persamaan, turunan);
    setMaxRAE(RAE);
    setMaxIterasi(iterasi);
    outNewtonRaphson();
}

double MainWindow::funcNewtonRaphson()
{   double x0 = getx0();
    return (double)(x0 - (calcFunc(x0) / (calcDerivative(x0))));
}

void MainWindow::outNewtonRaphson()
{
    double RAE = 1000.0, x1;
    double maxRAE = getMaxRAE();
    int maxIterasi = getMaxIterasi();
    int i = 1;

    //ui->tableNewton->clear();
    while((RAE > maxRAE) && (i <= maxIterasi)){
            x1 = funcNewtonRaphson();
            setx1(x1);
            RAE = abs((getx1() - getx0())/(getx1()));

            //output ke tabel
            ui->tableNewton->setRowCount(i);
            ui->tableNewton->setItem(i-1,0,new QTableWidgetItem(tr("%1").arg(getx1())));
            ui->tableNewton->setItem(i-1,1,new QTableWidgetItem(tr("%1").arg(getx0())));
            ui->tableNewton->setItem(i-1,2,new QTableWidgetItem(tr("%1").arg(calcFunc(getx0()))));
            ui->tableNewton->setItem(i-1,3,new QTableWidgetItem(tr("%1").arg(calcDerivative(getx0()))));
            ui->tableNewton->setItem(i-1,4,new QTableWidgetItem(tr("%1").arg(RAE*100)));

            setx0(getx1());
            i++;
    }
}

void MainWindow::updateSecant()
{
    string persamaan = ui->persSecant->toPlainText().toStdString();
    double RAE = ui->raeSecant->value();
    double x0 = ui->x0Secant->value();
    double x1 = ui->x1Secant->value();
    int iterasi = ui->iterasiSecant->value();
    setx0(x0);
    setx1(x1);
    setPersamaan(persamaan);
    setMaxRAE(RAE);
    setMaxIterasi(iterasi);
    outSecant();
}

double MainWindow::funcSecant()
{   double x0 = getx0();
    double x1 = getx1();
    return (double)(x1 - ((calcFunc(x1) * (x1-x0)) / (calcFunc(x1) - calcFunc(x0))));
}

void MainWindow::outSecant()
{
    double RAE = 1000.0, x2;
    double maxRAE = getMaxRAE();
    int maxIterasi = getMaxIterasi();
    int i = 0;

    //ui->tableSecant->clear();
    while((RAE > maxRAE) && (i < maxIterasi)){
            x2 = funcSecant();
            setx2(x2);
            RAE = abs((getx2() - getx1())/(getx2()));

            //output ke tabel
            ui->tableSecant->setRowCount(i+1);
            ui->tableSecant->setItem(i,0,new QTableWidgetItem(tr("%1").arg(getx2())));
            ui->tableSecant->setItem(i,1,new QTableWidgetItem(tr("%1").arg(getx0())));
            ui->tableSecant->setItem(i,2,new QTableWidgetItem(tr("%1").arg(getx1())));
            ui->tableSecant->setItem(i,3,new QTableWidgetItem(tr("%1").arg(calcFunc(getx0()))));
            ui->tableSecant->setItem(i,4,new QTableWidgetItem(tr("%1").arg(calcFunc(getx1()))));
            ui->tableSecant->setItem(i,5,new QTableWidgetItem(tr("%1").arg(RAE*100)));

            setx0(getx1());
            setx1(getx2());
            i++;
    }
}

