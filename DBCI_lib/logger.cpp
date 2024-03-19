#include "logger.h"

bool Logger::log(QSqlDatabase &db, ArmoryData &data)
{
    if (db.open())
    {
        ArmoryViewer av;
        QString query = "INSERT INTO loggs (name, guild, faction, race, class, status, date, char_id) VALUES (%1, %2, %3, %4, %5, %6, %7, %8)";
        query = query
                .arg(data.name())
                .arg(data.guild())
                .arg(av.getFaction(data, "ru"))
                .arg(av.getRace(data, "ru"))
                .arg(av.getClass(data, "ru"))
                .arg(av.getStatus(data, "ru"))
                .arg(QDate::currentDate().startOfDay().currentSecsSinceEpoch())
                .arg(data.id());
        db.exec(query);

        db.close();

        return true;
    }
    else
    {
        qDebug() << db.lastError().text();
        return false;
    }
}
