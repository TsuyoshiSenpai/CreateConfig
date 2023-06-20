#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void pathToHeaderButtonClicked();
    void pathToXMLButtonClicked();
    void generateXMLButtonClicked();
    void getStatus();

    QString pathToHeader;
    QString pathToXML;

    bool pathToHeaderIsSelected = false;
    bool pathToXMLIsSelected = false;

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
