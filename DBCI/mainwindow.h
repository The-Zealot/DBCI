#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <htmlparser.h>

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

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    HtmlParser* _parser;
};
#endif // MAINWINDOW_H
