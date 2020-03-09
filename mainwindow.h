#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "videojuego.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_agregar_clicked();

    void on_mostrar_clicked();

    void on_actionGuardar_triggered();

    void on_actionAbrir_triggered();

    void click_mostrar_tabla();

private:
    Ui::MainWindow *ui;
    Videojuego v;

    void personajes_tabla(const vector<Personaje> &personajes);
};
#endif // MAINWINDOW_H
