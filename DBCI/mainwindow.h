#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <htmlparser.h>
#include <textwriter.h>
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

private slots:
    void on_pushButton_clicked();

    void on_buttonSave_clicked();

private:
    Ui::MainWindow *ui;
    HtmlParser* _parser;
    ArmoryData _ad;
};
#endif // MAINWINDOW_H
