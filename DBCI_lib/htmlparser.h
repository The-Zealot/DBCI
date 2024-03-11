#ifndef HTMLPARSER_H
#define HTMLPARSER_H

#include "DBCI_lib_global.h"

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QFile>
#include <armorydata.h>
#include "htmlerror.h"

class DBCI_LIB_EXPORT HtmlParser : public QObject
{
    Q_OBJECT

public:
    HtmlParser(QObject* parent);
    ~HtmlParser();

    void loadPage(QUrl url);
    QString getTagValue(QString page, QString tag, QString closeTag = ">");

    void getCharacterData(QString name, QString realm);
    ArmoryData getArmory();

    const QString lastError() const;

public slots:
    void replyFinished(QNetworkReply* reply);
    void getArmoryUrl();
    void parse();

signals:
    void pageLoaded();
    void parsed();
    void failed();

private:
    QNetworkAccessManager* _manager;
    bool _isFirstLoad;
    QByteArray _data;
    ArmoryData _armoryData;
    HtmlError* _error;
};

#endif // HTMLPARSER_H
