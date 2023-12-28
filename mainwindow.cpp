#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QFont>
#include <QFontDialog>
#include <QColorDialog>
#include <QColor>
#include <QPrintDialog>
#include <QPrinter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionnew_triggered()
{
    filePath = "";
    ui->textEdit->setText("");
}


void MainWindow::on_actionope_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,"Open file");
    QFile file(fileName);
    if(!file.open(QFile::ReadOnly | QFile::Text) )
    {
        QMessageBox::warning(this,"..","File not open");
        return;
    }
    QTextStream in(&file);
    QString text =in.readAll();
    ui->textEdit->setText(text);
    file.close();

}


void MainWindow::on_actionsave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,"Open file");
    QFile file(fileName);
    if(!file.open(QFile::WriteOnly | QFile::Text) )
    {
        QMessageBox::warning(this,"..","File not open");
        return;
    }
    QTextStream out(&file);
    QString text =ui->textEdit->toPlainText();
    out << text;
    file.flush();
    file.close();

}


void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}


void MainWindow::on_actioncopy_triggered()
{
    ui->textEdit->copy();
}


void MainWindow::on_actionpaste_triggered()
{
    ui->textEdit->paste();
}


void MainWindow::on_actionFont_triggered()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok,this);
    if(ok)
    {
        ui->textEdit->setFont(font);
    }
    else
        return;

}


void MainWindow::on_actioncolor_triggered()
{
    QColor color = QColorDialog::getColor(Qt::white,this,"Choose color");
    if(color.isValid())
    {
        ui->textEdit->setTextColor(color);
    }
}


void MainWindow::on_actionbackgroundcolor_triggered()
{
    QColor color = QColorDialog::getColor(Qt::white,this,"Choose color");
    if(color.isValid())
    {
        ui->textEdit->setTextBackgroundColor(color);
    }
}


void MainWindow::on_actionBackgroundColor_textEdit_triggered()
{
    QColor color = QColorDialog::getColor(Qt::white,this,"Choose color");
    if(color.isValid())
    {
        ui->textEdit->setPalette(color);
    }
}


void MainWindow::on_actionPrint_triggered()
{
    QPrinter printer;
    printer.setPrinterName("Desired prineter name");
    QPrintDialog dailog(&printer,this);
    if(dailog.exec() == QDialog::Rejected) return;
    ui->textEdit->print(&printer);
}

