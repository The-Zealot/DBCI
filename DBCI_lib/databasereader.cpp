#include "databasereader.h"

DatabaseReader::DatabaseReader(QSqlDatabase *db)
{
    _db = db;

    _query = new QSqlQuery(*_db);
}

DatabaseReader::~DatabaseReader()
{
    delete _query;
}

ArmoryData DatabaseReader::read()
{
    ArmoryData data;

    if (!_db->open())
    {
        return data;
    }

    _query->exec("SELECT * FROM players");
    _query->next();

    data.setName(_query->value(DB_TABLE_PLAYER_NAME).toString());
    data.setGuild(_query->value(DB_TABLE_PLAYER_GUILD).toString());
    data.setDescription(_query->value(DB_TABLE_PLAYER_DESCRIPTION).toString());
    data.setId(_query->value(DB_TABLE_PLAYER_CHAR_ID).toInt());
    data.setRealm(_query->value(DB_TABLE_PLAYER_REALM).toInt());
    this->setClass(data, _query->value(DB_TABLE_PLAYER_CLASS).toString());
    this->setFaction(data, _query->value(DB_TABLE_PLAYER_FACTION).toString());
    this->setStatus(data, _query->value(DB_TABLE_PLAYER_STATUS).toString());
    this->setRace(data, _query->value(DB_TABLE_PLAYER_RACE).toString());

    _db->close();

    return data;
}

QVector<ArmoryData> DatabaseReader::readAll()
{
    return QVector<ArmoryData>();
}
