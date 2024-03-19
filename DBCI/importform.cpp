#include "importform.h"
#include "ui_importform.h"

ImportForm::ImportForm(QSqlDatabase &db, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ImportForm)
{
    ui->setupUi(this);

    ui->comboBox->setCurrentIndex(0);

    _db = db;
    _db.open();
    ui->comboBox->addItems(_db.tables());
    connect(ui->comboBox, &QComboBox::currentTextChanged, this, &ImportForm::selectTable);

    _model = new QSqlTableModel(this);
    ui->tableView->setModel(_model);
    ui->tableView->setEditTriggers(QTableView::NoEditTriggers);

    selectTable();

    _db.close();

    ui->tabWidget->setCurrentIndex(0);
    ui->tabWidget_2->setCurrentIndex(0);

    this->setEnabled(false);
}

ImportForm::~ImportForm()
{
    delete _model;
    delete ui;
}

void ImportForm::selectTable()
{
    _db.open();
    _model->setTable(ui->comboBox->currentText());
    _model->select();
    _db.close();
}
