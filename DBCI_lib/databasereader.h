#ifndef DATABASEREADER_H
#define DATABASEREADER_H

#include "ireader.h"
#include "armoryviewer.h"
#include "DBCI_lib_global.h"
#include "defines.h"
#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class DBCI_LIB_EXPORT DatabaseReader : public IReader, public ArmoryViewer
{
public:
    DatabaseReader(QSqlDatabase* db);
    ~DatabaseReader();

    virtual ArmoryData read() override;
    virtual QVector<ArmoryData> readAll() override;

private:
    QSqlDatabase* _db;
    QSqlQuery* _query;
};

#endif // DATABASEREADER_H
