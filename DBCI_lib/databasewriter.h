#ifndef DATABASEWRITER_H
#define DATABASEWRITER_H

#include "iwriter.h"
#include "DBCI_lib_global.h"
#include <QDate>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class DBCI_LIB_EXPORT DatabaseWriter : public IWriter
{
public:
    DatabaseWriter(QSqlDatabase* db);
    ~DatabaseWriter();

    virtual bool write(const ArmoryData &data) override;

private:
    void init();

private:
    QSqlDatabase* _db;
    QSqlQuery* _query;
};

#endif // DATABASEWRITER_H
