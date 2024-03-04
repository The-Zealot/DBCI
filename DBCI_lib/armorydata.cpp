#include "armorydata.h"

ArmoryData::ArmoryData()
{
    constInit();
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
    lang = lang.toLower();

    if (_races.contains({_class, lang}))
    {
        return _races[{_class, lang}];
    }
    else
    {
        return "";
    }
}

void ArmoryData::setRace(Race newRace)
{
    _race = newRace;
}

void ArmoryData::setRace(QString newRace, QString lang)
{
    lang    = lang.toLower();
    newRace = newRace.toLower();

    if (newRace == "человек") _race     = Race::Human;
    if (newRace == "дворф") _race       = Race::Dwarft;
    if (newRace == "гном") _race        = Race::Gnome;
    if (newRace == "ночной эльф") _race = Race::NightElf;
    if (newRace == "дреней") _race      = Race::Draenei;
    if (newRace == "ворген") _race      = Race::Worgen;
    if (newRace == "орк") _race         = Race::Orc;
    if (newRace == "нежить") _race      = Race::Undead;
    if (newRace == "таурен") _race      = Race::Tauren;
    if (newRace == "тролль") _race      = Race::Troll;
    if (newRace == "эльф крови") _race  = Race::BloodElf;
    if (newRace == "гоблин") _race      = Race::Goblin;
    if (newRace == "пандарен") _race    = Race::Pandaren;
}

ArmoryData::Status ArmoryData::status() const
{
    return _status;
}

QString ArmoryData::status(QString lang) const
{
    lang = lang.toLower();

    return _statuses[{_status, lang}];
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
    lang = lang.toLower();

    if (_classes.contains({_class, lang}))
    {
        return _classes[{_class, lang}];
    }
    else
    {
        return "";
    }
}

void ArmoryData::setClass(Class newClass)
{
    _class = newClass;
}

void ArmoryData::setClass(QString newClass, QString lang)
{
    lang        = lang.toLower();
    newClass    = newClass.toLower();

    if (newClass == "воин") _class          = Class::Warrior;
    if (newClass == "паладин") _class       = Class::Paladin;
    if (newClass == "охотник") _class       = Class::Hunter;
    if (newClass == "разбойник") _class     = Class::Rogue;
    if (newClass == "жрец") _class          = Class::Priest;
    if (newClass == "шаман") _class         = Class::Shaman;
    if (newClass == "маг") _class           = Class::Mage;
    if (newClass == "чернокнижник") _class  = Class::Warlock;
    if (newClass == "монах") _class         = Class::Monk;
    if (newClass == "друид") _class         = Class::Druid;
    if (newClass == "рыцарь смерти") _class = Class::DeathKnight;
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

QString ArmoryData::stringRealm() const
{
    switch (_realm)
    {
        case 3: return "FUN";
        case 5: return "x5";
        case 10: return "x100";
        default: return "";
    }
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

void ArmoryData::constInit()
{
    _statuses[{Status::Unknown, "ru"}]      = "Неизвестно";
    _statuses[{Status::Humiliated, "ru"}]   = "Опущен";
    _statuses[{Status::Terminated, "ru"}]   = "Ликвидирован";
    _statuses[{Status::Amnestied, "ru"}]    = "Амнистирован";
    _statuses[{Status::Sold, "ru"}]         = "Продан";

    _classes[{Class::Warrior, "ru"}]        = "Воин";
    _classes[{Class::Paladin, "ru"}]        = "Паладин";
    _classes[{Class::Hunter, "ru"}]         = "Охотник";
    _classes[{Class::Rogue, "ru"}]          = "Разбойник";
    _classes[{Class::Priest, "ru"}]         = "Жрец";
    _classes[{Class::DeathKnight, "ru"}]    = "Рыцарь Смерти";
    _classes[{Class::Shaman, "ru"}]         = "Шаман";
    _classes[{Class::Mage, "ru"}]           = "Маг";
    _classes[{Class::Warlock, "ru"}]        = "Чернокнижник";
    _classes[{Class::Monk, "ru"}]           = "Монах";
    _classes[{Class::Druid, "ru"}]          = "Друид";

    _races[{Race::Human, "ru"}]             = "Человек";
    _races[{Race::Dwarft, "ru"}]            = "Дворф";
    _races[{Race::NightElf, "ru"}]          = "Ночной эльф";
    _races[{Race::Gnome, "ru"}]             = "Гном";
    _races[{Race::Draenei, "ru"}]           = "Дреней";
    _races[{Race::Worgen, "ru"}]            = "Ворген";
    _races[{Race::Orc, "ru"}]               = "Орк";
    _races[{Race::Undead, "ru"}]            = "Нежить";
    _races[{Race::Tauren, "ru"}]            = "Таурен";
    _races[{Race::Troll, "ru"}]             = "Тролль";
    _races[{Race::BloodElf, "ru"}]          = "Эльф крови";
    _races[{Race::Goblin, "ru"}]            = "Гоблин";
    _races[{Race::Pandaren, "ru"}]          = "Пандарен";
}
