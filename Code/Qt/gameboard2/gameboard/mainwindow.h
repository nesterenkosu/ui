#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    qint32 is_first;
    QGridLayout *grid;

private slots:
    void on_pushButton_clicked();
    void on_gameboard_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
