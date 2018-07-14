#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "generation.h"

generation gen;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QList<QString> items = gen.getBooks();
    ui->bookComboBox->addItems(gen.getBooks());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_generateButton_clicked()
{
    QList<QString> ids = gen.getID();
    for (int i = 0; i < ids.size(); i++){
        gen.loadSelected(ids[i]);
    }
}

void MainWindow::on_bookComboBox_currentIndexChanged(const QString &arg1)
{
    gen.setStarting(arg1);
}
