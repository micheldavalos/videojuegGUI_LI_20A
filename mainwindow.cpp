#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFileDialog>
#include <QTableWidgetItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->mostrar_tabla,
            SIGNAL(clicked()),
            this,
            SLOT(click_mostrar_tabla()));
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
    // v.mostrar();
    ui->salida->clear();
    for (size_t i = 0; i < v.size(); i++) {
        Personaje &p = v[i];

        ui->salida->insertPlainText(
                    "Nombre: " +
                    QString::fromStdString(p.getNombre()) +
                    "\n");
        ui->salida->insertPlainText(
                    "Tipo: " +
                    QString::fromStdString(p.getTipo()) +
                    "\n");
        ui->salida->insertPlainText(
                    "Salud: " +
                    QString::number(p.getSalud()) +
                    "\n");

        ui->salida->insertPlainText(
                    "Fuerza: " +
                    QString::number(p.getFuerza()) +
                    "\n");
    }
}

void MainWindow::on_actionGuardar_triggered()
{
    qDebug() << "guardar";
    QString ubicacion =
            QFileDialog::getSaveFileName(
                this,
                "Guardar personajes",
                "C:\\",
                "Texto (*.txt)");
    qDebug() << ubicacion;
    v.respaldar(ubicacion.toStdString());
}

void MainWindow::on_actionAbrir_triggered()
{
    qDebug() << "abrir";
    QString ubicacion =
            QFileDialog::getOpenFileName(
                this,
                "Abrir archivo",
                ".",
                "Texto (*.txt)");
    v.recuperar(ubicacion.toStdString());
}

void MainWindow::click_mostrar_tabla()
{
    qDebug() << "mostrar tabla";
    vector<Personaje> personajes;
    for (size_t i = 0;i < v.size(); i++) {
        personajes.push_back(v[i]);
    }
    personajes_tabla(personajes);
}

void MainWindow::personajes_tabla(const vector<Personaje> &personajes)
{
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setRowCount(int(personajes.size()));

    QStringList labels;
    labels << "Nombre" << "Tipo" << "Salud" << "Fuerza";
    ui->tableWidget->setHorizontalHeaderLabels(labels);

    for (size_t i = 0; i < personajes.size(); i++) {
        const Personaje &p = personajes[i];

        QTableWidgetItem *nombre =
                new QTableWidgetItem(
                    QString::fromStdString(p.getNombre()));
        QTableWidgetItem *tipo =
                new QTableWidgetItem(
                    QString::fromStdString(p.getTipo()));
        QTableWidgetItem *salud =
                new QTableWidgetItem(
                    QString::number(p.getSalud()));
        QTableWidgetItem *fuerza =
                new QTableWidgetItem(
                    QString::number(p.getFuerza()));

        ui->tableWidget->setItem(i, 0, nombre);
        ui->tableWidget->setItem(i, 1, tipo);
        ui->tableWidget->setItem(i, 2, salud);
        ui->tableWidget->setItem(i, 3, fuerza);
    }


}
