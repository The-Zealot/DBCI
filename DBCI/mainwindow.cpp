#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setFixedSize(this->size());

    _db = QSqlDatabase::addDatabase("QSQLITE");
    _db.setDatabaseName("db.db");

    _parser = new HtmlParser(this);

    _viewForm = new ViewForm(_db);

    connect(_parser, &HtmlParser::parsed, this, &MainWindow::loadNext);
    connect(_parser, &HtmlParser::failed, this, &MainWindow::showError);
    connect(_parser, &HtmlParser::failed, this, &MainWindow::lockSaveButton);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadNext()
{
//    _parser->loadPage(QUrl("https://cp.pandawow.me/armory/char-10-3256.html"));

    _ad = _parser->getArmory();

    ui->buttonSave->setEnabled(true);
    ui->labelIndicator->setText("Загружено!");
    ui->labelIndicator->setStyleSheet("color: green;");

    qDebug() << "Name:" << _ad.name();
    qDebug() << "Guild:" << _ad.guild();
    qDebug() << "ID:" << _ad.id();

    ui->editName->setText(_ad.name());
    ui->editGuild->setText(_ad.guild());
    ui->editID->setText(QString::number(_ad.id()));

    ui->editFaction->setText(_ad.faction("ru"));
    ui->editRace->setText(_ad.race("ru"));
    ui->editClass->setText(_ad.getClass("ru"));
}

void MainWindow::showError()
{
    ui->labelIndicator->setText("Ошибка!");
    ui->labelIndicator->setStyleSheet("color: red;");

    QMessageBox::warning(this, "Не найдено", _parser->lastError());
}

void MainWindow::lockSaveButton()
{
    ui->buttonSave->setEnabled(false);
}

void MainWindow::on_pushButton_clicked()
{
    ui->buttonSave->setEnabled(false);
    ui->labelIndicator->setText("Загрузка...");
    ui->labelIndicator->setStyleSheet("color: black;");
    ui->textEdit->clear();

    switch (ui->comboBox->currentIndex())
    {
    case 0:
        _ad.setRealm(3);
        break;
    case 1:
        _ad.setRealm(5);
        break;
    case 2:
        _ad.setRealm(10);
        break;
    }

    QString name = ui->lineEdit->text();
    QString realm = QString::number(_ad.realm());
    qDebug() << "Find character:" << name;
    qDebug() << "Current realm:" << _ad.realm();
    _parser->getCharacterData(name, realm);
}


void MainWindow::on_buttonSave_clicked()
{
    _ad.setDescription(ui->textEdit->toPlainText());
    _ad.setStatus(ArmoryData::Status(ui->comboBoxStatus->currentIndex()));

    DatabaseWriter dbWriter(&_db);
    dbWriter.write(_ad);

    ui->labelIndicator->setText("Сохранено!");
    ui->labelIndicator->setStyleSheet("color: green;");

    TextWriter writer;
    writer.setFile("cInfo.txt");
    qDebug () << "Write data in file:" << writer.write(_ad);
}


void MainWindow::on_buttonLoad_clicked()
{
    _viewForm->show();
}

