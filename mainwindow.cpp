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
    ui->fileTypeCombo->addItems(gen.getFileTypes());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_generateButton_clicked()
{
    gen.setFilePath(QFileDialog::getSaveFileName(this, QObject::tr("Save File"), QObject::tr("/Documents/untitled.html"), QObject::tr("Web Page (*.html)")));

    QList<QString> ids = gen.getID();
    QList<QString> headers = gen.getHeaders();
    for (int i = 0; i < ids.size(); i++){
        gen.loadSelected(ids[i], headers[i]);
    }
}

void MainWindow::on_bookComboBox_currentIndexChanged(const QString &arg1)
{
    gen.setBooks(arg1);
}


void MainWindow::on_tradRadio_clicked()
{
    gen.setTraditional(true);
    qDebug() << gen.getTraditional();
}

void MainWindow::on_repeatRadio_clicked()
{
    gen.setTraditional(false);
    qDebug() << gen.getTraditional();
}
