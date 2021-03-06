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
    void on_generateButton_clicked();

    void on_bookComboBox_currentIndexChanged(const QString &arg1);    
    void on_tradRadio_clicked();

    void on_repeatRadio_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
