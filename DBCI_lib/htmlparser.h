#ifndef HTMLPARSER_H
#define HTMLPARSER_H

#include "DBCI_lib_global.h"

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QFile>
#include <armorydata.h>

class DBCI_LIB_EXPORT HtmlParser : public QObject
{
    Q_OBJECT

public:
    HtmlParser(QObject* parent);
    ~HtmlParser();

    QByteArray loadPage(QUrl url);
    QString getTagValue(QString page, QString tag, QString closeTag = ">");

    QStringList getCharacterData(const QString &name, QString realm = "10");
    ArmoryData getArmory();

public slots:
    void replyFinished(QNetworkReply* reply);
    void getArmoryUrl();
    void parse();

signals:
    void pageLoaded();
    void parsed();

private:
    QNetworkAccessManager* _manager;
    bool _isFirstLoad;
    QByteArray _data;
    ArmoryData _armoryData;
};

#endif // HTMLPARSER_H
