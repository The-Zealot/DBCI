#include "textwriter.h"

TextWriter::TextWriter()
{

}

bool TextWriter::setFile(QString fileName)
{
    _file.setFileName(fileName);
    return _file.exists();
}


bool TextWriter::write(const ArmoryData &data)
{
    if (!_file.exists())
    {
        qDebug() << "File no exist";
        return false;
    }

    if(_file.open(QIODevice::ReadWrite))
    {
        _file.seek(_file.size());

        QString str;
        str.append(data.name() + ";");
        str.append(data.guild() + ";");
        str.append(data.faction("ru") + ";");
        str.append(data.race("ru") + ";");
        str.append(data.getClass("ru") + ";");
        str.append(QString::number(data.id()));
        str.append("\n");
        _file.write(str.toUtf8());

        _file.close();
        return true;
    }

    return false;
}
