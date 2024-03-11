#include "textreader.h"

TextReader::TextReader()
{

}

bool TextReader::setFile(const QString &fileName)
{
    _file.setFileName(fileName);
    return _file.exists();
}

ArmoryData TextReader::read()
{
    ArmoryData result;

    if (!_file.exists())
    {
        return result;
    }

    if (_file.open(QIODevice::ReadOnly))
    {
        QString line = _file.readLine();
        QStringList sList = line.split(";");
        result.setName(sList.at(0));
        result.setGuild(sList.at(1));
        this->setFaction(result, sList.at(2));
        this->setRace(result, sList.at(3));
        this->setClass(result, sList.at(4));
        result.setId(sList.at(5).toInt());

        _file.close();
    }

    return result;
}
