#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _parser = new HtmlParser(this);

    connect(_parser, &HtmlParser::parsed, this, &MainWindow::loadNext);

//    _parser->getCharacterData("Негрофиллер", "10");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadNext()
{
//    _parser->loadPage(QUrl("https://cp.pandawow.me/armory/char-10-3256.html"));

    ArmoryData ad = _parser->getArmory();

    qDebug() << "Name:" << ad.name();
    qDebug() << "Guild:" << ad.guild();
    qDebug() << "ID:" << ad.id();
}


void MainWindow::on_pushButton_clicked()
{
    QString name = ui->lineEdit->text();
    QString realm = "10";
    qDebug() << "Find character:" << name;
    _parser->getCharacterData(name);
}

