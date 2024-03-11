#include "armorydata.h"

ArmoryData::ArmoryData()
{

}

void ArmoryData::clear()
{
    _name   = "";
    _guild  = "";
    _id     = 0;
    _rating = 0;
    _realm  = 0;
}

const QString &ArmoryData::name() const
{
    return _name;
}

void ArmoryData::setName(const QString &newName)
{
    _name = newName;
}

const QString &ArmoryData::guild() const
{
    return _guild;
}

void ArmoryData::setGuild(const QString &newGuild)
{
    _guild = newGuild;
}

Faction ArmoryData::faction() const
{
    return _faction;
}

void ArmoryData::setFaction(Faction newFaction)
{
    _faction = newFaction;
}

Race ArmoryData::race() const
{
    return _race;
}


void ArmoryData::setRace(Race newRace)
{
    _race = newRace;
}

Status ArmoryData::status() const
{
    return _status;
}

void ArmoryData::setStatus(Status newStatus)
{
    _status = newStatus;
}

Class ArmoryData::getClass() const
{
    return _class;
}


void ArmoryData::setClass(Class newClass)
{
    _class = newClass;
}

qint32 ArmoryData::rating() const
{
    return _rating;
}

void ArmoryData::setRating(qint32 newRating)
{
    _rating = newRating;
}

qint32 ArmoryData::id() const
{
    return _id;
}

void ArmoryData::setId(qint32 newId)
{
    _id = newId;
}

qint32 ArmoryData::realm() const
{
    return _realm;
}

void ArmoryData::setRealm(qint32 newRealm)
{
    _realm = newRealm;
}

bool ArmoryData::isEmpty()
{
    return _name.isEmpty();
}

const QString &ArmoryData::description() const
{
    return _description;
}

void ArmoryData::setDescription(const QString &newDescription)
{
    _description = newDescription;
}
