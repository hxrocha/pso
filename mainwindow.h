#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:


    void on_btnSair_clicked();

    void on_btnCalcular_clicked();

    void on_btnPlotar_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
