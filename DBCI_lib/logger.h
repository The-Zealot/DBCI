#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDate>
#include "DBCI_lib_global.h"
#include "armorydata.h"
#include "armoryviewer.h"

class DBCI_LIB_EXPORT Logger
{
public:
    static bool log(QSqlDatabase &db, ArmoryData &data);
};

#endif // LOGGER_H
