#ifndef ARMORYDATA_H
#define ARMORYDATA_H

#include "DBCI_lib_global.h"
#include "armoryenums.h"
#include <QObject>
#include <QMap>

#define CLASS_COUNT         11
#define FACTION_COUNT       2
#define RACE_COUNT_ALL      13
#define RACE_COUNT_FACTION  7

class DBCI_LIB_EXPORT ArmoryData
{
public:
    ArmoryData();

    void clear();

    const QString &name() const;
    void setName(const QString &newName);

    const QString &guild() const;
    void setGuild(const QString &newGuild);

    Faction faction() const;
    void setFaction(Faction newFaction);

    Race race() const;
    void setRace(Race newRace);

    Status status() const;
    void setStatus(Status newStatus);

    Class getClass() const;
    void setClass(Class newClass);

    qint32 rating() const;
    void setRating(qint32 newRating);

    qint32 id() const;
    void setId(qint32 newId);

    qint32 realm() const;
    void setRealm(qint32 newRealm);

    bool isEmpty();

    const QString &description() const;
    void setDescription(const QString &newDescription);

private:
    QString _name;
    QString _guild;
    Race _race;
    Faction _faction;
    Class _class;
    Status _status;
    qint32 _rating;
    qint32 _id;
    qint32 _realm;
    QString _description;

    friend class ArmoryObject;
};

#endif // ARMORYDATA_H
