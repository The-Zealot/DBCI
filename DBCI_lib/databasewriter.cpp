#include "databasewriter.h"

DatabaseWriter::DatabaseWriter(QSqlDatabase* db)
{
    _db = db;
    _query = new QSqlQuery(*_db);

    init();
}

DatabaseWriter::~DatabaseWriter()
{
    if (_query != nullptr)
        delete _query;
}

bool DatabaseWriter::write(const ArmoryData &data)
{
    if(_db->open())
    {
        if(_db->transaction())
        {
            QString query = "INSERT INTO players (name, guild, faction, race, class, char_id, date, realm, description, status) "
                            "VALUES (\'%1\', \'%2\', \'%3\', \'%4\', \'%5\', %6, %7, %8, \'%9\', \'%10\');";

            query = query
                    .arg(data.name())
                    .arg(data.guild())
                    .arg(this->getFaction(data, "ru"))
                    .arg(this->getRace(data, "ru"))
                    .arg(this->getClass(data, "ru"))
                    .arg(data.id())
                    .arg(QDate::currentDate().startOfDay().currentSecsSinceEpoch())
                    .arg(data.realm())
                    .arg(data.description())
                    .arg(this->getStatus(data, "ru"));

            qDebug() << "Current query:" << query;
            qDebug() << "Query execution:" << _query->exec(query);
            qDebug() << "Current query error:" << _query->lastError().text();

            _db->commit();
        }
        else
        {
            qDebug() << _db->lastError().text();
            _db->rollback();
            return false;
        }

        _db->close();
        return true;
    }
    else
    {
        qDebug() << _db->lastError().text();
        return false;
    }
}

void DatabaseWriter::init()
{
    _db->open();
    _db->exec("CREATE TABLE IF NOT EXISTS players ("
                "id          INTEGER PRIMARY KEY,"
                "name        TEXT    NOT NULL,"
                "guild       TEXT,"
                "faction     TEXT    NOT NULL,"
                "race        TEXT    NOT NULL,"
                "class       TEXT    NOT NULL,"
                "status      TEXT    NOT NULL DEFAULT Неизвестно,"
                "realm       INTEGER NOT NULL,"
                "date        INTEGER NOT NULL,"
                "description TEXT,"
                "char_id     INTEGER NOT NULL UNIQUE,"
                "own_mark    TEXT"
              ");");

    _db->exec("CREATE TABLE IF NOT EXISTS loggs ("
                  "id      INTEGER PRIMARY KEY,"
                  "name    TEXT    NOT NULL,"
                  "guild   TEXT,"
                  "faction TEXT    NOT NULL,"
                  "race    TEXT    NOT NULL,"
                  "status  TEXT    NOT NULL,"
                  "char_id INTEGER NOT NULL,"
                  "date    INTEGER NOT NULL"
              ");");
    _db->close();
}
