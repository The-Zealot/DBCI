#ifndef TEXTREADER_H
#define TEXTREADER_H

#include "ireader.h"
#include "DBCI_lib_global.h"

#include <QFile>

class DBCI_LIB_EXPORT TextReader : public IReader
{
public:
    TextReader();

    bool setFile(const QString &fileName);

    virtual ArmoryData read() override;

private:
    QFile _file;
};

#endif // TEXTREADER_H
