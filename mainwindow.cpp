#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
   ui->main_page->hide();
   ui->page_2->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->main_page->hide();
    ui->page_3->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->main_page->hide();
    ui->page_4->show();
}
