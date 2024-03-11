#ifndef TEXTWRITER_H
#define TEXTWRITER_H

#include "iwriter.h"
#include "armoryviewer.h"
#include <QFile>
#include <QDebug>

class DBCI_LIB_EXPORT TextWriter : public IWriter, public ArmoryViewer
{
public:
    TextWriter();

    bool setFile(QString fileName);

    virtual bool write(const ArmoryData &data) override;

private:
    QFile _file;
};

#endif // TEXTWRITER_H
