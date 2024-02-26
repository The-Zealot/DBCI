#ifndef ARMORYDATA_H
#define ARMORYDATA_H

#include "DBCI_lib_global.h"
#include <QObject>

#define CLASS_COUNT         11
#define FACTION_COUNT       2
#define RACE_COUNT_ALL      13
#define RACE_COUNT_FACTION  7

class DBCI_LIB_EXPORT ArmoryData
{
public:
    enum Faction
    {
        None        = 0,
        Alliance    = 1,
        Horde       = 2,
    };

    enum Race
    {
        Human       = 1,
        Dwarft      = 2,
        NightElf    = 3,
        Gnome       = 4,
        Draenei     = 5,
        Worgen      = 6,

        Orc         = 7,
        Undead      = 8,
        Tauren      = 9,
        Troll       = 10,
        BloodElf    = 11,
        Goblin      = 12,

        Pandaren    = 0,
    };

    enum Status
    {

    };

    enum Class
    {
        Warrior     = 1,
        Paladin     = 2,
        Hunter      = 3,
        Rogue       = 4,
        Priest      = 5,
        DeathKnight = 6,
        Shaman      = 7,
        Mage        = 8,
        Warlock     = 9,
        Monk        = 10,
        Druid       = 11,
    };

    ArmoryData();

    void clear();

    const QString &name() const;
    void setName(const QString &newName);

    const QString &guild() const;
    void setGuild(const QString &newGuild);

    Faction faction() const;
    QString faction(QString lang) const;
    void setFaction(Faction newFaction);
    void setFaction(QString newFaction, QString lang = "ru");

    Race race() const;
    QString race(QString lang) const;
    void setRace(Race newRace);
    void setRace(QString newRace, QString lang = "ru");

    Status status() const;
    void setStatus(Status newStatus);

    Class getClass() const;
    QString getClass(QString lang) const;
    void setClass(Class newClass);
    void setClass(QString newClass, QString lang = "ru");

    qint32 rating() const;
    void setRating(qint32 newRating);

    qint32 id() const;
    void setId(qint32 newId);

    qint32 realm() const;
    void setRealm(qint32 newRealm);

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
};

#endif // ARMORYDATA_H
