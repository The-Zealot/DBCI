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

ArmoryData::Faction ArmoryData::faction() const
{
    return _faction;
}

QString ArmoryData::faction(QString lang) const
{
    switch(_faction)
    {
    case ArmoryData::None:
        return "Без фракции";
    case ArmoryData::Alliance:
        return "Альянс";
    case ArmoryData::Horde:
        return "Орда";
    default:
        return "";
    }
}

void ArmoryData::setFaction(Faction newFaction)
{
    _faction = newFaction;
}

void ArmoryData::setFaction(QString newFaction, QString lang)
{
    lang = lang.toLower();

    if (newFaction == "Орда" or newFaction == "Horde") _faction      = Faction::Horde;
    if (newFaction == "Альянс" or newFaction == "Alliance") _faction = Faction::Alliance;
}

ArmoryData::Race ArmoryData::race() const
{
    return _race;
}

QString ArmoryData::race(QString lang) const
{
    switch (_race)
    {
    case ArmoryData::Human:
        return "Человек";
    case ArmoryData::Dwarft:
        return "Дворф";
    case ArmoryData::NightElf:
        return "Ночной эльф";
    case ArmoryData::Gnome:
        return "Гноме";
    case ArmoryData::Draenei:
        return "Дреней";
    case ArmoryData::Worgen:
        return "Ворген";
    case ArmoryData::Orc:
        return "Орк";
    case ArmoryData::Undead:
        return "Нежить";
    case ArmoryData::Tauren:
        return "Таурен";
    case ArmoryData::Troll:
        return "Тролль";
    case ArmoryData::BloodElf:
        return "Эльф крови";
    case ArmoryData::Goblin:
        return "Гоблин";
    case ArmoryData::Pandaren:
        return "Пандарен";
    default:
        return "";
    }
}

void ArmoryData::setRace(Race newRace)
{
    _race = newRace;
}

void ArmoryData::setRace(QString newRace, QString lang)
{
    lang = lang.toLower();

    if (newRace == "Человек") _race     = Race::Human;
    if (newRace == "Дворф") _race       = Race::Dwarft;
    if (newRace == "Гном") _race        = Race::Gnome;
    if (newRace == "Ночной эльф") _race = Race::NightElf;
    if (newRace == "Дреней") _race      = Race::Draenei;
    if (newRace == "Ворген") _race      = Race::Worgen;
    if (newRace == "Орк") _race         = Race::Orc;
    if (newRace == "Нежить") _race      = Race::Undead;
    if (newRace == "Таурен") _race      = Race::Tauren;
    if (newRace == "Тролль") _race      = Race::Troll;
    if (newRace == "Эльф крови") _race  = Race::BloodElf;
    if (newRace == "Гоблин") _race      = Race::Goblin;
    if (newRace == "Пандарен") _race    = Race::Pandaren;
}

ArmoryData::Status ArmoryData::status() const
{
    return _status;
}

void ArmoryData::setStatus(Status newStatus)
{
    _status = newStatus;
}

ArmoryData::Class ArmoryData::getClass() const
{
    return _class;
}

QString ArmoryData::getClass(QString lang) const
{
    switch(_class)
    {
    case ArmoryData::Warrior:
        return "Воин";
    case ArmoryData::Paladin:
        return "Паладин";
    case ArmoryData::Hunter:
        return "Охотник";
    case ArmoryData::Rogue:
        return "Разбойник";
    case ArmoryData::Priest:
        return "Жрец";
    case ArmoryData::DeathKnight:
        return "Рыцарь Смерти";
    case ArmoryData::Shaman:
        return "Шаман";
    case ArmoryData::Mage:
        return "Маг";
    case ArmoryData::Warlock:
        return "Чернокнижник";
    case ArmoryData::Monk:
        return "Монах";
    case ArmoryData::Druid:
        return "Друид";
    default:
        return "";
    }
}

void ArmoryData::setClass(Class newClass)
{
    _class = newClass;
}

void ArmoryData::setClass(QString newClass, QString lang)
{
    lang = lang.toLower();

    if (newClass == "Воин") _class          = Class::Warrior;
    if (newClass == "Паладин") _class       = Class::Paladin;
    if (newClass == "Охотник") _class       = Class::Hunter;
    if (newClass == "Разбойник") _class     = Class::Rogue;
    if (newClass == "Жрец") _class          = Class::Priest;
    if (newClass == "Шаман") _class         = Class::Shaman;
    if (newClass == "Маг") _class           = Class::Mage;
    if (newClass == "Чернокнижник") _class  = Class::Warlock;
    if (newClass == "Монах") _class         = Class::Monk;
    if (newClass == "Друид") _class         = Class::Druid;
    if (newClass == "Рыцарь Смерти") _class = Class::DeathKnight;
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
