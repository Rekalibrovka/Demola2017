#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
using std::string;

#include <QProcess>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->SSH_Btn, SIGNAL(clicked(bool)),this,SLOT(ssh_connect()));
    connect(ui->Test_btn, SIGNAL(clicked(bool)),this,SLOT(ssh_connect_test()));
    connect(ui->Test1_btn, SIGNAL(clicked(bool)),this,SLOT(test_1()));

    //connect(&process, SIGNAL(readyReadStandardOutput()), this, SLOT(readData()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ssh_connect()
{
    string destination; //putty -ssh -P 22 demo@test.org -pw password
    destination = "plink.exe -ssh " + (ui->UserName->text()).toStdString() +
                                "@" + (ui->ServerIP->text().toStdString()) +
                                " -P " + (ui->ServerPort->text().toStdString()) +
                                " -pw " + (ui->UserPassword->text().toStdString());
    char *cstr = new char[destination.length() + 1];
    strcpy(cstr, destination.c_str());
    system(cstr);
    delete [] cstr;
}

void MainWindow::ssh_connect_test()
{
    string destination = "plink.exe -ssh -P 2222 root@192.168.1.3 -pw u22m3sxw && wget ftp://anonymous:u22m3sxw@192.168.1.2/100.MB > /dev/null";
    //string destination = "plink.exe -ssh root@192.168.1.3 -P 2222 -pw u22m3sxw";
    char *cstr = new char[destination.length() + 1];
    strcpy(cstr, destination.c_str());
    system(cstr);
    delete [] cstr;
}

//Test 1 (20 small files)

void MainWindow::test_1()
{

    QString app_location = "C:\\Program Files (x86)\\PuTTY\\plink.exe";
    QStringList arguments;
    arguments << "+ssh" << ""
              << "+P" << "22"
              << "+" << "USERNAME@linux-desktop.cc.tut.fi"
              << "+pw" << "PASSWORD";

    QString command = "plink.exe -ssh " + (ui->UserName->text()) +
                                "@" + (ui->ServerIP->text()) +
                                " -P " + (ui->ServerPort->text()) +
                                " -pw " + (ui->UserPassword->text());
    QString destination = "plink -ssh -P 2222 root@192.168.1.2 -pw u22m3sxw";

    QProcess process;
    process.start(command);
    //qint64 *pid = Q_NULLPTR;

    //process.startDetached(app_location, arguments, "\\", pid);
    //process.waitForFinished();
    //QString output = process.readAllStandardOutput();
    //pid = process.processId();
    //ui->cmd->insertPlainText((QString)(int)pid);
    //ui->cmd->setText((QString)(int)pid);
}

//Test 2 (1 big file)

//Draw graph

//Show results (ping, latency, avg speed)
