#ifndef IMPORTFORM_H
#define IMPORTFORM_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlQuery>
#include "defines.h"

namespace Ui {
class ImportForm;
}

class ImportForm : public QWidget
{
    Q_OBJECT

public:
    explicit ImportForm(QSqlDatabase &db, QWidget *parent = nullptr);
    ~ImportForm();

    void selectTable();

private:
    Ui::ImportForm *ui;
    QSqlDatabase _db;
    QSqlQuery* _query;
    QSqlTableModel* _model;
};

#endif // IMPORTFORM_H
