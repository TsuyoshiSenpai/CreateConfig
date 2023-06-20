#include "mainwindow.h"
#include "headerparser.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pathToHeaderButton, &QPushButton::clicked, this, &MainWindow::pathToHeaderButtonClicked);
    connect(ui->pathToXMLButton, &QPushButton::clicked, this, &MainWindow::pathToXMLButtonClicked);
    connect(ui->generateXMLButton, &QPushButton::clicked, this, &MainWindow::generateXMLButtonClicked);

    ui->generateXMLButton->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::pathToHeaderButtonClicked()
{
    pathToHeader = QFileDialog::getOpenFileName(
        this,
        "Выберите файл system.h",
        QString(),
        "Header File (*.h)"
        );
    ui->pathToHeaderTextEdit->appendPlainText(pathToHeader);

    if(pathToHeader.isNull())
        pathToHeaderIsSelected = false;
    else
        pathToHeaderIsSelected = true;

    getStatus();
}

void MainWindow::pathToXMLButtonClicked()
{
    pathToXML = QFileDialog::getExistingDirectory(this, "Выберите папку для сохранения config.xml") + "/config.xml";
    ui->pathToXMLTextEdit->appendPlainText(pathToXML);

    if(pathToXML.isNull())
        pathToXMLIsSelected = false;
    else
        pathToXMLIsSelected = true;

    getStatus();
}

void MainWindow::generateXMLButtonClicked()
{
    HeaderParser parser(pathToHeader, pathToXML);
    QMessageBox msgBox;
    msgBox.setText("Файл сгенерирован!");
    msgBox.exec();
}

void MainWindow::getStatus()
{
    if(pathToHeaderIsSelected && pathToXMLIsSelected)
        ui->generateXMLButton->setEnabled(true);
}
