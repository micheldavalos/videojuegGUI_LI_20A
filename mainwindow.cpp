#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_agregar_clicked()
{
    qDebug() << "agregar";

    QString nombre = ui->nombre->text();
    QString tipo = ui->tipo->text();
    int fuerza = ui->fuerza->value();
    int salud = ui->salud->value();

    qDebug() << nombre << tipo << fuerza << salud;

    Personaje p;
    p.setNombre(nombre.toStdString());
    p.setTipo(tipo.toStdString());
    p.setFuerza(fuerza);
    p.setSalud(salud);

    v.agregar(p);
}

void MainWindow::on_mostrar_clicked()
{
    v.mostrar();
}

void MainWindow::on_actionGuardar_triggered()
{
    qDebug() << "guardar";
}
