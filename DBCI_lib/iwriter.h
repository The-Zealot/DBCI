#ifndef IWRITER_H
#define IWRITER_H

#include <QObject>
#include "DBCI_lib_global.h"
#include "armorydata.h"

class DBCI_LIB_EXPORT IWriter
{
public:
    IWriter();

    virtual bool write(const ArmoryData &data) = 0;
};

#endif // IWRITER_H
