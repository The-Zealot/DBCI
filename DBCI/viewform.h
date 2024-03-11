#ifndef VIEWFORM_H
#define VIEWFORM_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlError>

#include "defines.h"

namespace Ui {
class ViewForm;
}

class ViewForm : public QWidget
{
    Q_OBJECT

public:
    explicit ViewForm(QSqlDatabase &db, QWidget *parent = nullptr);
    ~ViewForm();

private slots:
    void on_buttonUpdate_clicked();

private:
    Ui::ViewForm *ui;
    QSqlDatabase _db;
    QSqlTableModel* _model;
};

#endif // VIEWFORM_H
