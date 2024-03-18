#ifndef IREADER_H
#define IREADER_H

#include <QObject>
#include "DBCI_lib_global.h"
#include "armorydata.h"

class DBCI_LIB_EXPORT IReader
{
public:
    IReader();

    virtual ArmoryData read() = 0;
    virtual QVector<ArmoryData> readAll() = 0;
};

#endif // IREADER_H
