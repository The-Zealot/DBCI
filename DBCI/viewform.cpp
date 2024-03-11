#include "viewform.h"
#include "ui_viewform.h"

ViewForm::ViewForm(QSqlDatabase &db, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ViewForm)
{
    ui->setupUi(this);

    _db = db;
    _db.open();
    _model = new QSqlTableModel(this, _db);

    _model->setTable("players");
    ui->tableView->setModel(_model);

    _model->select();

    _model->setHeaderData(DB_TABLE_PLAYER_NAME, Qt::Horizontal, "Имя");
    _model->setHeaderData(DB_TABLE_PLAYER_RACE, Qt::Horizontal, "Раса");
    _model->setHeaderData(DB_TABLE_PLAYER_DATE, Qt::Horizontal, "Дата");
    _model->setHeaderData(DB_TABLE_PLAYER_CLASS, Qt::Horizontal, "Класс");
    _model->setHeaderData(DB_TABLE_PLAYER_GUILD, Qt::Horizontal, "Гильдия");
    _model->setHeaderData(DB_TABLE_PLAYER_REALM, Qt::Horizontal, "Реалм");
    _model->setHeaderData(DB_TABLE_PLAYER_STATUS, Qt::Horizontal, "Статус");
    _model->setHeaderData(DB_TABLE_PLAYER_FACTION, Qt::Horizontal, "Фракция");
    _model->setHeaderData(DB_TABLE_PLAYER_CHAR_ID, Qt::Horizontal, "ID");
    _model->setHeaderData(DB_TABLE_PLAYER_DESCRIPTION, Qt::Horizontal, "Описание");

    ui->labelBaseName->setText(_db.databaseName());
    ui->labelTableName->setText(_model->tableName());
    ui->tableView->hideColumn(DB_TABLE_PLAYER_ID);
    ui->tableView->setEditTriggers(QTableView::NoEditTriggers);
//    ui->tableView->setSortingEnabled(true);

    _db.close();
}

ViewForm::~ViewForm()
{
    delete _model;
    delete ui;
}
