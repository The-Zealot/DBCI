#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <htmlparser.h>
#include <textwriter.h>
#include <databasewriter.h>
#include <QMessageBox>

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

private slots:
    void on_pushButton_clicked();

    void on_buttonSave_clicked();

private:
    Ui::MainWindow *ui;
    HtmlParser* _parser;
    ArmoryData _ad;
    QSqlDatabase _db;
};
#endif // MAINWINDOW_H
