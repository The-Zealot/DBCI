#ifndef HTMLERROR_H
#define HTMLERROR_H

#define HTML_ERROR_NO_ERROR     0
#define HTML_ERROR_EMPTY_DATA   1

#include <QObject>
#include <QDebug>
#include "DBCI_lib_global.h"

class DBCI_LIB_EXPORT HtmlError
{
public:
    static HtmlError* getError();

    const QString toString() const;

    void setCurrentErrorCode(int newCurrentErrorCode);

private:
    HtmlError();
    void init();
    int _currentErrorCode;
    QVector<QString> _errors;
    static HtmlError* _htmlError;
};


#endif // HTMLERROR_H
