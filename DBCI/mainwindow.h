#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <htmlparser.h>
#include <textwriter.h>
#include <databasewriter.h>
#include <QMessageBox>
#include "viewform.h"
#include "importform.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void loadNext();
    void showError();
    void lockSaveButton();
    void showImportForm();

private slots:
    void on_pushButton_clicked();

    void on_buttonSave_clicked();

    void on_buttonLoad_clicked();

private:
    Ui::MainWindow *ui;
    HtmlParser* _parser;
    ArmoryData _ad;
    ArmoryViewer _av;
    QSqlDatabase _db;
    ViewForm* _viewForm;
    ImportForm* _importForm;
};
#endif // MAINWINDOW_H
